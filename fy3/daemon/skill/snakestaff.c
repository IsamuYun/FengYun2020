// snakestaff.c

inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":               
"$N使一招「天光乍现」，手中$w扫向$n下盘！",
                "damage":               40,
                "dodge":                -400,
                "parry":                -400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N挥起$w，一招「雨後初晴」攻向$n$l！",
                "damage":               40,
                "dodge":                -200,
                "parry":                -600,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N横过手中$w，使出「浮云写意」击向$n$l！",
                "damage":               40,
                "dodge":                -100,
                "parry":                -400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N使出一招「游龙穿云」，$w一挺撞向$n$l！",
                "damage":               40,
                "dodge":                -100,
                "parry":                -400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
});

int valid_learn(object me)
{
    if( ( (int)me->query("mana") + (int)me->query("max_mana") )< 400 )
        return notify_fail("你的法力还不够，也许该练一练咒术来增强法力。\n");

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
            notify_fail("你必须先找一根木杖或者是类似的武器，才能练杖法。\n");

        if( (int)me->query("mana") < 6 )
                return 
            notify_fail("你的法力不够练这门杖法，还是先休息休息吧。\n");
        me->add("mana", -6);
        return 1;
}

int effective_level() { return 22;}
 
string *parry_msg = ({
        "结果$n用手中的$v格开了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
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
        return HIM "蛇信吞吐，$n只感觉气血不畅，心神不宁！\n" NOR;
    }
    return 0;
}

string perform_action_file(string action)
{
    return CLASS_D("baimiao") + "/snakestaff/" + action;
}
