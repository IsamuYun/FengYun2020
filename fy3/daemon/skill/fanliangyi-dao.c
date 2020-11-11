// fanliangyi-dao.c �����ǵ���

inherit SKILL;

mapping *action = ({
([	"action" : "$N����$wбָ��һ�С�����һ�ơ�������һ�٣�һ����$n��$l��ȥ",
	"force" : 120,
	"dodge" : -10,
	"lvl" : 0,
	"skill_name" : "����һ��",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С�̫�����ȡ�����������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
	"force" : 140,
	"dodge" : -10,
	"damage" : 5,
	"lvl" : 20,
	"skill_name" : "̫������",
	"damage_type" : "����"
]),
([	"action" : "$Nչ���鲽������Ծ�䣬һ�С����Ǻϵ¡������滯������ն��$n",
	"force" : 160,
	"dodge" : -5,
	"damage" : 15,
	"lvl" : 40,
	"skill_name" : "���Ǻϵ�",
	"damage_type" : "����"
]),
([	"action" : "$Nһ�С����»�������$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
	"force" : 180,
	"dodge" : 5,
	"damage" : 25,
	"lvl" : 60,
	"skill_name" : "���»���",
	"damage_type" : "����"
]),
([	"action" : "$N����$wһ����һ�С���ɫ���ࡹ��˫�ֳ����������У�����$n���ؿ�",
	"force" : 200,
	"dodge" : 10,
	"damage" : 30,
	"lvl" : 80,
	"skill_name" : "��ɫ����",
	"damage_type" : "����"
]),
([	"action" : "$N����$w��ʹ��һ�С���ٲ��������������ã����ҿ�����������$n",
	"force" : 250,
	"dodge" : 15,
	"damage" : 35,
	"lvl" : 100,
	"skill_name" : "��ٲ���",
	"damage_type" : "����"
])
});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("zixia-shengong", 1) < 10)
		return notify_fail("��ġ���ϼ�񹦡����̫ǳ��\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("fanliangyi-dao",1);
//        for(i = sizeof(action); i > 0; i--)
//                if(level > action[i-1]["lvl"])
//                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("qi") < 50)
		return notify_fail("��������������������ǵ�������\n");
	me->receive_damage("qi", 25);
	return 1;
}

string perform_action_file(string action)
{
	 return CLASS_D("huashan") + "/fanliangyi-dao/" + action;
}