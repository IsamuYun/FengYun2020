//by xgchen@fy

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
        int myexp,yourexp,lvl,fo;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［降龙无悔］只能对战斗中的对手使用。\n");
     if( (int)me->query("force") < 20 )     return
        notify_fail("你的内力不够。\n");
	weapon = me->query_temp("weapon");
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
        fo = (int) target->query_skill("force")+1;
        lvl = (int) target->query_skill("yiqiguanforce")+1;
	msg = HIR "$N将［降龙十八掌］的十八式溶汇贯通，幻出十八个掌影一连击向$n的十八处要害！" NOR;
	if(random(yourexp) < myexp)
	{
	if( random(2))
	{
		message_vision(msg + "\n", me, target);
		msg = "结果$n被$N攻了个手忙脚乱！\n";
		message_vision(msg, me, target);
		target->start_busy(3);
	}
	else
	{
                        me->add_temp("apply/attack", lvl*fo*fo);
                        me->add_temp("apply/damage",lvl*fo);
		        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
			me->start_busy(2);
                        me->add_temp("apply/attack", -lvl*fo*fo);
                        me->add_temp("apply/damage",-lvl*fo);
	}
	}
	else
	{
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->start_busy(2);
	}
    me->add("force", -20);
	return 1;
}
int help(object me)
{
        write(YEL"\n降龙十八掌之降龙无悔："NOR"\n");
	write(@HELP

       降龙十八掌亦为乌鲁汉所创，原名为“野狗十八咬”。洪七公将其去糙
       存精，并且改名为“降龙十八掌”。此掌法后经丐帮历代帮主研究发展，
       不仅是一等一的刚猛，而且攻守兼备。这招降龙无悔就是将十八掌融为
       一掌，从空中由上而下，双手一起击下。不仅可攻击，而且可以扰敌。

       要求：	
               (学）无；
               （用）内力 20 以上；

HELP
	);
	return 1;
}
