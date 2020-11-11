// by king
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        if( target != me ) return 
	notify_fail("你只能将［时照功］用在自己的身上。\n");
        if( (int)me->query("force") < 200 )     return
        notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("shizhao") ) return 
	notify_fail("你已经在施展［时照功］了。\n");
	skill = me->query_skill("four-force",1);
        if(skill < 140) return notify_fail("你的四照神功还不够火候！\n");
	skill =skill*3;
	me->add("force", -200);
        message_vision( HIC
"$N施展出四照神功——时照功，内力充斥全身，坚如寒冰。\n" NOR, me);
        me->add_temp("apply/iron-cloth", skill);
        me->set_temp("shizhao", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill :), skill/5);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/iron-cloth", - amount);
        me->delete_temp("shizhao");
        tell_object(me, "你的［时照功］的功效散光了。\n");
}
 
