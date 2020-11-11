inherit SKILL;

string *dodge_msg = ({
        "$nһ�С����߿��衹���������飬����Ʈ����$N����ʽ��ա�\n",
        "ֻ��$n���лζ�����������$N����ʽ���ϣ�һʽ����˿���������ɵض���һ�ԡ�\n",
        "$nʹ����Ы���˼�����бб�شܿ���\n",
        "$n����һ�㣬һ�С�������Ӱ���ڿն��𣬱��˿�ȥ��\n",
        "����$nʹһ�С�������Ӱ��������Ʈ��������$N�Ĺ���ʧȥ��׼ͷ��\n",
        "$n����һ�С������Ծ��������ȡ��ȴ׾������������\n",
        "����$nһ�С���Ы��Ӱ��ʹ�������λζ����ó�������Ӱ���Լ�����Ʈ�����ɿ��⣡\n",

});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취�嶾������\n");

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
                return notify_fail("������������������������嶾������\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

int effective_level() { return 19;}

int learn_bonus()
{
        return -90;
}
int practice_bonus()
{
        return -50;
}
int black_white_ness()
{
        return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("wudujiao") + "/dodge/" + action;
}