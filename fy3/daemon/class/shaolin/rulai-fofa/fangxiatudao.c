// xgchen@zzfy
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, myexp, hisexp;
	object weapon;
        if(me->query("family/family_name") != "少林寺")
		return notify_fail("你不是少林弟子不能使用放下屠刀！！\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("rulai-fofa",1) ;
	if ( extra < 70) return notify_fail("你的如来佛法还不够纯熟！\n");
		

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［放下屠刀］只能对战斗中的对手使用。\n");
	weapon = target->query_temp("weapon");
	myexp = (int)me->query("combat_exp");
	hisexp= (int)target->query("combat_exp");
	if(random(hisexp) < myexp * 2 && weapon)	
	{
	message_vision(
HIM "\n\n$N闭目低声诵起如来佛法............."HIY"\n\n\t［放下屠刀］\n"HIM"\n$n手中的兵刃"HIY+ 
weapon->name()+ HIM "脱手而飞！\n\n" NOR, me,target);
	if( weapon->unequip()) weapon->move(environment(target));
	}
	else
	{
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
	msg = HIY+ "\n\n$N对$n诵起如来佛法"HIY"----放下屠刀，我佛慈悲----\n\n"HIC"一股无形气劲击向$n的$l！\n"+ NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);
	msg = HIY+ "\n\n$N对$n诵起如来佛法"HIY"----不放屠刀，我佛不赦----\n\n"HIC"一股无形气劲击向$n的$l！\n"+ NOR;
	COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);
      me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
	me->start_busy(5);
	}
	return 1;
}
