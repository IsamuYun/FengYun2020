// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$n突然绕着敌人急转，丈许方园尽是人影，正是一招极为高明的「苍龙盘岭」。\n",
	"只见$n一招「凌空飞渡」闪过，这一下出招快极，抑且如梦如幻。\n",
	"$n一式「燕子回时」，猛的踏上一步，身向左转，敌招都落在空处。\n",
	"$n肩头微缩，身向后掠，一式「苍松迎客」避在五尺开外。\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练华山身法。\n");

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
		return notify_fail("你的气或内力不够，不能练倒华山身法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
int effective_level() { return 11;}

int learn_bonus()
{
	return -20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("bat") + "/huashan-steps/" + action;
}

