// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$nͻȻ���ŵ��˼�ת������԰������Ӱ������һ�м�Ϊ�����ġ��������롹��\n",
	"ֻ��$nһ�С���շɶɡ���������һ�³��п켫������������á�\n",
	"$nһʽ�����ӻ�ʱ�����͵�̤��һ����������ת�����ж����ڿմ���\n",
	"$n��ͷ΢����������ӣ�һʽ������ӭ�͡�������߿��⡣\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취����ɽ����\n");

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
		return notify_fail("���������������������������ɽ����\n");
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

