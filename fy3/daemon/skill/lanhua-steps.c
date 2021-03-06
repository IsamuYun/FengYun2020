// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$n一招「彩蝶飞舞」轻轻巧巧地避了开去。\n",
	"只见$n身影一晃，一式「蜻蜓点水」早已避在七尺之外。\n",
	"$n使出「倒转天权」，轻轻松松地闪过。\n",
	"$n左足一点，一招「宿鸟惊飞」腾空而起，避了开去。\n",
	"可是$n使一招「微风抚叶」，身子轻轻飘了开去。\n",
	"$n身影微动，已经藉一招「沾露茶花」轻轻闪过。\n",
	"但是$n一招「峰回路转」使出，早已绕到$N身後！\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练段氏步法。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 0
	||      (int)me->query("force") < 0 )
		return notify_fail("你的气或内力不够，不能练段氏步法。\n");
	me->receive_damage("kee", 0);
// me->add("force",1);
	return 1;
}
int effective_level() { return 22;}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

string perform_action_file(string action)
{
	return CLASS_D("yihua") + "/lanhua-steps/" + action;
}

