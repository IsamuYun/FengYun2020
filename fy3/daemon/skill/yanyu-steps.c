
inherit SKILL;

string *dodge_msg = ({
	"$nһ�С�������졹�������ɵر��˿�ȥ��\n",
        "$n��������һ�Σ�һ�С�������ɡ���һ��ת����������֮�⡣\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge") ;
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취�����㲽��\n");

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
		return notify_fail("�������������������������貽����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
int effective_level() { return 19;}

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
        return CLASS_D("yihua") + "/yanyu-steps/" + action;
}
