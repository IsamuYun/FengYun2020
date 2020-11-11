// yiru@hero 2000.8.5

// ��λ��

inherit SHEET;

#include <ansi.h>

void create()
{
    set_name(YEL "���" NOR, ({ "sky-vault sheet", "sheet"}) );
    set_weight(5);
    set("unit", "��");
    set("value", 0);
    set("level", 5);
    setup();
}

int burn_function()
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

    lvl = query("level");

    if ( random(bonus + lvl) > lvl )
    {
        me->start_busy(1);
    }else{
        me->start_busy(2);
    }

    if( (int)me->query_temp("vault")>0 ) return 1;
    message_vision("$N����һ��$n��$n��������������\n",me,this_object());

    me->add_temp("apply/courage", 10);
    me->add_temp("apply/attack", bonus/2);
    me->add_temp("apply/damage", lvl);
    me->add_temp("vault",1);
    me->start_call_out( (: call_other, __FILE__, "do_back", me, bonus,
            this_object() :), bonus/2);

    // ��call_out�ĺ�����δִ�У�����destruct
    set("no_get",1);
    move(VOID_OB);

    return 1;
}
 
void do_back(object ob, int bonus, object sheet)
{
    tell_object(ob,"���"+name()+"ʧЧ�ˡ�\n");
    ob->add_temp("apply/damage", -sheet->query("level"));
    ob->add_temp("apply/attack", -bonus/2);
    ob->add_temp("apply/courage", -10);
    ob->add_temp("vault",-1);
    destruct(sheet);
}
