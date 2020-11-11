// six-chaos-sword.c

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"Ⱥħ����",
		"action":		"$N����ͻ������ɭ�ϣ�����ǧ�������۶�������ǹ��ꪣ���ɳǧ����ƻ���$n��$l!",
		"dodge":		-200,
		"parry" :		-200,
		"damage":		70,
		"force" : 		200,
		"damage_type":	"����"
	]),
	([	"name":			"�������",
		"action":		"$N����һ��ָ��$n���������$n���������ڣ��˵����������ף�����˼��",
                "dodge":                -200,
                "parry" :               -200,
                "damage":               50,
                "force" :               100,
		"damage_type":	"����"
	]),
	([	"name":			"�ٹ�ҹ��",
		"action":		"$N�趯$w��һ�С����ա�Ю�������������$n��$l",
                "dodge":                -200,
                "parry" :               -300,
                "damage":               150,
                "force" :               250,
		"damage_type":	"����"
	]),
	([	"name":			"������·",
		"action":		"$N����ͻ��Ц�ݣ��ƺ��ѿ���$n���书��ʽ�����г����һ������$n��",
                "dodge":                -100,
                "parry" :               -100,
                "damage":               50,
                "force" :               150,
		"damage_type":	"����"
	]),
      ([     "action":         "$NĿ�����ǣ��������£�����бб����$n��$l��",
             "dodge":          -40,
            "parry" :          -49,
            "damage":          140,
             "force":           100,
           "damage_type":      "����"
]),

});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("�������������û�а취�����¾Ž���\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	return notify_fail("���¾Ž�ֻ��ͨ�����ܾ�ʽ����������\n");
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

int effective_level() { return 27;}

string *parry_msg = ({
        "ȴ��$n̤ǰһ������ʽбָ$N���ұۣ���Ҫʹ$N������ˡ�\n",
        "$n��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$N���Ƶ��������ȵ�$N���ò��أ�\n",
});

string *unarmed_parry_msg = ({
        "ȴ��$n̤ǰһ������ʽбָ$N���ұۣ���Ҫʹ$N������ˡ�\n",
        "$n��Ю���ƣ��󿪴��ص��ҿ�һͨ�������нԻ���$N���Ƶ��������ȵ�$N���ò��أ�\n",
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
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return -10;
}

string perform_action_file(string action)
{
        return CLASS_D("bat") + "/dugu-sword/" + action;
}


