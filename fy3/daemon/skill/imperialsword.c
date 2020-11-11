// yiru@hero
// imperialsword.c
// 御剑术

#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":               
"只见弧光一闪，$N手中的$w已化作一道光环向$n的$l罩下。",
        "dodge":                -500,
        "parry":                -500,
        "damage":               500,
        "force":                500,
        "weapon":      "剑气",
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N使出御剑术中的「万剑决」，万道剑光霍霍划向$n的$l",
        "dodge":                -1500,
        "parry":                -1500,
        "damage":               3000,
        "force":                3000,
        "weapon":      "剑气",
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N使一招「仙风骤行」，身形陡然滑出数尺，手中$w斩向$n的$l",
        "dodge":                -700,
        "parry":                -700,
        "damage":               700,
        "force":                700,
        "weapon":      "剑气",
                "damage_type":  "拉伤"
        ]),
        ([      "action":               
"$N与手中$w心剑合一，对准$n的$l刺出惊天动地的一剑",
        "dodge":                -900,
        "parry":                -900,
        "damage":               900,
        "force":                900,
        "weapon":      "剑气",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w寒光四射，对准$n的$l斜斜刺出",
        "dodge":                -1100,
        "parry":                -1100,
        "damage":               1100,
        "force":                1100,
        "weapon":      "剑气",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N身形一转，使一招「御剑伏魔」，$n只见四周都是光弧刺向自己的$l",
        "dodge":                -1300,
        "parry":                -1300,
        "damage":               1300,
        "force":                1300,
        "weapon":      "剑气",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N将$w越舞越急，一团剑光，直冲$n而去。",
        "dodge":                -1500,
        "parry":                -1500,
        "damage":               1500,
        "force":                1500,
        "weapon":      "剑气",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N错步上前，弧光现处，$w向$n的$l划去。",
        "dodge":                -1500,
        "parry":                -1500,
        "damage":               1500,
        "force":                1500,
        "weapon":      "剑气",
      "damage_type":  "割伤"
        ]),

        ([      "action":               
"$N将$w一划,九道剑气化为三路，分攻$n上，中，下三盘。",
        "dodge":                -1700,
        "parry":                -1700,
        "damage":               1700,
        "force":                1700,
        "weapon":      "剑气",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N$w连点，无数剑气绵绵不绝地向$n攻去。",
        "dodge":                -1900,
        "parry":                -1900,
        "damage":               1900,
        "force":                1900,
        "weapon":      "剑气",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N将$w朝$n一指，只听“嗤”的一声，一道剑光以迅雷不及掩耳盗铃之势刺向$n的$l。",
        "dodge":                -1800,
        "parry":                -1800,
        "damage":               2100,
        "force":                2100,
        "weapon":      "剑气",
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N竖起$w，剑尖上光芒闪处，宛如“蜀山日出”，迸出万道金光，将$n罩住。",
        "dodge":                -1800,
        "parry":                -1800,
        "damage":               2300,
        "force":                2300,
        "weapon":      "剑气",
                "damage_type":  "刺伤"
        ]),
([      "action":               
"$N大喝一声，$w化作无数剑光，铺天盖地同时向$n刺去，意欲立斩$n于剑下，正是一招“除魔天地”。",
        "dodge":                -3000,
        "parry":                -3000,
        "damage":               3000,
        "force":                3000,
        "weapon":      "剑气",
                "damage_type":  "刺伤"
        ]),     
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query_skill_eff_lvl("pal-sword") 
            < me->query_skill_eff_lvl("imperialsword") )
                return notify_fail("你的蜀山剑法修为不够，没有办法练御剑术。\n");

        if( (int)me->query_skill("incarnation") < me->query_skill_eff_lvl("imperialsword") )
                return notify_fail("你的仙术修为不够，没有办法练御剑术。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

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
            return notify_fail("你的灵力不够了！\n");
        me->add("atman", -lvl);
        write("你按著所学练了一遍御剑术。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("xianren") + "/pal-sword/" + action;
}
 
int effective_level() { return 36;}

string *parry_msg = ({
        "$n不退反进，手中的$v轻描淡写的划开了$N的$w。\n",
        "$n$v一抖，幻出数朵剑花，挡住了$N的$w。\n",
        "$n御剑飞行，整个人隐蔽在一团剑光之中。\n",
        "$n使出「封」字诀，将$N的$w封于丈外。\n",
        "$n剑气急收，化作两股，“双龙飞舞”，绞住了$N的$w。\n",
        "$n将手中的$v化做万道剑气，迫得$N连连后退。\n",
});

string *unarmed_parry_msg = ({
        "无数剑气绵绵缠住了$N，将$N缠的动弹不得，举步维艰。\n",
        "$n手中的$v转成一道密不透风的光环，封住了$N的攻势。\n",
        "$n御剑飞行，整个人隐蔽在一团剑光之中。\n",
        "$n将手中的$v化做万道剑气，迫得$N连连后退。\n",
            "$n挺剑直指，从剑梢透出一股内力逼开了$N。\n",
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
                tell_object(me,HIC"由于你的蜀山剑法修为不够，你的御剑术又退步了。\n"NOR);
                return;
        }
    }
    
    if( (int)me->query_skill("incarnation") < (int)me->query_skill_eff_lvl("imperialsword"))
    {
        if(lvl > 1)
        {
                me->set_skill("imperialsword", lvl-1);
                tell_object(me,HIC"由于你的仙术修为不够，你的御剑术又退步了。\n"NOR);
                return;
        }
    }
}

