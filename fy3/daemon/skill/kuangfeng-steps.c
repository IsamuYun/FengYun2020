inherit SKILL;

string *dodge_msg = ({
        "$nһ�С�������ӿ�����������飬����Ʈ�����㿪��$N��ʽ��\n",
        "ֻ��$n���񲻶�����$N����ʽ���ϣ�һʽ��΢����桹�����ɵض���һ�ԡ�\n",
        "$nʹ�������Ʒ�����,����ܿ���\n",
        "$n˫��һ�㣬һ�С������ơ��ڿն��𣬱��˿�ȥ��\n",
        "����$nʹһ�С��������硹������Ʈ��������$N�Ĺ���ʧȥ��׼ͷ��\n",
        "$n����һ�С����ŭ�š�������Ʈ�ˣ�����������\n",
        "����$nһ�С��������ݡ�ʹ�������λζ����ó�������Ӱ�������ܳ����ɣ�\n",

});

int valid_enable(string usage)
{
        return (usage=="dodge") ;
}

int valid_learn(object me)
{

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취��������\n");

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
                return notify_fail("�������������������������粽����\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

int effective_level() { return 25;}

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
        return CLASS_D("lou") + "/steps/" + action;
}