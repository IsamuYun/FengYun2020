// lingbo-steps.c

inherit SKILL;

string *dodge_msg = ({
        "����$nʩչ�貨΢����ֻ�����赭д������̤��һ����������رܿ���$N�Ĺ��ơ�\n",
        "ֻ��$nʩչ�貨΢���������ϣ�է��է�������޳��򣬽�ֹ���ڡ�\n",
        "ֻ��$nʩչ�貨΢����������ӯ���·�����֮���£���֪���ľ͵�������֮�⡣��\n",
        "ֻ��$n��Ӱ�������һת����Ѹ����Ʈ������ʩչ�������貨΢����\n",
        "ֻ��$n��������̤��һ����ʩչ�貨΢����������������$Nǣ��������ת��\n",
        "ֻ��$nʩչ�貨΢��������Ư��������Ī������رܿ�$N�����ع��ơ�\n",
        "$n����ӰƮƮ��������֮��ѩ��ʩչ�������貨΢����$N��$n���½Ƕ�մ������\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취���貨΢����\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("�����������������������ϰ�貨΢����\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
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
        return 10;
}

string perform_action_file(string action)
{
        return CLASS_D("dali") + "/steps/" + action;
}
