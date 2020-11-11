// invocation.c
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
    object soldier;
    int     spells, cost;

    cost=150-me->query_spi();
    if(cost<60) cost=60;

    spells = me->query_skill("imperialsword",1);
    if(spells < 60 )
            return notify_fail("你的御剑术不够高！\n");

    if( me->query("class")!="xianren" )
            return notify_fail("你不是仙人，无法召唤剑神。\n");

    if( !me->is_fighting() )
            return notify_fail("只有战斗中才能召唤剑神！\n");

    if( (int)me->query("atman") < cost )
            return notify_fail("你的灵力不够了！\n");

    if( (int)me->query("gin") < cost )
            return notify_fail("你的精神无法集中！\n");
    if( me->query_temp("have_guard"))
            return notify_fail("你已经召唤剑神了！\n");

    message_vision("$N将手中"+me->query_temp("weapon")->query("name")+
                   "一挥，\n", me);

    me->add("atman", -cost);
    me->receive_damage("gin", cost-30);

    seteuid(getuid());

    soldier = new("/obj/npc/sword_god");

    soldier->move(environment(me));
    soldier->invocation(me,
        me->query_skill("incarnation") + (me->query_spi() - 18) * 3);
    soldier->set("possessed", me);

    if ( me->query_skill("imperialsword", 1) <= 90 )
        soldier->set_temp("no_increase", 1);

    me->set_temp("have_guard", 1);
    return 1;
}
