// snakestaff.c

inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":               
"$Nʹһ�С����է�֡�������$wɨ��$n���̣�",
                "damage":               40,
                "dodge":                -400,
                "parry":                -400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w��һ�С�������硹����$n$l��",
                "damage":               40,
                "dodge":                -200,
                "parry":                -600,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������$w��ʹ��������д�⡹����$n$l��",
                "damage":               40,
                "dodge":                -100,
                "parry":                -400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С��������ơ���$wһͦײ��$n$l��",
                "damage":               40,
                "dodge":                -100,
                "parry":                -400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
    if( ( (int)me->query("mana") + (int)me->query("max_mana") )< 400 )
        return notify_fail("��ķ�����������Ҳ�����һ����������ǿ������\n");

    return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "staff" )
                return 
            notify_fail("���������һ��ľ�Ȼ��������Ƶ��������������ȷ���\n");

        if( (int)me->query("mana") < 6 )
                return 
            notify_fail("��ķ��������������ȷ�����������Ϣ��Ϣ�ɡ�\n");
        me->add("mana", -6);
        return 1;
}

int effective_level() { return 22;}
 
string *parry_msg = ({
        "���$n�����е�$v����$N��$w��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
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
        return 1000;
}
int practice_bonus()
{
        return 1000;
}
int black_white_ness()
{
        return 80;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    int damage = me->query_skill("staff");
    if( random(damage) > 150) 
    {
        victim->receive_damage("gin",damage, me);
        victim->receive_damage("kee",damage, me);
        victim->receive_damage("sen",damage, me);
        me->add("mana",damage/3);
	        if(me->query("mana") > me->query("max_mana")*3)
	        {
	            me->set("mana", me->query("max_mana")*3);
	        }
        return HIM "�������£�$nֻ�о���Ѫ��������������\n" NOR;
    }
    return 0;
}

string perform_action_file(string action)
{
    return CLASS_D("baimiao") + "/snakestaff/" + action;
}
