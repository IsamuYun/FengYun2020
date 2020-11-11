// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$Nƽƽ������ʹ��һ�С���ɳ·�����������ư������仯�����ƴ�������$n��$l",
                "dodge":                -100,
                "parry":                100,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һ�С�ƽ������ơ������ƻ���Ϊʵ����$n��$l",
                "dodge":                -100,
                "parry":                100,
                "force":                 70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������������Х���������죬һ�С�����Х���졹��һ������$n��$l",
                "dodge":                -100,
                "parry":                100,
                "force":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ϣ����ƻ��һ�С��󽭶���ȥ���ƺƵ�������׼$n��$l�����ĳ�",
                "dodge":                -100,
                "parry":                100,
                "force":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�Ʒ��������������������Ƴ���һ�С����׳��������޼᲻�ߵػ���$n$l",
                "dodge":                -100,
                "parry":                100,
                "force":                240,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ܣ��Ʒ����ᣬһ�С�ϸ��鴺�硹���ӿ��е�ͷ��$n��$l���ƹ���",
                "dodge":                -200,
                "parry":                200,
                "force":                150,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�����ڴ���ӡ������֡�\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n�����飬ʹ��һ�С�����ӳб��������������һ����$N��$w������\n",
        "$n��һת����ʽƮ��������һ�С����¼�ʱ�С�����$N����$w���֡�\n",
        "$n����������ʽ�����������־����������ӳ��һ�С�������ͬ�ԡ�����ƫ��$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n���β������������ڵ��⣬���ȶ�����һ�С����������¡����Ƶ�$N�����Ա���\n",
        "$n����Բת���������Ķ����䣬һ�С�������Ǭ���������赭д�Ļ�����$N�Ĺ��ơ�\n",
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
	return 0;
}

string perform_action_file(string action)
{
        return CLASS_D("taoist") + "/qiankunstrike/" + action;
}


