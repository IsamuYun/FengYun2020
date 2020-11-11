// yiru@hero
// imperialsword.c
// ������

#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":               
"ֻ������һ����$N���е�$w�ѻ���һ���⻷��$n��$l���¡�",
        "dodge":                -500,
        "parry":                -500,
        "damage":               500,
        "force":                500,
        "weapon":      "����",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ���������еġ��򽣾�������������������$n��$l",
        "dodge":                -1500,
        "parry":                -1500,
        "damage":               3000,
        "force":                3000,
        "weapon":      "����",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹһ�С��ɷ����С������ζ�Ȼ�������ߣ�����$wն��$n��$l",
        "dodge":                -700,
        "parry":                -700,
        "damage":               700,
        "force":                700,
        "weapon":      "����",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������$w�Ľ���һ����׼$n��$l�̳����춯�ص�һ��",
        "dodge":                -900,
        "parry":                -900,
        "damage":               900,
        "force":                900,
        "weapon":      "����",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$w�������䣬��׼$n��$lбб�̳�",
        "dodge":                -1100,
        "parry":                -1100,
        "damage":               1100,
        "force":                1100,
        "weapon":      "����",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һת��ʹһ�С�������ħ����$nֻ�����ܶ��ǹ⻡�����Լ���$l",
        "dodge":                -1300,
        "parry":                -1300,
        "damage":               1300,
        "force":                1300,
        "weapon":      "����",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wԽ��Խ����һ�Ž��⣬ֱ��$n��ȥ��",
        "dodge":                -1500,
        "parry":                -1500,
        "damage":               1500,
        "force":                1500,
        "weapon":      "����",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����ǰ�������ִ���$w��$n��$l��ȥ��",
        "dodge":                -1500,
        "parry":                -1500,
        "damage":               1500,
        "force":                1500,
        "weapon":      "����",
      "damage_type":  "����"
        ]),

        ([      "action":               
"$N��$wһ��,�ŵ�������Ϊ��·���ֹ�$n�ϣ��У������̡�",
        "dodge":                -1700,
        "parry":                -1700,
        "damage":               1700,
        "force":                1700,
        "weapon":      "����",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N$w���㣬�����������಻������$n��ȥ��",
        "dodge":                -1900,
        "parry":                -1900,
        "damage":               1900,
        "force":                1900,
        "weapon":      "����",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w��$nһָ��ֻ�����͡���һ����һ��������Ѹ�ײ����ڶ�����֮�ƴ���$n��$l��",
        "dodge":                -1800,
        "parry":                -1800,
        "damage":               2100,
        "force":                2100,
        "weapon":      "����",
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�������Ϲ�â���������硰��ɽ�ճ������ų������⣬��$n��ס��",
        "dodge":                -1800,
        "parry":                -1800,
        "damage":               2300,
        "force":                2300,
        "weapon":      "����",
                "damage_type":  "����"
        ]),
([      "action":               
"$N���һ����$w�����������⣬����ǵ�ͬʱ��$n��ȥ��������ն$n�ڽ��£�����һ�С���ħ��ء���",
        "dodge":                -3000,
        "parry":                -3000,
        "damage":               3000,
        "force":                3000,
        "weapon":      "����",
                "damage_type":  "����"
        ]),     
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query_skill_eff_lvl("pal-sword") 
            < me->query_skill_eff_lvl("imperialsword") )
                return notify_fail("�����ɽ������Ϊ������û�а취����������\n");

        if( (int)me->query_skill("incarnation") < me->query_skill_eff_lvl("imperialsword") )
                return notify_fail("���������Ϊ������û�а취����������\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
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
    int lvl = me->query_skill("imperialsword",1);
        if( (int)me->query("atman") < lvl )
            return notify_fail("������������ˣ�\n");
        me->add("atman", -lvl);
        write("�㰴����ѧ����һ����������\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("xianren") + "/pal-sword/" + action;
}
 
int effective_level() { return 36;}

string *parry_msg = ({
        "$n���˷��������е�$v���赭д�Ļ�����$N��$w��\n",
        "$n$vһ�����ó����佣������ס��$N��$w��\n",
        "$n�������У�������������һ�Ž���֮�С�\n",
        "$nʹ�����⡹�־�����$N��$w�������⡣\n",
        "$n�������գ��������ɣ���˫�����衱����ס��$N��$w��\n",
        "$n�����е�$v��������������ȵ�$N�������ˡ�\n",
});

string *unarmed_parry_msg = ({
        "�������������ס��$N����$N���Ķ������ã��ٲ�ά�衣\n",
        "$n���е�$vת��һ���ܲ�͸��Ĺ⻷����ס��$N�Ĺ��ơ�\n",
        "$n�������У�������������һ�Ž���֮�С�\n",
        "$n�����е�$v��������������ȵ�$N�������ˡ�\n",
            "$nͦ��ֱָ���ӽ���͸��һ�������ƿ���$N��\n",
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
        return -3600;
}
int practice_bonus()
{
        return -3600;
}
int black_white_ness()
{
        return 100;
}

void skill_improved(object me)
{
        int lvl;
    lvl = (int) me->query_skill("imperialsword",1);
        
    if( (int)me->query_skill_eff_lvl("pal-sword")< (int)me->query_skill_eff_lvl("imperialsword"))
    {
        if(lvl > 1)
        {
                me->set_skill("imperialsword", lvl-1);
                tell_object(me,HIC"���������ɽ������Ϊ������������������˲��ˡ�\n"NOR);
                return;
        }
    }
    
    if( (int)me->query_skill("incarnation") < (int)me->query_skill_eff_lvl("imperialsword"))
    {
        if(lvl > 1)
        {
                me->set_skill("imperialsword", lvl-1);
                tell_object(me,HIC"�������������Ϊ������������������˲��ˡ�\n"NOR);
                return;
        }
    }
}

