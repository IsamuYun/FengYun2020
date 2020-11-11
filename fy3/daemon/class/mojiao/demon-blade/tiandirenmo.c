// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg,forceskill;
	int extra,lv,hit,extra2;
	object weapon;
	lv = me->query("tiandirenmo");
	if (!lv)
		me->set("tiandirenmo",1);
	lv = me->query("tiandirenmo");
	hit = me->query_skill("literate",1);
	extra = me->query_skill("demon-blade",1);
	if ( extra < 150) return notify_fail("你的［天地人魔连环八式］还不够纯熟！\n");
	dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "demon-steps")
			return notify_fail("［天地人魔］需要如意人魔连环八步的配和！\n");
	forceskill = (string) me->query_skill_mapped("force");
	if ( forceskill != "demon-force")
			return notify_fail("［天地人魔］需要天地人魔心法的配和！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［天地人魔］只能对战斗中的对手使用。\n");
    if( (int)me->query("force") < 100*lv )    
		return  notify_fail("你的内力不够。\n");
	weapon = me->query_temp("weapon");
	extra2 = hit*lv/3;
	extra = (extra + lv* 100)/3;
	msg = HIY  "$N神气贯通，将天地人魔连环八式一气呵成！\n万魔初醒！" NOR;
	me->add_temp("apply/attack",extra2*3);
	me->add_temp("apply/damage",extra*3);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "魔焰万丈！" NOR;
		me->add_temp("apply/attack",-extra2);
		me->add_temp("apply/damage",-extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "魔光乍现！" NOR;
		me->add_temp("apply/attack",-extra2);
		me->add_temp("apply/damage",-extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "天魔独尊！" NOR;
		me->add_temp("apply/attack",-extra2);
		me->add_temp("apply/damage",-extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "万刃天魔！" NOR;
		me->add_temp("apply/attack",-extra2);
		me->add_temp("apply/damage",-extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "天魔回天！" NOR;
		me->add_temp("apply/attack",-extra2);
		me->add_temp("apply/damage",-extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "天魔七现！" NOR;
		me->add_temp("apply/attack",-extra2);
		me->add_temp("apply/damage",-extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "万魔归宗！" NOR;
		me->add_temp("apply/attack",-extra2);
		me->add_temp("apply/damage",-extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		me->add_temp("apply/attack",extra2*4);
		me->add_temp("apply/damage",extra*4);
		me->add("force",-100*lv);
	me->start_busy(5);
	if(me->query("tiandirenmo") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("tiandirenmo_exp",1);
	      tell_object(me, "你的【天地人魔】获得了一点技能熟练度。\n"NOR);
		}
	  if((me->query("tiandirenmo_exp") > (me->query("tiandirenmo")*me->query("tiandirenmo")*100))&&(me->query("tiandirenmo")< MAX_PFMLEVEL))
		{
		me->add("tiandirenmo",1);
		me->set("tiandirenmo_exp",0);

	      tell_object(me, HIW"你的【天地人魔】等级上升了。\n"NOR);
		}
	return 1;
}
int help(object me)
{
        write(YEL"\n如意地魔连环八刀之天地人魔："NOR"\n");
	write(@HELP

      魔教独闯的武功绝学，一招八式，一气呵成，起手招式凶猛，收招略微薄弱。
	
	  如意地魔连环八刀等级每提升三级，提升物理攻击一点。
      读书识字等级每提升三级，提升物理命中一点。
      天地人魔等级每提升一级，增加此招的物理命中和伤害。
     

HELP
	);
	return 1;
}

