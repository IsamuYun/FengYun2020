// yiru@hero 2000.8.5

// �����

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "�����" NOR, ({ "revival sheet", "sheet"}) );
    set_weight(5);
    set("unit", "��");
    set("value", 0);
    set("level", 5);
    setup();
}

int attach_function(object ob)
{
    object me = this_player();
    int lvl, bonus;

    bonus = me->query("mana_factor");
    if( bonus < 1 ){
        write("����ʹ�� encurse ����ָ����������������\n");
        return 1;
    }
    if( me->query("mana")<me->query("mana_factor") ){
        write("��ķ��������ˣ�\n");
        return 1;
    }
    me->add("mana", -me->query("mana_factor") );

    bonus = bonus + query("level");

    message_vision("\n$N��$n��������һ��"+name()+"��\n", me, ob);
    if ( random(bonus) > ob->query("level") )
    {
        ob->revive();
    }else{
        tell_object(me, "\n����ʲôҲû�з�����Ҳ���Ƿ���������\n");
        me->start_busy(3);
    }

    destruct(this_object());
    return 1;
}
