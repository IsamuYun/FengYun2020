//卧龙太玄醉  written by tiandi
inherit SKILL;
#include <ansi.h>
#include <combat.h>
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}
string status_msg(int ratio)
{
        if( ratio==100 ) return HIG "看起来精神饱满，正处于巅峰状态。" NOR;
        if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
        if( ratio > 90 ) return HIY "看起来可能有些不济。" NOR;
        if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
        if( ratio > 60 ) return HIY "气喘嘘嘘，脸色惨白。" NOR;
        if( ratio > 40 ) return HIR "似乎十分疲惫，看来需要好好休息了。" NOR;
        if( ratio > 30 ) return HIR "已经一副头重脚轻的模样，正在勉力支撑著不倒下去。" NOR;
        if( ratio > 20 ) return HIR "看起来已经力不从心了。" NOR;
        if( ratio > 10 ) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
        return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}

string *dodge_msg = ({
	"$n一招「卧虎藏龙」摇摇晃晃地避了开去。\n",
	"只见$n身影飘忽，略显酒醉之状，一式「梦龙欲醉」早已避在数尺之外。\n",
	"$n使出「点睛」，轻轻往$N身上一点，不觉间已经闪过$N的招式。\n",
	"$n左足一点，一招「隆中对」腾空而起，跌跌撞撞地避过了$N一击。\n",
	"$n身影微动，已经藉一招「豁到足游」将自己的身形硬是挪了半分。\n",
	 "但是$n脚踏八卦步，出入生门，一招"+HIM"「扭转乾坤」"+NOR"，转守为攻向$N袭去！\n",
        "$n身形往上一拔，一个转折再一个转折，早已将$N避退到数丈之外。\n",
	 "$n左跨一步，右跨一步，一时间身影似乎变成了三个，把$N晃得眼花缭乱。\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query_skill("move",1) < 150 || (int)me->query_skill("dodge",1)<150)
		return notify_fail("你的基础不够，没有办法练"+HIC"卧"+HIY"龙"+HIR"太"+HIW"玄"+HIB"醉。\n"NOR);
	  if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		return notify_fail("以你目前的状况，还没有资格练"+HIC"卧"+HIY"龙"+HIR"太"+HIW"玄"+HIB"醉。\n"NOR);

	return 1;
}

string query_dodge_msg(string limb)
{
	object me=this_player();
	object target = offensive_target(me);
	int i;
//        object weapon = target->query_temp("weapon");
	int lv = target->query_skill("long-steps",1);
	int force=target->query("eff_force");
	int damage=random(force)+100;
	string msg;
	i=random(sizeof(dodge_msg));
	if(i!=5)   return dodge_msg[i];
        if (lv >130)  { 
		msg=dodge_msg[5];
		msg+="$n似醉似醒，仿佛喝醉了一般，动作缓慢了下来。不料$n醉步中突然暴喝一声，身形由慢转快，迅速向$N发起了攻击！\n";
		msg+="$N始未料到$n还藏有这一杀招，匆忙中来不及变招应付，被$n扎扎实实地击中要害。\n";
		me->receive_wound("kee",damage);
             	msg+= "( $N"+status_msg((int)me->query("eff_kee")*100/(int)me->query("max_kee"))+")\n";
		return msg;
						}
	return dodge_msg[4];
}
int practice_skill(object me)
{
	if( (int)me->query_skill("move",1) < 250 || (int)me->query_skill("dodge",1)<250)
		return notify_fail("你的基础不够，没有办法练"+HIC"卧"+HIY"龙"+HIR"太"+HIW"玄"+HIB"醉。\n"NOR);

	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练"+HIC"卧"+HIY"龙"+HIR"太"+HIW"玄"+HIB"醉。\n"NOR);
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
int effective_level() { return 25;}

int learn_bonus()
{
	return -20;
}
int practice_bonus()
{
	return 20;
}
int black_white_ness()
{
	return 100;
}

string perform_action_file(string action)
{
        return CLASS_D("zhuge") + "/long-steps/" + action;
}
