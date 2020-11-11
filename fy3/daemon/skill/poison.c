// poison.c

#include <ansi.h>
inherit FORCE;

mapping *action = ({
        ([      "action":               "$N��ȭ����$n��$l",
        "force":        200,
                "damage_type":  "����",
        ]),
        ([      "action":               "$N��$n��$lһץ",
        "force":        200,
                "damage_type":  "ץ��",
        ]),
        ([      "action":               "$N����ȭͷ��$n��$l��ȥ",
        "force":        200,
                "damage_type":  "����",
        ]),
        ([      "action":               "$N��׼$n��$l�����ӳ�һȭ",
        "force":        200,
                "damage_type":  "����",
        ]),
});

int valid_learn(object me) 
{
        if( ((int)me->query_skill("poison",1)>=60) && (string)me->query("class") != "baimiao")
                return notify_fail("���޷�ѧ��������Ķ�����\n");
        return 1;
}

int valid_enable(string usage) { return usage=="force" || usage=="unarmed"; }

int practice_skill(object me)
{
    if( (string) me->query_skill_mapped("force") != "poison" )
        return notify_fail("����ֻ������Ϊ�ڹ���ϰ��\n");

    if( me->query("force_factor") >= 
        (me->query_skill("force") + me->query_skill("poison",1) )/3 )
    return 
        notify_fail("����ڹ��޷����ӳ������������\n");
    me->add("force_factor",2);
        me->start_busy(2);
    return 
        notify_fail("���������ǿ�ˣ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("baimiao") + "/poison/" + func;
}
 
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int force, skill;

    if( (string) me->query_skill_mapped("force") != "poison" )
        return damage_bonus+factor;

    skill = (int)me->query_skill("poison",1);
    force = (int)victim->query_skill("force");

    if( random(2*skill+force) > force) {
                victim->apply_condition("unknown", skill / 20);
        skill = 2000 / skill;
        victim->receive_wound("gin", (int)me->query("gin")/skill);
        victim->receive_wound("kee", (int)me->query("kee")/skill);
        victim->receive_wound("sen", (int)me->query("sen")/skill);

        return HIW "$n����$N���ϵĶ���\n" NOR;
    }
    return skill+damage_bonus+factor;
}

string *parry_msg = ({
        "���Ǳ�$n���ˡ�\n",
        "�����$n�����ˡ�\n",
});

string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int effective_level() { return 8;}

int learn_bonus()
{
        return -100;
}
int practice_bonus()
{
        return -100;
}
int black_white_ness()
{
        return -200;
}

