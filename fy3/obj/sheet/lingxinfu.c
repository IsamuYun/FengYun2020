// yiru@hero 2000.8.5

// ���ķ�

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "���ķ�" NOR, ({ "ling-xin sheet", "sheet"}) );
    set_weight(5);
    set("unit", "��");
    set("value", 0);
    set("level", 5);
    setup();
}

int attach_function(object ob)
{
    object me = this_player();
    int bonus;

    bonus = me->query("atman_factor");
    if( bonus < 1 ){
        write("����ʹ�� enchant ����ָ����������������\n");
        return 1;
    }
    if( me->query("atman")<me->query("atman_factor") ){
        write("������������ˣ�\n");
        return 1;
    }
    me->add("atman", -me->query("atman_factor") );

    if( me ==ob )
        message_vision("\n$N���Լ���������һ��"+name()+"��\n",me);
    else
        message_vision("\n$N��$n��������һ��"+name()+"��\n",me,ob);

    bonus += query("level");
        if(ob->query("family/family_name")!="��ɽ����")
        {
                bonus = bonus/10;
        }

    // �ⶨ��
    ob->delete_temp("no_move");
    // ����ѣ
    if( ob->query_temp("is_unconcious") )
    {
        ob->revive();
    }
    // �����
    if( ob->query("bellicosity") > bonus )
    {
        ob->add("bellicosity", -bonus);
    }
    else
    {
        ob->set("bellicosity", 0);
    }
    
    // �����
    if( environment(ob)->query("magic_protect") ) 
    {
        environment(ob)->delete("magic_protect");
        environment(ob)->delete("no_magic");
        message_vision(HIY"\n��Χ��ħ�����Ʊ�����ˣ�\n"NOR,me);
    }

    me->start_busy(1);

    destruct(this_object());

    return 1;
}

