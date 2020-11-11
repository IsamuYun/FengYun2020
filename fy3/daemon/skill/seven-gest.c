// seven-gest 七决剑气

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([  "action":           "$N手腕急振，指尖内力如枪直击，攻向$n的胸膛",
        "damage":               500,
        "force":                500,
        "skill_name" : "直劈",
        "damage_type":  "瘀伤"
]),
([  "action":           "$N单臂一挥，一道「剑气」自左而右划向$n的腿部",
        "damage":               700,
        "force":                700,
    "weapon":      "剑气",
        "skill_name" : "剑气",
        "damage_type":  "割伤"
]),
([  "action":           "$N振臂一举，一式「气剑指」，数道剑气从四面八方袭来，$n几乎都辩不明方向",
        "damage":               900,
        "force":                900,
    "weapon":      "剑气",
        "skill_name" : "气剑指",
        "damage_type":  "割伤"
]),
([  "action":           "$N双手急舞，一式「气剑斩」，双手聚出一股内劲破土而过，排山倒海般扫向$n下盘",
        "damage":               1100,
        "force":                1100,
    "weapon":      "剑气",
        "skill_name" : "气剑斩",
        "damage_type":  "刺伤"
]),
([  "action":           "$N忽的向前一跃，一式「半月斩」，以不可思意的角度划向$n前方",
        "damage":               1200,
        "force":                1200,
    "weapon":      "剑气",
        "skill_name" : "半月斩",
        "damage_type":  "割伤"
]),
([  "action":           "$N力贯指尖，一式「弦月斩」，气出无形, 突然从$n身后袭来, 锐不可当, 防不胜防",
        "damage":               1300,
        "force":                1300,
    "weapon":      "剑气",
        "skill_name" : "弦月斩",
        "damage_type":  "割伤"
]),
([  "action":           "$N如山而立，一式「横扫千军」，以地裂天崩之势凌空扫向$n",
        "damage":               1500,
        "force":                1500,
    "weapon":      "剑气",
        "skill_name" : "横扫千军",
        "damage_type":  "刺伤"
])
});

mapping *weapon_action = ({
([  "action":           "$N手腕急振，指尖内力随$w直击而出，攻向$n的胸膛",
        "damage":               700,
        "force":                700,
    "weapon":      "剑气",
        "skill_name" : "直劈",
        "damage_type":  "刺伤"
]),
([  "action":           "$N单臂一挥，一道「剑气」自左而右划向$n的腿部",
        "damage":               900,
        "force":                900,
    "weapon":      "剑气",
        "skill_name" : "剑气",
        "damage_type":  "割伤"
]),
([  "action":           "$N振臂一举，一式「气剑指」，数道剑气从四面八方袭来，$n几乎都辩不明方向",
        "damage":               1100,
        "force":                1100,
    "weapon":      "剑气",
        "skill_name" : "气剑指",
        "damage_type":  "刺伤"
]),
([  "action":           "$N双手急舞，一式「气剑斩」，双手聚出一股内劲破土而过，排山倒海般扫向$n下盘",
        "damage":               1200,
        "force":                1200,
    "weapon":      "剑气",
        "skill_name" : "气剑斩",
        "damage_type":  "瘀伤"
]),
([  "action":           "$N忽的向前一跃，一式「半月斩」，$w以不可思意的角度划向$n前方",
        "damage":               1300,
        "force":                1300,
    "weapon":      "剑气",
        "skill_name" : "半月斩",
        "damage_type":  "割伤"
]),
([  "action":           "$N力贯指尖，一式「弦月斩」，手中$w气出无形, 突然从$n身后袭来, 锐不可当, 防不胜防",
        "damage":               1400,
        "force":                1400,
    "weapon":      "剑气",
        "skill_name" : "弦月斩",
        "damage_type":  "割伤"
]),
([  "action":           "$N如山而立，一式「横扫千军」，手中$w以地裂天崩之势凌空扫向$n",
        "damage":               1500,
        "force":                1500,
    "weapon":      "剑气",
        "skill_name" : "横扫千军",
        "damage_type":  "刺伤"
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
        return notify_fail("你的扑击格斗之技太差了，学不了这门武功。\n");

    if( (int)me->query_spi() < 40 )
        return notify_fail("你的灵性太差了，无法学习这门武功。\n");

    if( (int)me->query("spi")*3 < me->query_skill("seven-gest",1) )
        return notify_fail("你的灵性太低了，无法继续领悟这门武功。\n");

    if( (int)me->query_skill("force",1) < me->query_skill("seven-gest",1) )
        return notify_fail("你的内功心法太差了，无法继续领悟这门武功。\n");

    if( (int)me->query("max_force") < 1500 || (int)me->query("force") < 1500 )
        return notify_fail("你的内力不足，没有办法练七决剑气, 多练些内力再来吧。\n");

    if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return notify_fail("练七决剑气必须空手。\n");

    if( (me->query_skill("seven-gest",1) > 10) && (me->query("family/family_name")!="林家堡"))
        return notify_fail("非林家堡弟子无法再继续学此武功。\n");
    
    return 1;
}

string *parry_msg = ({
        HIW"$n两指虚幌，将内劲从七个方向透出，逼得$N撤招自保。\n"NOR,
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
                return notify_fail("你的真气不够练七决剑气了。\n");
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
        HIC"$n身型微展，七决剑气并发，浑身肌肤射出犹如实质般的神芒剑气。\n"NOR,
        HIC"$n身体急转，双手连动，全身内劲化作七决剑气澎湃而出。\n"NOR,
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

