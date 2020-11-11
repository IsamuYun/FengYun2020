// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,kee;
	int orforce,hit,damage,lv;
	object weapon;
	lv = (int)me->query("kaitianpidi");
	if (!lv)
		me->set("kaitianpidi",1);
	lv = (int)me->query("kaitianpidi");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
    extra = me->query_skill("pangu-hammer",1);
    hit = me->query_skill("literate",1);
    damage = me->query_skill("str");
    if ( extra < 30) return notify_fail("你的盘古九式还不够三十级！\n");
    if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［开天辟地］只能对战斗中的对手使用。\n");
	kee = 0;
	orforce = (int) me->query("force");
	if (orforce < lv*30)
		return notify_fail("你的内力不足。\n");
    me->add_temp("apply/attack",extra/2 + lv*100);
    me->add_temp("apply/damage",extra/2 + lv*100);
	weapon = me->query_temp("weapon");
	me->add("force", -lv*30);
	msg = HIY  "$N举起手中的"+weapon->name()+HIY"对空划着一个圆圈,在$N的不停舞动中,周围的风都聚拢在了一起.\n$N对着$n大喝一声:开！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    me->add_temp("apply/attack",- extra/2 - lv*100);
    me->add_temp("apply/damage",- extra/2 - lv*100);
	kee =1;
	if (extra > 59 && random(extra*lv)>40 && kee==1)
	{
		orforce = (int) me->query("force");
		if (orforce < lv*60)
			return notify_fail("你的内力不足使用第二招。\n");
	me->add_temp("apply/attack",extra + lv*150);
    me->add_temp("apply/damage",extra + lv*150);
	weapon = me->query_temp("weapon");
	me->add("force", -lv*60);
	msg = HIB  "$N移到$n右侧,"+weapon->name()+HIB"不再停歇,往$n身上就是一撩,欲给$n来个措手不及.\n天！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    me->add_temp("apply/attack",- extra - lv*150 );
    me->add_temp("apply/damage",- extra - lv*150);
	kee =2;
	}
	if (extra > 89 && random(extra*lv)>55 && kee==2)
	{
		orforce = (int) me->query("force");
		if (orforce < lv*90)
			return notify_fail("你的内力不足使用第三招。\n");
	me->add_temp("apply/attack",extra*2 + lv*200);
    me->add_temp("apply/damage",extra*2 + lv*200);
	weapon = me->query_temp("weapon");
	me->add("force", -lv*90);
	msg = HIC  "$N骤然一跃而起,盘踞而下,"+weapon->name()+HIC"犹如神助凝聚着青色的光芒,大鹏展翅般扑向$n.\n辟！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    me->add_temp("apply/attack",- extra*2 - lv*200);
    me->add_temp("apply/damage",- extra*2 - lv*200);
	kee =3;
	}
	if (extra > 119 && random(extra*lv)>70 && kee==3)
	{
		orforce = (int) me->query("force");
		if (orforce < lv*120)
			return notify_fail("你的内力不足使用第四招。\n");
	me->add_temp("apply/attack",extra*3 + lv*300);
    me->add_temp("apply/damage",extra*3 + lv*300);
	weapon = me->query_temp("weapon");
	me->add("force", -lv*120);
	msg = HIW  "$N浑然而立,手中"+weapon->name()+HIW"舞得狂风大作,令$n无法辨别出$N下一步的动作.就在此刻,$N的最后一招终于使了出来.\n地！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    me->add_temp("apply/attack",- extra*3 - lv*300);
    me->add_temp("apply/damage",- extra*3 - lv*300);
	kee = 4;
	}
	if(me->query("kaitianpidi") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("kaitianpidi_exp",1);
	      tell_object(me, "你的【开天辟地】获得了一点技能熟练度。\n"NOR);
		}
	  if((me->query("kaitianpidi_exp") > (me->query("kaitianpidi")*me->query("kaitianpidi")*100))&&(me->query("kaitianpidi")< MAX_PFMLEVEL))
		{
		me->add("kaitianpidi",1);
		me->set("kaitianpidi_exp",0);

	      tell_object(me, HIW"你的【开天辟地】等级上升了。\n"NOR);
		}
	me->start_busy(kee+1);
	return 1;
}
int help(object me)
{
	int extra,lv;
	extra = me->query_skill("pangu-hammer",1);
	lv = me->query("kaitianpidi");
        write(YEL"\n盘古九式之开天辟地："NOR"\n");
	write(@HELP

      天锤山庄的终极杀招，虽是四式,但也需要上下贯通才能使得完整。
HELP
	);
	write("\t当前状态：物理命中伤害加成第一招"+(int)(extra/2+100*lv)+"点,第二招"+(int)(extra+150*lv)+"点,第三招"+(int)(extra*2+200*lv)+"点,第四招"+(int)(extra*3+300*lv)+"点.\n\n.");
	
	write(@HELP
	  盘古九式等级每上升一级,增加此招命中物理伤害.
      开天辟地等级每上升一级，提升后一招式的出招率。

HELP
	);
	return 1;
}
