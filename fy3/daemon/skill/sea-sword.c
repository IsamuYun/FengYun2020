inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N内力自手中$w激荡而出，一招「大龙剑」，$n被笼罩在一片剑光之中",
                "force" :               50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出海渊剑法中的「无敌剑」，手中$w势不可当，直取$n的$l",
                "force":               50,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「杀人剑」，腾空而起，身剑融为一体，化作一道寒光直刺$n的$l",
                "force":               50,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w连劈连挑，虚实相间，一式「大龙剑」，层层叠叠向$n的$l刺出",
                "force":                90,

                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w左削右砍，蓦地一招「大乐剑」反手对准$n$l一剑刺去",
                "force":               90,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;
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
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("你的内力或气不够，没有办法练习海渊剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍海渊剑法。\n");
        return 1;
}


string perform_action_file(string action)
{
        return CLASS_D("moondoor") + "/sea-sword/" + action;
}
 
int effective_level() { return 15;}

string *parry_msg = ({
        "$n使出一招「伤心剑」，身形拔地而起，手中的$v荡开了$N的$w。\n",
        "$n使出「不破剑」，身形未动，手中$v将$N的$w封于丈外。\n",
        "$n使出一招「大乐剑」，手中的$v光芒陡长，剑光自远而近，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「大愚剑」，向$N拿$w的手腕削去。\n",
});

string *unarmed_parry_msg = ({
        "$n用手中的$v带得$N脚步踉跄，一招「伤心剑」封住了$N的攻势。\n",
        "$n微一侧身，一招「不破剑」，整个人消失在一团剑光之中。\n",
        "$n使出一招「大愚剑」，$v直刺$N的双手。\n",
        "$n将手中的$v一抖，一招「大乐剑」，迫得$N连连后退。\n",
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
        return 20;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 15;

}