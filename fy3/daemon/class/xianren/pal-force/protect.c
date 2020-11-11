// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) 
        	return notify_fail("你只能将［真元护体］用在自己的身上。\n");

        skill = me->query_skill("incarnation");

        if( (int)me->query("force") < skill )     return 
notify_fail("你的内力不够。\n");
        if( (int)target->query_temp("spi_protect") ) return 
notify_fail("你已经在运功中了。\n");


        me->add("force", -skill);

        message_vision(
                HIW 
                "$N微一凝神，运起真元护体，防御力突然提高！\n" NOR, me);

        target->add_temp("apply/armor", skill/3);
       target->add_temp("apply/iron-cloth", skill/3);
        target->set_temp("spi_protect", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", target, 
skill/3 :), me->query_spi());

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
        me->add_temp("apply/iron-cloth", - amount);
        me->delete_temp("spi_protect");
        tell_object(me, HIY "你的真元护体失效了。\n" NOR);
}
