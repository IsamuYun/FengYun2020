inherit SKILL;
string *dodge_msg = ({
        "$n��Ӱһ�Σ����Ǽ�Ų��$N�ı���\n",
        "$n����΢΢�ζ���������Ʈ�����⡣\n",
        "$n�������΢΢�趯��������˲��͵�����$N�Ĺ�����Χ��\n",
        "$n˫��΢�ʣ��˼���Ϊ���ػ�Ӱ��ʹ$N�޷�ȷ��������Ŀ�ꡣ\n",
        "$n����һ���������˺��Ƴ����⡣\n"
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
                return notify_fail("�������̫���ˣ���������ң�Ρ�\n");
        me->receive_damage("kee", 30);
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
        return 0;
}

string perform_action_file(string action)
{
        return CLASS_D("piaomiao") + "/xiaoyao-steps/" + action;
}
