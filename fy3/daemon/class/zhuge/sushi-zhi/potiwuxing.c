// 破体无形
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg,msgg;
	int extra,orforce;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("sushi-zhi",1);
	if ( extra < 150) return notify_fail("你的俗世指还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［"HIR"破"HIW"体"HIB"无"HIY"形"NOR"］只能对战斗中的对手使用。\n");
				orforce = (int) me->query("force");

	if (target->query_skill_mapped("iron-cloth"))
	{
	me->add_temp("apply/attack",extra*4);
	me->add_temp("apply/damage",extra*8);
	me->add("force_factor",1000);
			
	} else 
	{
	me->add_temp("apply/attack",extra/20);
	me->add_temp("apply/damage",extra/20);
	}
	msgg = "\n$n试着用硬功对抗$N的［"HIR"破"HIW"体"HIB"无"HIY"形"NOR"］，结果由于武功相克，$n的硬功根本无从施展！";
	weapon = me->query_temp("weapon");
	msg = HIY  "\n$N踏浪虚步，左手微斜，如凤舞之式，避实就虚，“嗤嗤嗤”发出三道暗劲。\n";
	msg +="右手伏卧成形，现龙状，“啵啵”两声，两道阴柔的指风射向$n！\n";
	msg +=HIG"$n不禁失声叫道："NOR;
	          message_vision(msg,me,target);
       msg =  HIC  "\n     	 -------  破 ☆ 体 ☆ 无 ☆ 形  -------\n" NOR;
	if (target->query_skill_mapped("iron-cloth"))
	msg += msgg;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIR  "\n ◇花年虚度尽百岁◇\n" NOR;
       if (target->query_skill_mapped("iron-cloth"))
	msg += msgg;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIW  "\n            ◇青山依旧始方唯◇\n" NOR;
       if (target->query_skill_mapped("iron-cloth"))
	msg += msgg;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "\n                       ◇淡竹春风拂玉柳◇\n" NOR;
       if (target->query_skill_mapped("iron-cloth"))
	msg += msgg;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC "\n                                    ◇嫣然一笑暮黄昏◇\n" NOR;
       if (target->query_skill_mapped("iron-cloth"))
	msg += msgg;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
  	me->start_busy(3);	
	if (target->query_skill_mapped("iron-cloth"))
	{
	me->add_temp("apply/attack",-extra*4);
	me->add_temp("apply/damage",-extra*8);
	} else 
	{
	me->add_temp("apply/attack",-extra/20);
	me->add_temp("apply/damage",-extra/20);
	}
	me->set("force_factor",0);
	me->set("force", orforce);
return 1;
}
