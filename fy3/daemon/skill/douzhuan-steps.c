inherit SKILL;
string *dodge_msg = ({
        "$nһ�С������岼���������ɵر��˿�ȥ��\n",
        "ֻ��$n��Ӱһ�Σ�һʽ�������Ƶ硹���ѱ����߳�֮�⡣\n",
        "$nʹ������ת��Ȩ�����������ɵ�������\n",
        "$n����һ�㣬һ�С������пա��ڿն��𣬱��˿�ȥ��\n",
        "����$nʹһ�С��������硹����������Ʈ�˿�ȥ��\n",
        "����$nһ�С����Ʊ�á�ʹ���������Ƶ�$N���ᣡ\n"
});
int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}
int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취����ת���Ʋ�����\n");
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
                return notify_fail("�������������������������ת���Ʋ�����\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
int effective_level() { return 10;}
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
        return CLASS_D("bloomdoor") + "/douzhuan-steps/" + action;
}
