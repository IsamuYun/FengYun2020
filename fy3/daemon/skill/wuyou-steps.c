// wuyou-steps.c

inherit SKILL;

string *dodge_msg = ({
        "$n���в�����һ�С���Ӣ�ͷס��������ɵص��˿�ȥ��\n",
        "ֻ��$n��Ӱһ�Σ�һʽ���ɻ���Ҷ�����ѱ�������֮�⡣\n",
        "$nʹ����Ϧ����¶�����������ɵ���������\n",
        "$n����΢�㣬һ�ơ��仨���⡹�ڿն��𣬱��˿�ȥ��\n",
        "����$nʹһ�С��������硹����������Ʈ�˿�ȥ��\n",
        "$n��Ӱ΢�����Ѿ���һ�С�̤¶��������������\n",
        "����$nһ�С�ɽ��������ʹ���������Ƶ�$N���ᣡ\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)

{
        if( (int)me->query("max_force") < 25 )
                return notify_fail("�������������û�а취�����ǲ�����\n");

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
                return notify_fail("�����������������������ϰ���ǲ�����\n");
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
        return CLASS_D("baihua") + "/step/" + action;
}