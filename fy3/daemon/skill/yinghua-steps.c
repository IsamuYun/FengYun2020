// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$n����һת���͵�����һ��,�����$N�Ĺ��ơ�\n",
	"$nȫ��Ϊһ����Ӱ������һ���շ��������Ʈ���ұߡ�\n",
	"$n������һֻ��ӥ������һ����$N����ǰ�ɹ���\n",
	"$n����һ����ʸ������ٿ�İεض�����$N�������ӡ�\n",
	"$n���İεض����ڰ����һת�����䵽����Զ�ĵط���\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취�����ɲ�����\n");

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
		return notify_fail("����������������������������ɲ�����\n");
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

