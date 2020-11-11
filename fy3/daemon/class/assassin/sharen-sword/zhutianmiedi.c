// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp;
	object weapon;
	extra = me->query_skill("sharen-sword",1);
	if ( extra < 80) return notify_fail("你的［杀人剑法］还不够纯熟！\n");
	dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "jinhong-steps")
			return notify_fail("［诛天灭地］需要［金虹步法］的配和！\n");
	tmp = me->query_skill("jinhong-steps",1);
	if ( tmp < 80 )return notify_fail("你的［金虹步法］还不够纯熟！\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［诛天灭地］只能对战斗中的对手使用。\n");
	me->add_temp("apply/attack",tmp);
	me->add_temp("apply/damage",extra);
	weapon = me->query_temp("weapon");
	msg = HIW  "\n\n$N双目赤红，突然变换身行，使出杀人剑法中的禁手［诛天灭地］,手中的$w划出条条剑气，狂风暴雨般的向$n砍来 ！！\n\n\n诛天！\n$N手中$w宛如吃人的猛兽，劈头盖脸的由上至下砍向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "$N发出的剑气被一层迷茫的血雾弥漫着,$n只觉得四肢发凉..." NOR;
	if(random((int)me->query("combat_exp")) >= (int)target->query("combat_exp"))
	{
	message_vision(msg+"\n",me,target);
	message_vision( HIR "$N被这一招结结实实地砍中！鲜血从一条可怕的伤口喷出！！！\n" NOR,target);
	target->receive_wound("kee",extra);
	me->receive_heal("kee",extra);
	}	
	else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N见势不好，狼狈的跳了开去...\n" NOR,target);
	}
        msg = HIW  "灭地！\n$N手中$w带着丝丝杀气,猛然由左至右向$n砍来！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "$N发出的剑气被一层迷茫的血雾弥漫着,$n只觉得四肢发凉..." NOR;
	if(random((int)me->query("combat_exp")) >= (int)target->query("combat_exp"))
	{
	message_vision(msg+"\n",me,target);
	message_vision( HIR "$N被这一招结结实实地砍中！鲜血从一条可怕的伤口喷出！！！\n" NOR,target);
	target->receive_wound("kee",extra);
	me->receive_heal("kee",extra);
	}	
	else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N见势不好，轻巧的跳了开去...\n" NOR,target);
	}
        msg = HIW  "无情！\n$N手中$w对准$n一阵乱砍！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "$N发出的剑气被一层迷茫的血雾弥漫着,$n只觉得四肢发凉..." NOR;
	if(random((int)me->query("combat_exp")) >= (int)target->query("combat_exp"))
	{
	message_vision(msg+"\n",me,target);
	message_vision( HIR "$N被这一招结结实实地砍中！鲜血从一条可怕的伤口喷出！！！\n" NOR,target);
	target->receive_wound("kee",extra);
	me->receive_heal("kee",extra);
	}	
	else{
        message_vision(msg,me,target);
        message_vision( HIB "\n$N见势不好，飞身跃了开去...\n" NOR,target);
	}
      me->start_busy(2);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
	return 1;
}
