
inherit FORCE;

int valid_enable(string usage) { return usage=="iron-cloth"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("ϴ�辭ֻ����ѧ�ġ�\n");
}

 
int effective_level() { return 35;}

string *absorb_msg = ({
        "$N����ܸһ�ɴ�����$n���Ϸ���������\n",
        "$nȫ��������̥���ǣ�һ�ɵ���������$N��\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
    return 100;
}

int learn_bonus()
{
	return -70;
}
int practice_bonus()
{
	return -20;
}
int black_white_ness()
{
	return 20;
}
string perform_action_file(string action)
{
        return CLASS_D("shaolin") + "/xisui/" + action;
}

