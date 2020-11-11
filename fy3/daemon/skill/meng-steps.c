
inherit SKILL;

string *dodge_msg = ({
	"$n���ζ��ر��Ʈ����������$N�޷����塣\n",
	"$n˫�ŵ�أ�ȫ����Ϊһ����Ӱ����������$N���˼�ת��\n",
	"$n��һ����磬�滺��������$N���������ơ�\n",
	"$n������ͥ�Ų����ڵ�ָ����Ȼ�˳����⡣\n",
	"����$n��һת����һ�ƣ���Ӱ����ʧ������\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge"||usage=="move") ;
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 100 )
		return notify_fail("�������������û�а취�����β���\n");

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
		return notify_fail("��������������������������β�����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
int effective_level() { return 19;}

int learn_bonus()
{
	return -90;
}
int practice_bonus()
{
	return -50;
}
int black_white_ness()
{
	return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("bat") + "/meng-steps/" + action;
}
