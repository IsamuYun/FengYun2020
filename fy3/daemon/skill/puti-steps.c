//TIE@FY3
inherit SKILL;
string *dodge_msg = ({
	"$nһ�С����᱾�������������ɵر��˿�ȥ��\n",
	"ֻ��$n��Ӱһ�Σ�һʽ���龵���̨�����ѱ����߳�֮�⡣\n",
	"$nʹ����������һ����������ɵ�������\n",
	"$n����һ�㣬һ�С��δ��ǳ������ڿն��𣬱��˿�ȥ��\n",
	"����$nʹһ�С�����Ϫˮ������������Ʈ�˿�ȥ��\n",
	"$n��Ӱ΢�����Ѿ���һ�С����ϱ��������������\n",
	"����$nһ�С���ʱ�����С�ʹ���������Ƶ�$N���ᣡ\n",
        "����$n����Ʈ��������һ�ݣ�һ�С�˵�����ա����ܿ���һ����\n",
        "$n��������һ�Σ�һ�С�շת���ɲ¡���һ��ת����������֮�⡣\n",

});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취��������ղ�����\n");

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
		return notify_fail("�����������������������������ղ�����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
int effective_level() { return 10;}

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
        return CLASS_D("shaolin") + "/puti-steps/" + action;
}

