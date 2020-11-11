// save-me sheet.c

#include <ansi.h>
#define MAX_GUARD 4

inherit SHEET;

void create()
{
    set_name(YEL "����ٻ���" NOR, ({ "save-me sheet", "sheet"}) );
    set_weight(5);
    set("unit", "��");
    set("value", 0);
    setup();
}

int burn_function()
{ 
    object soldier, me;
    int    spells;

    me = this_player();
    if( !me->is_fighting() )
        return notify_fail("û����Ҫɱ�㣡\n");
    if( me->query_temp("max_guard") > MAX_GUARD )
        return notify_fail("���Ѿ��ٻ�̫����������ˣ�\n");
    message_vision( 
        "$N���о��񣬼�����ζ�������һ��" + name() + "����������\n"
        , me);
    me->receive_damage("sen", 20);
    if( random(me->query("mana")) < 200 ) {
        message("vision", "����ʲ��Ҳû�з�����\n", environment(me));
        return 1;
    }
    spells = me->query_skill("scratching");
    seteuid(getuid());
    if( random(10) < 5 )
        soldier = new("/obj/npc/heaven_soldier");
    else
        soldier = new("/obj/npc/hell_guard");
    soldier->move(environment(me));
    soldier->invocation(me, spells);
    soldier->set("possessed", me);
    me->add_temp("max_guard",1);
    me->remove_all_killer();
    message_vision(HIB "\n$N����$n�ı��󺰵�������ɱ��\n" NOR, me, soldier );
    message_vision(HIB "\n$n��$N��ס�����е��˵Ĺ�����\n" NOR, me, soldier );
    destruct(this_object());
    return 1;
}
