// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$n身行一转，猛的跳向一旁,躲过了$N的攻势。\n",
	"$n全身化为一道白影，忽的一个空翻，从左边飘到右边。\n",
	"$n身体如一只苍鹰，呼的一声从$N的眼前飞过。\n",
	"$n宛若一条矫矢苍龙，倏的拔地而起，令$N不敢仰视。\n",
	"$n忽的拔地而起，在半空中一转，已落到几丈远的地方。\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练飞仙步法。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练倒飞仙步法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
int effective_level() { return 25;}

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
        return CLASS_D("swordsman") + "/feixian-steps/" + action;
}

