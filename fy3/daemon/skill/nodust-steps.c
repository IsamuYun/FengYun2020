// notracesnow.c

inherit SKILL;

string *dodge_msg = ({
        "$nһ�С�������翡��������ɵر��˿�ȥ��\n",
        "ֻ��$n��Ӱһ�Σ�һʽ������ֱ�ϡ����ѱ����߳�֮�⡣\n",
        "$nʹ������շɶɡ����������ɵ�������\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 150 )
                return notify_fail("�������������û�а취���޳�������\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
   return notify_fail("�޳�����ֻ��ͨ����ʦ��ѧϰ��������\n");
}
int effective_level() { return 10;}

int learn_bonus()
{
	return 20;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 20;
}
string perform_action_file(string action)
{
        return CLASS_D("tianchui") + "/nodust-steps/" + action;
}
string belong()
{
	return "tianchui";
}

