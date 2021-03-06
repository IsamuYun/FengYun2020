inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使一招「地动山摇」，手中$w如万道神光般挥向$n的$l",
                "dodge":                -20,
                "damage":               40,
                "damage_type":  "砍伤"
        ]),
        ([      "action":               
"$N使出大禹剑法中的「龙盘虎踞」，剑光霍霍劈向$n的$l",
                "dodge":                -20,
                "damage":               40,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「山水无情」，身形陡然飘开数尺，手中$w斩向$n的$l",
                "dodge":                -30,
                "damage":               50,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w中宫直进，一式「狂雨暴风」对准$n的$l连削数剑",
                "dodge":                -40,
                "damage_type":  "砍伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w一招「独劈山河」对准$n的$l斜斜劈出一剑",
                "dodge":                -40,
                "damage_type":  "劈伤"
        ]),
        ([      "action":               
"$N的$w幻出重重剑影，一招「剑游万里」挥向$n的$l",
                "dodge":                20,
                "damage":               50,
                "damage_type":  "砍伤"
        ]),
        ([      "action":               
"$N手中$w向外一分，使一招「神剑冲天」反手对准$n$l一刀削去",
                "dodge":                -20,
                "damage":               50,
                "damage_type":  "砍伤"
        ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练大禹剑法。\n");

        if( (string)me->query_skill_mapped("force")!= "wuwei-force")
                return notify_fail("大禹剑法法必须配心法才能练。\n");

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
notify_fail("你的内力或气不够，没有办法练习大禹剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按著所学练了一遍大禹剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("zhiyi") + "/sword/" + action;
}
 
int effective_level() { return 18;}

string *parry_msg = ({
        "$n使出一招「剑游万里」，手中的$v化作一条游龙，磕开了$N的$w。\n",
        "$n使出「漫天飞雨」，将$N的$w封于丈外。\n",
        "$n使出一招「飞沙走石」，手中的$v化做漫天剑影，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「暮月幻影」，向$N拿$w的手腕砍去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手一招「剑游万里」，整个人消失在一团迷离的剑光之中。\n",
        "$n使出一招「漫天飞雨」，$v直劈$N的双手。\n",
        "$n将手中的$v化做七条剑影，迫得$N连连后退。\n",
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


