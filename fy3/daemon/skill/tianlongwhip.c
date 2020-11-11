// TIE@FY3
inherit SKILL;
mapping *action = ({
	([
		"action":		"$N����$w�ն����޷���ӿ��ȥʽ��������һ�С����ƺ�����������ֱ��$n��$l��",
		"dodge":		-500,
		"parry" :		-500,
		"force" :		500,
		"damage_type":	"����"
	]),
        ([
                "action":               "$N�۽�����һ˿Ц��,����$wȦ����һ�С���������Ц������������$n��$l��",
                "dodge":                -300,
                "parry" :               -300,
                "force" :               300,
                "damage_type":  "����"
        ]),
        ([
                "action":               "$N����$w���ڣ����μ�����һ�С����ܵǳ�����Ϸ�������ó�������Ӱ��ֱ��$n��$l��",
                "dodge":                -500,
                "parry" :               -500,
                "force" :               400,
                "damage_type":  "����"
        ]),
        ([
                "action":               "$N����$w����������ת��һ�С�����˭�����˹������ޱ޽Դ���$n��$l��",
                "dodge":                -700,
                "parry" :               -700,
                "force" :               700,
                "damage_type":  "����"
        ]),
        ([
                "action":               "$N����$w��ͷһ�ޣ������ű���һ�ڣ�һ�С�һ�����󷽷����������ó�����Ӱ����$nΧ�����У�",
                "dodge":                -500,
                "parry" :               -500,
                "force" :               600,
                "damage_type":  "����"
        ]),
        ([
                "action":               "$N����$wȦȦ��㣬�������࣬һ�С�������ʱ�����ԡ�������ʵʵ��$n��$l��ȥ��",
                "dodge":                -700,
                "parry" :               -700,
                "force" :               300,
                "damage_type":  "����"
        ]),
        ([
                "action":               "$Nʹ��һ�С������������뾻������ͷֱֱ����$n��$l��",
                "dodge":                -700,
                "parry" :               -700,
                "force" :               100,
                "damage_type":  "����"
        ]),
        ([
                "action":               "$N����$wӭͷ��ȥ�����Ұڶ���һ�С�δ��֪����֪�ա�������$n�ĵ���������",
                "dodge":                -300,
                "parry" :               -300,
                "force" :               700,
                "damage_type":  "����"
        ]),

});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 150 )
		return notify_fail("�������������û�а취�����������޷�������Щ���������ɡ�\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "whip" )
		return notify_fail("���������һ�����Ӳ������޷���\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 5 )
		return notify_fail("�����������������û�а취��ϰ���������޷���\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("�㰴����ѧ����һ�����������޷���\n");
	return 1;
}

int effective_level() { return 18;}

string *parry_msg = ({
        "$nʹ��һ�С�˫�����������ȡ�����׮վ�ȣ����㲻������׼$N�����ƣ�����$vһ�������$w��\n",
	"$nһ�С����ķ������������������������$vӭ��$N��$w�����$N˫�����飬$w��Щ���֡�\n",
});

string *unarmed_parry_msg = ({
        "$n����$v�ն������ν�����һ�С��ŵ��޸���ƮƼ��������$N�Ĺ���Ʈ����\n",
        "$n�����Ҷ���$v���գ�һ�С��ų���;�����١�����ȴת��$N����\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return -40;
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
        return CLASS_D("shaolin") + "/tianlongwhip/" + action;
}

