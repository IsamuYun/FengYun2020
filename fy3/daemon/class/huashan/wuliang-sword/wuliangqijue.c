// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int lev;
	int fr;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("无量七绝只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	if (!weapon) return notify_fail("无量七绝只能和无量剑法配和！\n");
	if( (string)weapon->query("skill_type") != "sword" )
	return notify_fail("无量七绝只能和无量剑法配和！\n");
	if ( (string) me->query_skill_mapped("sword") != "wuliang-sword")
	return notify_fail("无量七绝只能和无量剑法配和！\n");
	
	extra = me->query_skill("wuliang-sword",1);
	if ( extra < 100) return notify_fail("你的［无量剑法］还不够纯熟！\n");
	
	fr = me->query_skill("foreknowledge", 1);

	me->add_temp("apply/attack", extra+fr/10);
	me->add_temp("apply/damage", extra+fr/10);

	msg = HIW  "$N低喧一声'无量寿佛'，奋起全身之力挥出无量剑法中惊天动地的一式－－－无－量－七－绝－\n\n" NOR;

	message_vision(msg,me);

        msg = HIY  "狂龙无量！\n$N心神合一，剑气自手中$w呼啸而出，狂奔$n的$l！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg = HIW  "大海无量！\n$N手中$w剑光爆闪，犹如汪洋大海般罩向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg = HIG  "山石无量！\n$N手中$w似重逾千斤，猛然撞向$n的$l！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg = HIM  "般若无量！\n$N纵身跃起，手中$w化做般若流云，忽刺$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg = HIC  "道心无量！\n$N暴喝一声，手中$w圈转，剑光道心浑然一体，旋向$n的$l！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg = HIB  "真言无量！\n$N身行一长，手中$w大开大合，方圆丈许布满剑气，将$n团团围住！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg = HIR  "众生无量！\n$N手中$w加紧，瞬间化为一片电光，从四面八方击向$n！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	if(extra > 210)
	{
        msg =  HIW  "\n七绝合一，乾坤无量！天地乾坤，无形无量。\n$N的剑势忽然慢了，很慢。一剑挥出，不着边际，不成章法。\n" NOR;
        if(random((fr/100)*(int)me->query("combat_exp")) >= random((int)target->query("combat_exp")))
        {
			message_vision(msg+"\n",me,target);
			message_vision( HIY "只见这笨拙而迟钝的一剑慢慢的刺过来忽然化作了满天的花雨。\n$N无从躲避，心惊胆寒！\n" NOR,target);
			target->receive_damage("kee",extra*fr/100);
			target->receive_damage("sen",extra+fr);
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
		}
		else
		{
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		}		
	}

	if(extra > 240)
	{
        msg =  HIG  "\n无量乾坤，生死无量！$N剑尖忽然起了奇异的震动。剑尖本来是斜斜指向$n，震动一起，万物忽然间全都静止。\n就连周围的空气，都彷佛也已停顿。\n" NOR;
		if(random((fr/50)*(int)me->query("combat_exp")) >= random((int)target->query("combat_exp")))
		{
			message_vision(msg+"\n",me,target);
			message_vision( HIY "流水乾枯，变化穷尽，生命终结，万物灭亡。\n$N只觉全身一阵虚脱，似乎所有的生命力都消失了！\n" NOR, target);
			target->receive_damage("gin",extra*fr/50);
			target->receive_damage("kee",extra*fr/50);
			target->receive_damage("sen",extra*fr/50);
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
		}
		else
		{
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		}
	}

	me->add_temp("apply/attack", -(extra+fr/10));
	me->add_temp("apply/damage", -(extra+fr/10));

  	lev = 4 - fr/200;
  	if(lev < 2)
  	{
  		lev = 2;	
  	}
	me->start_busy(lev);

	return 1;
}
