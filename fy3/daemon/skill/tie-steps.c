
// tie-steps.c
//written by kouga

inherit SKILL;

string *dodge_msg = ({
        "����$n����Ʈ����һ�С������ơ��εض��𣬾�������ıܿ���һ����\n",
        "$n������ת��һʽ�������ơ���ȫ����������Ӱ�ӳ����⡣\n",
        "$n��������һ�Σ�һ�С������ơ����ڿն��𣬱��˿�ȥ��\n",
        "$n���۵��һ�С������ơ������μ������㿪$N������һ����\n",
        "$n��������һ�Σ�һ�С���ɽ�ơ���������֮�⡣\n",
        "$n���λζ���һ�С������ơ���ȫ����������Ӱ�ӳ����⡣\n",
        "$n��������������������һ����һ�С������ơ������μ��ٺ��ˡ�\n",
        "$nʹ��������ơ�����������ض㿪��$N��һ�С�\n",
        "$n��Ӱ΢�����Ѿ���һ�С������ơ�����������\n",
        "$n�ڿ�һԾ��˫����ǰһ�ߣ�һ�С������ơ����㿪���ߡ�\n",
        "ֻ��$n��Ӱһ�Σ�һʽ����Ծ�ơ����ѱ����߳�֮�⡣\n",
        "����$nʹһ�С�ӥ���ơ�����������Ʈ�˿�ȥ�������Ƶ�$N���ᣡ\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
                      return notify_fail("��Ѫʮ����ֻ��ͨ��ѧϰ��������\n");
        return 1;
}
int effective_level() { return 20;}

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
        return 20;
} 
string perform_action_file(string action)
{
        return CLASS_D("tieflag") + "/tie-steps/" + action;
}
string belong()
{
	return "tieflag";
}