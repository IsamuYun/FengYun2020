//����Ӣ��
//by lion
// tiannan-step.c ���ϲ���

inherit SKILL;

string *dodge_msg = ({
    "ֻ��$nһ�С����ذδС����������ϱ�ֱ���������࣬�����$N��һ�С�\n",
    "$nһ��������鳲��������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
    "$nʹ������������������һ��ƮȻ�ݳ��������ŵء�\n"
    "����$n����Ʈ����һ�С��������С�����һ�ݣ����ѱܿ���\n",
    "$n������ת��һ�С��˷��ȥ��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
    "����$n����һ�ã�һ�С��绯������$N��һ�����˸��ա�\n",
    "ȴ��$n�㲻��أ�һ�С�����ֱ�ϡ����Դܿ����ߣ����˿�ȥ��\n",
    "$n����΢�Σ�һ�С�������졹�о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move");}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
    return dodge_msg[random(sizeof(dodge_msg))];
}

int effective_level() { return 43;}

int practice_skill(object me)
{
    if( (int)me->query("kee") < 180 )
       return notify_fail("������������ˣ�\n");
    me->receive_damage("kee", 150);
    return 1;
}

int learn_bonus()
{
        return -3800;
}
int practice_bonus()
{
        return -3800;
}
int black_white_ness()
{
        return 100;
}
