// tang-steps.c ����ǧ�ﲽ 

inherit SKILL;

string *dodge_msg = ({
	"$n�������ĵ���������һ�����պñܹ�$N���������ơ�\n",
	"����$nǡ����������һ���������$N��һ�С�\n",
	"ֻ��$nһ�С��׺׳��졹���������ϱ�ֱ���������࣬�����$N��һ�С�\n",
	"$nһ�������ӷ���������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
	"$nʹ��������չ�᡹����һ��ƮȻ�ݳ��������ŵء�\n"
        "����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
       "$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
        "����$n����һ�ã�$N��һ�����˸��ա�\n",
        "ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
        "$n����΢�Σ��о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 100 )
		return notify_fail("�������������û�а취������ǧ�ﲽ��\n");

	return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
       return notify_fail("�������̫���ˣ�����������ǧ�ﲽ��\n");
        me->receive_damage("kee", 30);
return 1;
}
int effective_level() { return 15;}

int learn_bonus()
{
	return -20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("tangmen") + "/tang-steps/" + action;
}



