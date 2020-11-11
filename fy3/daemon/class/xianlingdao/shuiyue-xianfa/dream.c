// yiru@hero
// dream.c
// 回魂仙梦

#include <ansi.h>

inherit SSERVER;
int conjure(object me, object target)
{
        int lvl,i;
        object env, *inv;
        lvl = (int) me->query_skill("magic");
        lvl += (int) me->query("spi");
    if ( lvl < 300)
        return notify_fail("你的水月仙法不够熟练！\n");
        if( me->query("atman") < 100 )
                return notify_fail("你的灵力不够！\n");
    if( me->query("gin") <= 30 )
        return notify_fail("你的精不够！\n");
    if(me->query_temp("in_dreaming"))
        return notify_fail("你正在施展［回魂仙梦］！\n");
    if( me->is_fighting() )
        return notify_fail("战斗中不可以施展［回魂仙梦］！\n");
        me->add("atman", -100);
        me->receive_damage("gin", 30);
        message_vision(HIW "$N凝神提气，顿时只觉一阵天旋地转。。。\n" NOR, me);
        me->set_temp("in_dreaming", 1);
    me->remove_all_killer();
    tell_object(me,"你感觉周遭的事物似乎有了变化。\n");
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), lvl);
    return 1;

}

void remove_effect(object me)
{
    me->delete_temp("in_dreaming");
        message_vision(HIW "一阵天旋地转之后，$N又回到了。。。\n" NOR, me);
    me->move(environment(me));
    me->remove_all_killer();
}
