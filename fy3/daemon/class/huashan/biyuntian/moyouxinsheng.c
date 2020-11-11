// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int lev;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("biyuntian",1);
	if ( extra < 50) return notify_fail("你的碧云天还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［魔由心生］只能对战斗中的对手使用。\n");
	me->add_temp("apply/attack",extra*2);
	me->add_temp("apply/damage",extra*2);

	weapon = me->query_temp("weapon");
	msg = HIR  "$N双手合拢，忽又分开，眼中血光愈加浓烈，死气弥漫，笼罩天地！\n$n顿感四周迷迷朦朦，没有白天，没有黑夜！\n" NOR;
	message_vision(msg,me,target);
	msg = HIW   "却是$N已然使出碧云天中的［魔由心生］！\n" NOR;
	message_vision(msg,me,target);
    
    lev = extra/50;
    
    if(lev > 0)
    {
        msg =  HIM  "冷  血  涔  涔" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIB  "凄  风  雨" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    }
    
    if(lev > 1)
    {
        msg =  HIM  "暗  夜  阴  魂" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIB  "怨  鬼  咒" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    }
    
    if(lev > 2)
    {
        msg =  HIM  "妖  魔  尽  舞" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIB  "生  死  劫" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    }
    
    if(lev > 3)
    {
        msg =  HIC  "魔  由  心  生" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIC  "碧  云  天" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    }
  	  	
    me->add_temp("apply/attack",-extra*2);
    me->add_temp("apply/damage",-extra*2);

  	if(lev > 4)
  	{
  		lev = 4;	
  	}
  	
  	if(lev < 2)
  	{
  		lev = 2;	
  	}
  	
  	me->start_busy(lev);

	return 1;
}
