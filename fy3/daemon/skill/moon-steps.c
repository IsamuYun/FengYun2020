inherit SKILL;
string *dodge_msg = ({
      "$nһ�С��µ��ǻ������������ĵ���������һ�����պñܹ�$N���������ơ�\n",
      "$nʹһ�С�������硱���������ϱ�ֱ���������࣬�����$N��һ�С�\n",
      "$nʩչ�����´�����,��һ��ƮȻ�ݳ��������ŵء�\n",
      "$n����΢�Σ�һ�С����²��������о����յرܿ���$N��һ�С�\n",
      "$nʹ��������˪�족�����λ�ʵΪ��ض㿪��$N��һ�С�\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge");
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
                return notify_fail("�������̫���ˣ�������Բ�²�����\n");
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
        return 3;
}
int black_white_ness()
{
        return 0;
}

string perform_action_file(string action)
{
        return CLASS_D("moon") + "/moon-steps/" + action;
}
