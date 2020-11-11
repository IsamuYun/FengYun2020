// seven-gest �߾�����

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([  "action":           "$N������ָ��������ǹֱ��������$n������",
        "damage":               500,
        "force":                500,
        "skill_name" : "ֱ��",
        "damage_type":  "����"
]),
([  "action":           "$N����һ�ӣ�һ����������������һ���$n���Ȳ�",
        "damage":               700,
        "force":                700,
    "weapon":      "����",
        "skill_name" : "����",
        "damage_type":  "����"
]),
([  "action":           "$N���һ�٣�һʽ������ָ������������������˷�Ϯ����$n�������粻������",
        "damage":               900,
        "force":                900,
    "weapon":      "����",
        "skill_name" : "����ָ",
        "damage_type":  "����"
]),
([  "action":           "$N˫�ּ��裬һʽ������ն����˫�־۳�һ���ھ�������������ɽ������ɨ��$n����",
        "damage":               1100,
        "force":                1100,
    "weapon":      "����",
        "skill_name" : "����ն",
        "damage_type":  "����"
]),
([  "action":           "$N������ǰһԾ��һʽ������ն�����Բ���˼��ĽǶȻ���$nǰ��",
        "damage":               1200,
        "force":                1200,
    "weapon":      "����",
        "skill_name" : "����ն",
        "damage_type":  "����"
]),
([  "action":           "$N����ָ�⣬һʽ������ն������������, ͻȻ��$n���Ϯ��, �񲻿ɵ�, ����ʤ��",
        "damage":               1300,
        "force":                1300,
    "weapon":      "����",
        "skill_name" : "����ն",
        "damage_type":  "����"
]),
([  "action":           "$N��ɽ������һʽ����ɨǧ�������Ե������֮�����ɨ��$n",
        "damage":               1500,
        "force":                1500,
    "weapon":      "����",
        "skill_name" : "��ɨǧ��",
        "damage_type":  "����"
])
});

mapping *weapon_action = ({
([  "action":           "$N������ָ��������$wֱ������������$n������",
        "damage":               700,
        "force":                700,
    "weapon":      "����",
        "skill_name" : "ֱ��",
        "damage_type":  "����"
]),
([  "action":           "$N����һ�ӣ�һ����������������һ���$n���Ȳ�",
        "damage":               900,
        "force":                900,
    "weapon":      "����",
        "skill_name" : "����",
        "damage_type":  "����"
]),
([  "action":           "$N���һ�٣�һʽ������ָ������������������˷�Ϯ����$n�������粻������",
        "damage":               1100,
        "force":                1100,
    "weapon":      "����",
        "skill_name" : "����ָ",
        "damage_type":  "����"
]),
([  "action":           "$N˫�ּ��裬һʽ������ն����˫�־۳�һ���ھ�������������ɽ������ɨ��$n����",
        "damage":               1200,
        "force":                1200,
    "weapon":      "����",
        "skill_name" : "����ն",
        "damage_type":  "����"
]),
([  "action":           "$N������ǰһԾ��һʽ������ն����$w�Բ���˼��ĽǶȻ���$nǰ��",
        "damage":               1300,
        "force":                1300,
    "weapon":      "����",
        "skill_name" : "����ն",
        "damage_type":  "����"
]),
([  "action":           "$N����ָ�⣬һʽ������ն��������$w��������, ͻȻ��$n���Ϯ��, �񲻿ɵ�, ����ʤ��",
        "damage":               1400,
        "force":                1400,
    "weapon":      "����",
        "skill_name" : "����ն",
        "damage_type":  "����"
]),
([  "action":           "$N��ɽ������һʽ����ɨǧ����������$w�Ե������֮�����ɨ��$n",
        "damage":               1500,
        "force":                1500,
    "weapon":      "����",
        "skill_name" : "��ɨǧ��",
        "damage_type":  "����"
])
});

int valid_enable(string usage) 
{ 
    return (usage == "whip") 
        || (usage == "sword")
        || (usage == "blade")
        || (usage == "iron-cloth")
        || (usage == "unarmed")
        || (usage == "force")
        || (usage == "parry");
}

int valid_learn(object me)
{
    object weapon;

    if( (int)me->query_skill("unarmed",1) < 230 )
        return notify_fail("����˻���֮��̫���ˣ�ѧ���������书��\n");

    if( (int)me->query_spi() < 40 )
        return notify_fail("�������̫���ˣ��޷�ѧϰ�����书��\n");

    if( (int)me->query("spi")*3 < me->query_skill("seven-gest",1) )
        return notify_fail("�������̫���ˣ��޷��������������书��\n");

    if( (int)me->query_skill("force",1) < me->query_skill("seven-gest",1) )
        return notify_fail("����ڹ��ķ�̫���ˣ��޷��������������书��\n");

    if( (int)me->query("max_force") < 1500 || (int)me->query("force") < 1500 )
        return notify_fail("����������㣬û�а취���߾�����, ����Щ���������ɡ�\n");

    if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return notify_fail("���߾�����������֡�\n");

    if( (me->query_skill("seven-gest",1) > 10) && (me->query("family/family_name")!="�ּұ�"))
        return notify_fail("���ּұ������޷��ټ���ѧ���书��\n");
    
    return 1;
}

string *parry_msg = ({
        HIW"$n��ָ��ϣ����ھ����߸�����͸�����Ƶ�$N�����Ա���\n"NOR,
});

string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}

mapping query_action(object me, object weapon)
{
  if(me->query_temp("weapon"))
        return weapon_action[random(sizeof(weapon_action))];
  else
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)(me->query("force")-me->query("max_force")) < 1500)
                return notify_fail("��������������߾������ˡ�\n");
        me->add("force", -1500);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("linjiabao") + "/seven-gest/" + action;
}

string exert_function_file(string func)
{
        return CLASS_D("linjiabao") + "/seven-gest/" + func;
}

int effective_level() { return 49;}

string *absorb_msg = ({
        HIC"$n����΢չ���߾������������������������ʵ�ʰ����â������\n"NOR,
        HIC"$n���弱ת��˫��������ȫ���ھ������߾��������ȶ�����\n"NOR,
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
    return 50;
}

int learn_bonus()
{
        return -4900;
}
int practice_bonus()
{
        return -4900;
}
int black_white_ness()
{
        return 100;
}

