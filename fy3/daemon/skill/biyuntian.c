#include <ansi.h>
inherit FORCE;
mapping *action = ({
                        ([      "action":               
                                        "$Nʹ��һ�С�а�Ʊ��ա�������һ�ݣ�˫�����϶��£�����$n��$l",
                                "dodge":                250,
                                "parry":                250,
                                "force":                200,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$Nʹ��һ�С���ӳѪ�ա���˫��һ�֣�ֱ��$n��$l",
                                "dodge":                200,
                                "parry":                200,
                                "force":                270,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$Nʹ��һ�С���ɫ��а�������Ʋ���$n��$l",
                                "dodge":                300,
                                "parry":                300,
                                "force":                250,
                           "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N˫��һ��һ����Σ�ʹ��������ħӰ������׼$n��$l����б��",
                                "dodge":                400,
                                "parry":                500,
                                "force":                350,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$N���κ�����ң�˫����ӣ�ʹ����������������Ϯ��$n$l",
                                "dodge":                300,
                                "parry":                300,
                                "force":                240,
                                "damage_type":  "����"
                        ]),
                        ([      "action":               
                                        "$Nʹ�������պ��ơ�������˫�ƣ��ӿ��е�ͷ��$n��$l���ƹ���",
                                "dodge":                500,
                                "parry":                600,
                                "force":                350,
                                "damage_type":  "����"
                        ]),
                ([      "action":               "$Nʹһ�С���Ӱ���¡�����׼$n��$l��������һȭ",
                        "force":                350,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����ȭͷ��һ�С���Ѫ��ɽ������$n��$l�к���ȥ",
                        "force":                450,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N������Σ���ȭ���������ӡ���$n��$l����",
                        "force":                550,
                        "damage_type":  "����"
                ]),
                ([      "action":               "$N����һ����Ŀ¶Ѫ�⣬˫ȭʹ����Ѫ��ħ�졹����$n$l",
                        "force":                650,
                        "damage_type":  "����"
                ]),
});

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int lev = 0;
	int a1 = 0;
	int a2 = 0;
	int pro = 0;

	lev = me->query_skill("biyuntian",1);
	if(lev < 50)
	{
		return ("");	
	}

	a1 = (int)victim->query("int");
	a2 = (int)victim->query("spi");	
	
	pro = a1+a2-lev;
	if(pro < 4)
	{
		pro = 4;	
	}
	
	if(!random(pro))
	{
		victim->apply_condition("demon",1+(a1+a2+lev)/30);
		return (HIW"$n"NOR+HIW"����ħ��������������!\n" NOR);
	}
	
	return ("");
}

int valid_enable(string usage) 
{ 
return 	usage=="parry" ||
	usage=="unarmed" ||
	usage=="force";
}

int valid_learn(object me)
{
        if( (int)me->query("int") < 30 )
                return notify_fail("��Ĳ���̫��,ѧ���˱����졣\n");

        if( (int)me->query("spi") < 30 )
                return notify_fail("�������̫��,ѧ���˱����졣\n");

        if ((int)me->query_skill("force", 1) < 100) 
        {
                return notify_fail("��Ļ����ڹ����̫ǳ��\n");
        }
	return 1;
}

int practice_skill(object me)
{
        return notify_fail("������ֻ����ѧ�ġ�\n");
}

 
int effective_level() { return 20;}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string *unarmed_parry_msg = ({
        "$nʹ��һ�С���ҹ���ȡ�������������$N��˫��������ס��\n",
        "$n���Ʋ�㣬һ�С�������������$N��˫�֡�\n",
        "$nʹ����Թ�����졹��˫��һ������ƫ��$N�Ĺ��ơ�\n",
        "$nһ�С���ħһ�ߡ����ͻ�$N�����ţ��Ƶ�$N��;���С�\n",
        "$n��ȭ��ϣ���ȭһ�С�����񺿡����Ƶ�$N����������\n",
        "$n����Ϊ����һ�С�аħ��������ͻ�$N������\n",
});
string *parry_msg = ({
        "$nʹ��һ�С���ҹ���ȡ�������������$N��$w������ס��\n",
        "$n���Ʋ�㣬һ�С�������������$N����$w���֡�\n",
        "$nʹ����Թ�����졹��˫��һ������ƫ��$N��$w��\n",
        "$nһ�С���ħһ�ߡ����ͻ�$N�����ţ��Ƶ�$N��;�������е�$w��\n",
        "$n��ȭ��ϣ���ȭһ�С�����񺿡����Ƶ�$N����������\n",
        "$n����Ϊ����һ�С�аħ��������ͻ�$N��$w������\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int bounce_ratio()
{
	return 40;
}

int learn_bonus()
{
	return -1000;
}
int practice_bonus()
{
	return -1000;
}
int black_white_ness()
{
	return 200;
}
string exert_function_file(string func)
{
        return CLASS_D("huashan") + "/biyuntian/" + func;
}

string perform_action_file(string action)
{
        return CLASS_D("huashan") + "/biyuntian/" + action;
}
void skill_improved(object me)
{
	int lev = 0;
	int a1 = 0;
	int a2 = 0;
	int exp = 0;
	
	lev = me->query_skill("biyuntian",1);
	a1 = (int)me->query("int");
	a2 = (int)me->query("spi");
	exp = (int)me->query("combat_exp");
	
	if(!random(a1/30+a2/30+lev/15))
	{
		if(lev > 1)
		{
			me->set_skill("biyuntian", lev-1);
		}
		me->apply_condition("demon",a1/30+a2/30+lev/15);
	}
}

