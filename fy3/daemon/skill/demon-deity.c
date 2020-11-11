// yiru@hero
// ħ��

inherit SKILL;

string *dodge_msg = ({
        "$n���˷�������ǰ̤��һ�����Ƶ�$N��;���С�\n",
        "$n���һ�����ҿ�һ����һʱ����Ӱ�ƺ��������������$N�ε��ۻ����ҡ�\n",
        "$n���������һ���������š���������$N��һ�С�\n",
        "$n�Ų�һ��һ����������$N�ı���\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 180 )
                return notify_fail("�������������û�а취��ħ�񲽷���\n");

        return 1;
}

int effective_level() { return 12;}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    if( (int)me->query("max_force") < 2 )
        return notify_fail("�������������������ħ�񲽷���\n");
    me->add("max_force", -2);
    me->set("force", me->query("max_force"));
    return 1;
}

int learn_bonus()
{
        return -520;
}

int practice_bonus()
{
        return -520;
}

int black_white_ness()
{
        return -18;
}

string perform_action_file(string action)
{
    return CLASS_D("heimiao") + "/demon-deity/" + action;
}
