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
	lv = (int)me->query("shixuepofeng");
	if (!lv)
		me->set("shixuepofeng",1);
	lv = (int)me->query("shixuepofeng");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
    extra = me->query_skill("pofeng-strike",1);
    hit = me->query_skill("literate",1);
    damage = me->query_skill("str");
         if ( extra < 30) return notify_fail("你的泼风掌还不够三十级！\n");
         if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［嗜血泼风］只能对战斗中的对手使用。\n");
	orforce = (int) me->query("force");
	if (orforce < lv*50)
		return notify_fail("你的内力不足。\n");
	kee = me->query("kee");
	if (kee < lv*10)
		return notify_fail("你的气血太低.使用此招会有危险.\n");
	me->add("kee",- kee/10);
    me->add_temp("apply/attack",hit*3+extra+lv*100);
    me->add_temp("apply/damage",4*(damage+extra+lv*130));
	weapon = me->query_temp("weapon");
	me->add("force", lv*50);
	msg = HIR  "$N双掌呈鲜红色，只见血液从指间缓缓流出,双眼散发出野兽版的厉芒,看上去已经失去了理智.\n接着弹指间,$N移动到了$n身前,右手带着一股血腥味击向$n！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(2);
            me->add_temp("apply/attack",- hit*3-extra-lv*100);
            me->add_temp("apply/damage",-4*(damage +extra+ lv*130));
	if(me->query("shixuepofeng") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("shixuepofeng_exp",1);
	      tell_object(me, "你的【嗜血泼风】获得了一点技能熟练度。\n"NOR);
		}
	  if((me->query("shixuepofeng_exp") > (me->query("shixuepofeng")*me->query("shixuepofeng")*100))&&(me->query("shixuepofeng")< MAX_PFMLEVEL))
		{
		me->add("shixuepofeng",1);
		me->set("shixuepofeng_exp",0);

	      tell_object(me, HIW"你的【嗜血泼风】等级上升了。\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n泼风掌之嗜血泼风："NOR"\n");
	write(@HELP

      此招使用后，消耗自身十分之一的气血,攻击敌方,爆发力极强的杀招。
HELP
	);
	write("\t当前状态：物理命中加成"+(int)(me->query_skill("literate")*3+me->query_skill("pofeng-strike",1)+me->query("shixuepofeng")*100)+"点,物理伤害加成"+2*(int)(me->query_skill("pofeng-strike",1)+me->query("str")+me->query("shixuepofeng")*130)+"点\n\n.");
	
	write(@HELP
      读书识字技能等级每上升一级，增加此招命中三点。
      人物力量属性每上升一级，增加此招伤害两点。
	  泼风掌等级每上升一级,增加此招命中一点,物理伤害两点.
      嗜血泼风等级每上升一级，增加此招命中一百点,物理伤害五百二十点。

HELP
	);
	return 1;
}
