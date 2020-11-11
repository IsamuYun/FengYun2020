//TIE@FY3
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	
		"action":		"$N使一招「无量气海」，身形暴长，手中$w一摆，向$n的$l刺去",
		"dodge":		40,
		"force":		150,
		"damage_type":	"刺伤"
	]),
	([	
		"action":		"$N身形拔地而起，手中$w舞动，满天剑气森森，一招「无量迭起」罩向$n的$l",
		"dodge":		-60,
		"force":		180,
		"damage_type":	"刺伤"
	]),
	([	
		"action":		"$N手中$w光芒闪闪，一招「千漩百转」，瞬间已向$n的$l连攻数剑",
		"dodge":		-40,
		"damage":		190,
		"damage_type":	"刺伤"
	]),
	([	
		"action":		"$N手中$w一圈，带起满天沙尘，突然剑身一颤，化出无数剑尖，一招「海量汪涵」往$n$l刺去",
		"dodge":		-40,
		"damage":		140,
		"damage_type":	"刺伤"
	]),
	([	
		"action":		"$N$w闪动，幻出满天剑影，团团簇簇，一招「海网撒天」笼住$n的$l",
		"dodge":		60,
		"damage":		220,
		"damage_type":	"刺伤"
	]),
	([	
		"action":		"$N身形跃起，手中$w挽出朵朵剑花，一招「狂涛无量」裹住$n的全身",
		"dodge":		-60,
		"damage":		250,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N手中$w幻出满天剑光，一招「无量飞身」，身行如飞，无声无息地转到$n的背后，猛刺$n的$l",
                "damage":               190,
                "dodge" :               200,
                "parry" :               100,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N的$w走弧形，一招「无量封影」，封住$n的退路，剑尖直刺$n的$l",
		"damage":		130,
                "dodge" :               200,
                "parry" :               100,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N一招「无量风电」，$w挂风，自上而下，电闪般刺向$n的$l",
		"damage":		150,
                "dodge" :               200,
                "parry" :               100,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query_skill("foreknowledge", 1) < 100)
	{
		return notify_fail("你对占卜学的理解不够，没有办法学无量剑法。\n");
	}
	
	if( (int)me->query("max_force") < 150 )
		return notify_fail("你的内力不够，没有办法练无量剑法。\n");
	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry" || usage=="dodge";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 50
	||	(int)me->query("force") < 15 )
		return notify_fail("你的内力或气不够，没有办法练习无量剑法。\n");
	me->receive_damage("kee", 50);
	me->add("force", -15);
	write("你按著所学练了一遍无量剑法。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
        return CLASS_D("huashan") + "/wuliang-sword/" + action;
}

int effective_level() { return 21;}

string *parry_msg = ({
        "$n运剑如飞，顿时就将$N的$w挡在了身外。\n",
        "$n内力贯注剑尖，$N只觉手中一震，$w几欲飞出。\n",
        "$n手中$v圆转，内力激荡，一招「无量山河」，强劲的剑气逼得$N连联后退。\n",
});

string *unarmed_parry_msg = ({
        "$n运剑如飞，顿时就将$N的$w挡在了身外。\n",
        "$n内力贯注剑尖，$N只觉手中一震，$w几欲飞出。\n",
        "$n手中$v圆转，内力激荡，一招「无量山河」，强劲的剑气逼得$N连联后退。\n",
        "$n的剑势毫无破绽，令$N只觉得无处下手。\n",
        "$n剑势奇妙，竟似有种奇异的力量，带偏了$N的招式。 \n",
        "$n剑出如飞，逼得$N连连后退。\n",        
});

string *dodge_msg = ({
                "$n身形飘忽不定，无影无量，令$N难以把握。\n",
                "$n竟倒纵开去，令$N一时无法追击。\n",
                "$n静立不动，等$N攻到身前时却略一移位，就使$N落了个空。\n",
                "$n右足一点，全身腾空，立时躲开了$N志在必得的这一击。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int learn_bonus()
{
	return -150;
}
int practice_bonus()
{
	return -150;
}
int black_white_ness()
{
	return 30;
}

