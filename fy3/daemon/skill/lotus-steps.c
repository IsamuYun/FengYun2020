// �����ò�

inherit SKILL;

string *dodge_msg = ({
        "����$n����Ʈ��������һ�ݣ��������ŵıܿ���һ����\n",
        "$n������ת����������ܿ����ߣ��ܿ��ˡ�\n",
        "$n�����ƻã��������ϰ���һ��ת����������֮�⡣\n"
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
        return notify_fail("�����ò�ֻ��ͨ����ʦ��ѧϰ��������\n");
        return 1;
}
int effective_level() { return 10;}

int learn_bonus()
{
          return -60;
}
int practice_bonus()
{
        return -10;
}
int black_white_ness()
{
        return 0;
}

string perform_action_file(string action)
{
        return CLASS_D("xingguo") + "/lotus-steps/" + action;
}
string belong()
{
	return "xingguo";

}