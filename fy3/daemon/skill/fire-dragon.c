// ����ȭ��
// fire-dragon ������

#include <ansi.h>
#include <condition.h>

inherit SKILL;

mapping *action = ({
([  "action":           HIG "$N"HIG"����һ�ۣ��ó������һ��������$n"HIG"��$lץȥ"NOR,
        "dodge":                -600,
        "parry":                -600,
        "damage":               600,
        "force":                600,
    "weapon":      "����",
        "damage_type":  "ץ��"
]),
([  "action":           HIG "$N"HIG"����һ�ۣ��ó������һ��������$n"HIG"��$lֱ�̶�ȥ"NOR,
        "dodge":                -900,
        "parry":                -900,
        "damage":               900,
        "force":                900,
    "weapon":      "����",
        "damage_type":  "����"
]),
([  "action":           HIY "$N"HIY"˫��һ�ۣ��ó������һ�������ɿ�Ĳ���$n"HIY"��$l"NOR,
        "dodge":                -1200,
        "parry":                -1200,
        "damage":               1200,
        "force":                1200,
    "weapon":      "����",
        "damage_type":  "����"
]),
([  "action":           HIR "$N"HIR"ȫ��һ�ۣ����������һ����������$n"HIR"��$l"NOR,
        "dodge":                -1500,
        "parry":                -1500,
        "damage":               1500,
        "force":                1500,
    "weapon":      "����",
        "damage_type":  "����"
])});

int valid_enable(string usage) 
{ 
    return (usage == "unarmed") || (usage == "parry");
}

int valid_learn(object me)
{
       if( (int)me->query_skill("unarmed",1) < me->query_skill("fire-dragon",1) )
        return notify_fail("����˻���֮��̫���ˣ��޷��������������书��\n");

    if( (int)me->query_skill("fire-force",1) < me->query_skill("fire-dragon",1) )
        return notify_fail("��Գ�Ѫ�����ķ������򲻹����޷�����ѧϰ�����书��\n");

    if( (int)me->query("max_force") < 1000 || (int)me->query("force") < 1500 )
        return notify_fail("����������㣬û�а취��������, ����Щ���������ɡ�\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("�������Ʊ�����֡�\n");

        return 1;
}

string *parry_msg = ({
    HIM"$nȫ����һ�Ż���һ��ȼ�գ��Ƶ�$N���ҽ���\n"NOR,
});

string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    int force, dragon;
    
    if(me->query_skill_mapped("force")!="fire-force")
        return 0;

    force=me->query_skill("fire-force");
    dragon=me->query_skill("fire-dragon");

    if( 2*random(force+dragon) > random(victim->query("force")) )
        {
            victim->receive_wound("kee", (damage_bonus + factor+force+dragon));
            victim->receive_wound("gin", (damage_bonus + factor+force/2+dragon/2));
            victim->receive_wound("sen", (damage_bonus + factor+force/2+dragon/2));
            return HIC"$n��$N�Ķ��������ˣ�����\n"NOR;
        }

    return 0;
}

int practice_skill(object me)
{
    if ( me->query("force") > me->query("max_force") )
        return notify_fail("���������������������������ơ�\n");
    if ( me->query("force") < 200)
        return notify_fail("��������������������ˡ�\n");
    me->add("force", -200);
    return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("heimiao") + "/fire-dragon/" + action;
}

string exert_function_file(string func)
{
        return CLASS_D("heimiao") + "/fire-dragon/" + func;
}

int effective_level() { return 26;}

int learn_bonus()
{
        return -500;
}
int practice_bonus()
{
        return -500;
}
int black_white_ness()
{
        return 200;
}
