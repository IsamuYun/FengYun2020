// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg,type;
	int extra,extra2;
	int lev;
	int dam1;
	int dam2;
	int dam3;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("moon-dance",1);
	if ( extra < 30) return notify_fail("你的水月神舞还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［月神十舞］只能对战斗中的对手使用。\n");

    weapon = me->query_temp("weapon");
    if (!weapon) 
        type = "unarmed";
    else
        type = weapon->query("skill_type");

    if ( type!="whip" || (string) me->query_skill_mapped(type) != "moon-dance")
        return notify_fail("你目前使用的外功不是水月神舞！\n");

    if ( (string) me->query_skill_mapped("force") != "moon-dance")
        return notify_fail("你目前使用的内功不是水月神舞！\n");

	me->add_temp("apply/attack",extra*5);
	me->add_temp("apply/damage",extra*10);

	msg = HIR  "$N仰天发出一声长笑，使出水月神舞中的［月神十舞］\n\n" NOR;
	msg += HIG   "就似浩瀚无比的水月苍穹近在眼前，顿时间天地亦为之变色！\n" NOR;
	message_vision(msg,me,target);
    
    lev = extra/30;
    extra2 = me->query_skill("moon-dance");
    dam1 = (int) me->query("max_force");
    dam2 = (int) me->query("max_mana");
    dam3 = (int) me->query("max_atman");

	me->add("str",3*extra);
    
    if(lev > 0)
    {
        msg =  HIC  "\n月神一舞惊天变\n" NOR;
		message_vision(msg,me,target);
        if(1*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIW "$N大惊失色，变化不及！\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)/10+extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)/10+extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)/10+extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");

    }
    
    if(lev > 1)
    {
        msg = HIY  "\n 月神二舞仙魔乱\n" NOR;
        message_vision(msg,me,target);
        if(2*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIG "$N逃不出千重诡异幻境，招式混乱！\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)/8+2*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)/8+2*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)/8+2*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
    }
    
    if(lev > 2)
    {
    	target->start_busy(3);
        msg = HIW  "\n  月神三舞鬼神泣\n" NOR;
        message_vision(msg,me,target);
        if(3*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIC "$N似乎听到周围都是鬼哭神嚎，心神剧烈颤动！\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)/6+3*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)/6+3*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)/6+3*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
    }
    
    if(lev > 3)
    {
        msg = HIR  "\n   月神四舞翻江海\n" NOR;
        message_vision(msg,me,target);
        if(4*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIC "$N直感气血翻腾，及于呕吐！\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)/4+4*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)/4+4*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)/4+4*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
    }
    
    if(lev > 4)
    {
        msg = HIB  "\n    月神五舞日月暗\n" NOR;
        message_vision(msg,me,target);
        if(5*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIY "$N顿感日月无光，天昏地暗，似乎生命也已走到尽头！\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)/2+5*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)/2+5*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)/2+5*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
  	}

    if(lev > 5)
    {
        msg =  HIC  "\n     月神六舞换天地\n" NOR;
        message_vision(msg,me,target);
        if(6*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIW "生死轮回，改天换地, $N顿感寸步难行！\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)+6*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)+6*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)+6*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
    }

    if(lev > 6)
    {
    	target->add_temp("is_unconcious",1);
        msg = HIY  "\n      月神七舞血漫天\n" NOR;
        message_vision(msg,me,target);
        if(7*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIR "$N杀气暴涨，血色漫天！\n" NOR,me);
			message_vision( HIR "$N心惊胆寒，肝胆俱裂！\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)*2+7*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)*2+7*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)*2+7*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
    }

    if(lev > 7)
    {
        msg = HIW  "\n       月神八舞入神道\n" NOR;
        message_vision(msg,me,target);
        if(8*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIC "$N神态忽转，天道渺渺！\n" NOR,me);
			message_vision( HIG "$N战意全消，意识渐弱！\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)*3+8*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)*3+8*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)*3+8*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
    }

    if(lev > 8)
    {
        msg = HIB  "\n        月神九舞混沌归\n" NOR;
        message_vision(msg,me,target);
        if(9*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIY "$N混沌归元，气破九重天！\n" NOR,me);
			message_vision( HIG "$N精神趋无，已无力再战！\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)*4+9*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)*4+9*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)*4+9*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
  	}

    if(lev > 9)
    {
        msg = HIR  "\n         月神十舞苍穹开\n" NOR;
        message_vision(msg,me,target);
        if(10*(int)me->query("combat_exp") >= random((int)target->query("combat_exp")))
        {
			message_vision( HIW "$N仰天长啸，浩瀚苍穹，为我所用, 呼风唤雨，水月神舞！\n" NOR,me);
			message_vision( HIG "$N精气神受到严重的损伤，濒临死亡！\n" NOR,target);
			target->receive_damage("sen",(dam1+dam2+dam3)*5+10*extra2,me);
			target->receive_damage("kee",(dam1+dam2+dam3)*5+10*extra2,me);
			target->receive_damage("gin",(dam1+dam2+dam3)*5+10*extra2,me);
		}

		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
    }
  	
  	me->add("str",-3*extra);
  	
  	if(lev > 6)
  	{
		target->add_temp("is_unconcious",-1);
  	}
  	
  	if(lev > 5)
  	{
  		lev = 5;	
  	}
  	
  	lev = lev - (me->query_skill("incarnation",1)+me->query_skill("literate",1))/300;
  	if(lev < 1)
  	{
  		lev = 1;	
  	}
  	
  	me->start_busy(lev);
  	
    me->add_temp("apply/attack",-extra*5);
    me->add_temp("apply/damage",-extra*10);
	return 1;
}
