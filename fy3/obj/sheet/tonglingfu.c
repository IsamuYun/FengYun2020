// yiru@hero 2000.8.6

// ͨ�`��

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "ͨ�`��" NOR, ({ "tong-ling sheet", "sheet"}) );
    set_weight(5);
    set("unit", "��");
    set("level", 5);
    set("value", 0);
    setup();
}

int burn_function()
{
    object ob, me = this_player();
    int lvl, bonus;

    ob = me;
    bonus = me->query("atman_factor");

        if( me->query_temp("apply/astral_vision") )
        {
                write("���Ѿ�����ͨ��������ˡ�\n");
                return 1;
        }
        
    if( bonus < 1 ){
        write("����ʹ�� enchant ����ָ����������������\n");
        return 1;
    }
    if( me->query("atman")<me->query("atman_factor") ){
        write("������������ˣ�\n");
        return 1;
    }
    me->add("atman", -me->query("atman_factor") );

    message_vision("$N����һ��$n��$n��������������\n",me,this_object());

    // ֻ�б��������շ����бȽϺõ�Ч����
    bonus += query("level");
        if(me->query("family/family_name")!="��ɽ����")
        {
                bonus = bonus/10;
        }

    ob->add_temp("apply/astral_vision", 1);
    ob->start_call_out( (: call_other, __FILE__, "do_back", ob, this_object() :), bonus/3);

    // ��call_out�ĺ�����δִ�У�����destruct
    set("no_get",1);
    move(VOID_OB);

    return 1;
}
 
void do_back(object ob, object sheet)
{
    tell_object(ob,"���"+name()+"ʧЧ�ˡ�\n");
    ob->add_temp("apply/astral_vision", -1);
    destruct(sheet);
}

