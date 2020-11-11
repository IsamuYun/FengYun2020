#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) return 
	notify_fail("你只能提升自己的力量。\n");

        if( (int)me->query("force") < 100 )     return 
	notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("strengthup") ) return 
	notify_fail("你已经在运功中了。\n");
        skill = me->query_skill("lanhua-force");
	if(skill < 20) return notify_fail("你的兰花心法太差了！\n");
        me->add("force", -100);
        message_vision(
                HIR 
"$N暗暗地聚气凝神，整个人处于一触即发的状态！\n" NOR, me);
        me->add_temp("apply/strength", skill/2);
        me->set_temp("strengthup", 20);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/20 :), skill/2);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/strength", - amount);
        me->delete_temp("strengthup");
        tell_object(me, "你的兰花心法运行完毕，整个人又松懈了下来。\n");
}
 
