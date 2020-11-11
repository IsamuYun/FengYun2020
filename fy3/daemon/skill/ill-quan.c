#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nһʽ���½�����������£�ʤ�����£�˫ȭ����$n��$l",
                "dodge":                -30,
                "parry":                50,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һת����ȭ���¶�������$n��$l",
                "dodge":                -40,
                "parry":                100,
                "force":                120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��һ�٣����˴�ȭ����$n��ǰ����Ѹ�ײ����ڶ�֮�ƻ���$n��$l",
                "dodge":                -30,
                "parry":                120,
                "force":                190,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��һת������$n��������$n��$l�ͻ�",
                "dodge":                -50,
                "parry":                200,
                "force":                290,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("����άĦȭ������֡�\n");
    return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }
int effective_level() { return 15;}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return notify_fail("��άĦȭֻ��ͨ��ѧϰ��������\n");
        return 1;
}
 
string perform_action_file(string action)
{
        return CLASS_D("tieflag") + "/ill-quan/" + action;
}

string *parry_msg = ({
        "$n���һָ������һ��$N��$w��$w��תͷȥ����$N���ɹ�ȥ��\n",
	"$nһ��$N��$w���������Ѿ���$N��ͷ����Խ������������������$N���\n",
	"$n����һ����������ճ��$N��$w��һ����\n",
        "$n����΢΢һ�࣬�Ѷ㿪$N�Ĺ��ơ�\n",
        "$N��ǰһ�������е�$w����������鴦����ϸһ����$nվ��ԭ��û�ж�����\n",
});

string *unarmed_parry_msg = ({
        "$n����΢΢һ�࣬�Ѷ㿪$N�Ĺ��ơ�\n",
        "$nһ�С�Χκ���ԡ������˷���������$N���Ƶ�$N�����Ա���\n",
	"$n˫ȭ���䣬��סȫ��Ҫ����\n",
        "$N��ǰһ�������е���ʽ����������鴦����ϸһ����$nվ��ԭ��û�ж�����\n",
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
	return 20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 30;
}
string belong()
{
	return "tieflag";
}
