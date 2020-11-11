// 黑苗拳法
// fire-dragon 火龙掌

#include <ansi.h>
#include <condition.h>

inherit SKILL;

mapping *action = ({
([  "action":           HIG "$N"HIG"左手一聚，幻出三条烈火巨龙，向$n"HIG"的$l抓去"NOR,
        "dodge":                -600,
        "parry":                -600,
        "damage":               600,
        "force":                600,
    "weapon":      "火龙",
        "damage_type":  "抓伤"
]),
([  "action":           HIG "$N"HIG"右手一聚，幻出五条烈火巨龙，向$n"HIG"的$l直刺而去"NOR,
        "dodge":                -900,
        "parry":                -900,
        "damage":               900,
        "force":                900,
    "weapon":      "火龙",
        "damage_type":  "刺伤"
]),
([  "action":           HIY "$N"HIY"双手一聚，幻出七条烈火巨龙，飞快的擦过$n"HIY"的$l"NOR,
        "dodge":                -1200,
        "parry":                -1200,
        "damage":               1200,
        "force":                1200,
    "weapon":      "火龙",
        "damage_type":  "割伤"
]),
([  "action":           HIR "$N"HIR"全身一聚，化作九条烈火巨龙，飞向$n"HIR"的$l"NOR,
        "dodge":                -1500,
        "parry":                -1500,
        "damage":               1500,
        "force":                1500,
    "weapon":      "火龙",
        "damage_type":  "瘀伤"
])});

int valid_enable(string usage) 
{ 
    return (usage == "unarmed") || (usage == "parry");
}

int valid_learn(object me)
{
       if( (int)me->query_skill("unarmed",1) < me->query_skill("fire-dragon",1) )
        return notify_fail("你的扑击格斗之技太差了，无法继续领悟这门武功。\n");

    if( (int)me->query_skill("fire-force",1) < me->query_skill("fire-dragon",1) )
        return notify_fail("你对赤血毒焰心法的领悟不够，无法继续学习这门武功。\n");

    if( (int)me->query("max_force") < 1000 || (int)me->query("force") < 1500 )
        return notify_fail("你的内力不足，没有办法练火龙掌, 多练些内力再来吧。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练火龙掌必须空手。\n");

        return 1;
}

string *parry_msg = ({
    HIM"$n全身如一团火焰一般燃烧，逼得$N不敢近身。\n"NOR,
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
            return HIC"$n被$N的毒焰烧着了！！！\n"NOR;
        }

    return 0;
}

int practice_skill(object me)
{
    if ( me->query("force") > me->query("max_force") )
        return notify_fail("你现在真气激荡，不能练火龙掌。\n");
    if ( me->query("force") < 200)
        return notify_fail("你的内力不够练火龙掌了。\n");
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
