inherit SKILL;

string *dodge_msg = ({
        "����$n����Ʈ����һ�С����ɷ��衹�εض��𣬱ܿ�������һ����\n",
        "$n������ת��һʽ�����ڻ�Ծ����ȫ����������Ӱ�ӳ����⡣\n",
        "$n��������һ�Σ�һ�С��������졹���ڿն��𣬱��˿�ȥ��\n",
        "$n���۵��һ�С���󴻢�᡹�����μ������㿪$N������һ����\n",
        "$n��Ӱ΢�����Ѿ���һ�С�������Ԩ������������\n",
        "$n�ڿ�һԾ��˫����ǰһ�ߣ�һ�С��������������㿪���ߡ�\n",
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
        if( (int)me->query("kee") < 30 )
                return notify_fail("�������̫���ˣ�����������������\n");
        me->receive_damage("kee", 30);
        return 1;
}
int effective_level() { return 15;}

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
        return CLASS_D("moondoor") + "/flydragon-steps/" + action;
}
