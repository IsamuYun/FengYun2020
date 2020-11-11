// yiru@hero 2000.8.5
// sheet.c

#include <dbase.h>
#include <move.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;

// ������ /obj/sheet Ŀ¼�£���Ϊ���ܹ���ȷ�������� euid �� uid
// /obj/ Ŀ¼�µ������ euid ���䴴���ߵ��û� euid ��ͬ��
// ������ŵ������� /d/testcave/obj ֮���Ŀ¼�У� euid �Ͳ�������
// ��Ϊ����������Ҫ euid ���û� euid ��ͬ�����Ա���ע��������⡣

void setup()
{
        seteuid(getuid());
    set("long", "����һ��" + name() +"��\n");
}

int unequip()
{
        set("equipped", 0);
        return 1;
}

void init()
{
    // һ������ͨ�ķ�����ô������������
    add_action("do_burn", "burn");
    add_action("do_write", "write");
    add_action("do_attach", "attach");
}

int burn_function();
int attach_function(object ob);
int write_function(object ob);

int do_burn(string target)
{
    object ob, me;
    me = this_player();

    if( !target ){
        // �������ʽ����ȷʱ�������ǽ�������ת����������������Ҫ���� 1 
        write("ָ���ʽ��burn <��>\n");
        return 1;
    }

    // �ж��Ƿ����ָ��Ҫ�յķ���
    if( !(ob = present(target, me
)) ){
        // �����ǽ�������ת����������������Ҫ���� 1 
        write("������û��"+target+"��\n");
        return 1;
    }

    if( me->is_busy() ){
        write("���ϸ�������δ��ɣ������շ���\n");
        return 1;
    }

    // �ж��Ƿ��Ǳ�������յ� burn ָ���һ��������Ҫ��
    // �����ж��ŷ���ʱ��Ӧ�����ഫ�� burn ָ������Ҫ���� 0��
    if( ob != this_object() ) {
        return 0;
    }


    if( environment(me)->query("no_magic") ){
        write("���ﲻ���շ���\n");
        return 1;
    }

    me->start_busy(1);

    // ��ʵ֤�������ƺ�ȷʵ���Է��� 1
    return burn_function();
}
 
int do_attach(string arg)
{
    string target;
    object ob, me = this_player();

    if( !arg ){
        // �������ʽ����ȷʱ�������ǽ�������ת����������������Ҫ���� 1 
        write("ָ���ʽ��attach <��> to <Ŀ��>\n");
        return 1;
    }

    if( me->is_busy() ){
        write("���ϸ�������δ��ɣ�����ʩ����\n");
        return 1;
    }

    if( sscanf(arg,"%s to %s",arg,target)!=2 ){
        write("ָ���ʽ��attach <��> to <Ŀ��>\n");
        return 1;
    }

    // �ж��Ƿ����ָ��Ҫ���ķ���
    if( !(ob = present(arg, me)) ){
        // �����ǽ�������ת����������������Ҫ���� 1 
        write("������û��"+arg+"��\n");
        return 1;
    }

    // �ж��Ƿ��Ǳ�������յ� attach ָ���һ��������Ҫ��
    // �����ж��ŷ���ʱ��Ӧ�����ഫ�� attach ָ�
    if( ob!=this_object() ) 
        return 0;

    // ��Ȼob==this_object() ��ob�Ϳ���Ų�������ˡ�

    // �ж��Ƿ����ָ��Ҫ����Ŀ�ꡣ
    if( !(ob = present(target, environment(me))) ){
        // �����ǽ�������ת����������������Ҫ���� 1 
        write("����û��"+target+"��\n");
        return 1;
    }

    me->start_busy(1);

    return attach_function(ob);
}

int do_write(string arg)
{
    string target;
    object ob, me = this_player();

    if( !arg ){
        // �������ʽ����ȷʱ�������ǽ�������ת����������������Ҫ���� 1 
        write("ָ���ʽ��write <Ŀ��> on <��>\n");
        return 1;
    }

    if( me->is_busy() ){
        write("���ϸ�������δ��ɣ�����д�֡�\n");
        return 1;
    }

    if( sscanf(arg,"%s on %s",target,arg)!=2 ){
        write("ָ���ʽ��write <Ŀ��> on <��>\n");
        return 1;
    }

    // �ж��Ƿ����ָ��Ҫ���ķ���
    if( !(ob = present(arg, me)) ){
        // �����ǽ�������ת����������������Ҫ���� 1 
        write("������û��"+arg+"��\n");
        return 1;
    }

    // �ж��Ƿ��Ǳ�������յ� attach ָ���һ��������Ҫ��
    // �����ж��ŷ���ʱ��Ӧ�����ഫ�� attach ָ�
    if( ob!=this_object() ) 
        return 0;

    // ��Ȼob==this_object() ��ob�Ϳ���Ų�������ˡ�

    // �ж��Ƿ����ָ��Ҫ����Ŀ�ꡣ
    ob = present(target, environment(me));
    if(!ob) ob = find_player(target);
    if(!ob) ob = find_living(target);

    delete("targetname");
    if(!ob){
        set("targetname", target);
        message_vision("$N��" + target + "д��$n�ϡ�\n", me, this_object());
        set("long",
            "����һ��" + name() + "������д�š�" + target + "������С�֡�\n");
    }else{
        set("targetname", ob);
        message_vision("$N��" + ob->name() + "д��$n�ϡ�\n", me, this_object());
        set("long",
            "����һ��" + name() + "������д�š�" + ob->name() + "����\n");
    }

    me->start_busy(1);

    if(ob) write_function(ob);

    return 1;
}

int burn_function()
{
    message_vision( "$N�յ���һ��"+name()+"��\n", this_player());
    destruct(this_object());
    return 1;
}
int write_function(object ob)
{
    return 1;
}
int attach_function(object ob)
{   
    message_vision( "$N�ó�һ��"+name()+"��$nһ����\n", this_player(),ob);
    destruct(this_object());
    return 1;
}

