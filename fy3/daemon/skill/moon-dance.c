#include <ansi.h>
inherit SKILL;
mapping *action = ({
        ([      "action":
"$Nʹ��һ�С�����䡹��������ѣ�����$w��������$n��$l",
		"damage":		3000,
		"dodge":		500,
		"parry":		500,	
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С���ħ�ҡ�����ҡ��ۣ�$w�ó����ع���֮��Ϯ��$n��$l",
		"damage":		5000,
		"dodge":		1000,
		"parry":		1000,	
                "damage_type":  "����"
        ]),
	([ 	"action":
"$Nʹ��һ�С���������������񺿣������������Ļ���Χ����$n�Ķ���",
		"damage":		7000,
		"dodge":		1500,
		"parry":		1500,	
                "damage_type":  "����"
        ]),
	([	"action":
"$Nʹ��һ�С��������������������������Ʊ����޼�ѹ��һ����һ������$n��$l",
		"damage":		9000,
		"dodge":		2000,
		"parry":		2000,	
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С�����ء������컻�أ�����$w������ң����Ϻ��£�Ʈ����������$n��$l",
		"damage":		3000,
		"dodge":		500,
		"parry":		500,	
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ�С����°����������޹⣬ȫ���ڿն�������$w���ñ�ֱ��Ȼ����$n��$l",
		"damage":		5000,
		"dodge":		1000,
		"parry":		1000,	
                "damage_type":  "����"
        ]),
	([ 	"action":
"$Nʹ��һ�С�Ѫ���졹��Ѫɫ���죬$w�����ɱ������ʵ�ʰ����$n��$l",
		"damage":		7000,
		"dodge":		1500,
		"parry":		1500,	
                "damage_type":  "����"
        ]),
	([	"action":
"$Nʹ��һ�С���Ǭ�������ض�ɽҡ��$w��������һ�㣬��۵糸�����$n��$l",
		"damage":		9000,
		"dodge":		2000,
		"parry":		2000,	
                "damage_type":  "����"
        ]),
});

int valid_enable(string usage) 
{ 
return 	(usage=="whip") || (usage=="force");
}

int valid_learn(object me)
{
	object ob;
    
    if( (int)me->query_spi() < 80 )
        return notify_fail("�������̫���ˣ��޷�ѧϰ�����书��\n");

    if( (int)me->query_int() < 80 )
        return notify_fail("��Ĳ���̫���ˣ��޷�ѧϰ�����书��\n");

    if( (int)me->query("spi")*3 < me->query_skill("moon-dance",1) )
        return notify_fail("�������̫���ˣ��޷��������������书��\n");

    if( (int)me->query_skill("force",1)/2 < me->query_skill("moon-dance",1) )
        return notify_fail("����ڹ��ķ�̫���ˣ��޷��������������书��\n");

    if( (int)me->query("max_force") < 2500 || (int)me->query("force") < 2500 )
        return notify_fail("����������㣬û�а취��ˮ������, ����Щ���������ɡ�\n");

	if( !(ob = me->query_temp("weapon"))
		||	(string)ob->query("skill_type") != "whip" )
		return notify_fail("���������һ�����Ӳ�����ˮ�����衣\n");

    if( me->query("family/family_name")!="���鵺" )
        return notify_fail("�����鵺ˮ�¹������޷�ѧ���书��\n");
    
    return 1;
}

int practice_skill(object me)
{
        return 
notify_fail("ˮ������ֻ����ѧ�ġ�\n");
}

 
int effective_level() { return 58;}

string *parry_msg = ({
        HIW"$nʩչ����ˮ�����衹�����赭д�Ļ�����$N�Ĺ��ơ�\n"NOR,
        HIW"$n������ת�����е�$v�û������ر�Ӱ��$N��ʱ��֪�Ӻδ�������\n"NOR,
});

string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string *absorb_msg = ({
        HIC"$n����΢չ������˺�һ���ͷ�ˮ�����軤��������\n"NOR,
        HIC"$n���弱ת��ȫ���ھ���������֮�����ȶ�����\n"NOR,
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
    return 80;
}

int learn_bonus()
{
        return -6800;
}
int practice_bonus()
{
        return -6800;
}
int black_white_ness()
{
        return 200;
}

string perform_action_file(string action)
{
        return CLASS_D("xianlingdao") + "/moon-dance/" + action;
}

string exert_function_file(string func)
{
        return CLASS_D("xianlingdao") + "/moon-dance/" + func;
}
