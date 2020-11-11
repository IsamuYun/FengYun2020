// save-me sheet.c

#include <ansi.h>
#define MAX_GUARD 4

inherit SHEET;

void create()
{
    set_name(YEL "天兵召唤符" NOR, ({ "save-me sheet", "sheet"}) );
    set_weight(5);
    set("unit", "张");
    set("value", 0);
    setup();
}

int burn_function()
{ 
    object soldier, me;
    int    spells;

    me = this_player();
    if( !me->is_fighting() )
        return notify_fail("没有人要杀你！\n");
    if( me->query_temp("max_guard") > MAX_GUARD )
        return notify_fail("你已经召唤太多天兵鬼卒了！\n");
    message_vision( 
        "$N集中精神，祭起三味真火，唿的一声" + name() + "着了起来！\n"
        , me);
    me->receive_damage("sen", 20);
    if( random(me->query("mana")) < 200 ) {
        message("vision", "但是什麽也没有发生。\n", environment(me));
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
    message_vision(HIB "\n$N躲在$n的背后喊道：给我杀！\n" NOR, me, soldier );
    message_vision(HIB "\n$n替$N挡住了所有敌人的攻击！\n" NOR, me, soldier );
    destruct(this_object());
    return 1;
}
