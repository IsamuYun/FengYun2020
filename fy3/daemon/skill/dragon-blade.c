// dragon-blade.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使一招「龙飞凤舞」，手中$w如万道金龙般砍向$n的$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "砍伤"
        ]),
        ([      "action":               
"$N使出降龙刀法中的「龙盘虎踞」，刀光霍霍斩向$n的$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「龙争虎斗」，身形陡然飘开数尺，手中$w斩向$n的$l",
                "dodge":                -30,

                "damage":               20,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w中宫直进，一式「龙潭虎穴」对准$n的$l连砍数刀",
                "dodge":                -40,
                "damage_type":  "砍伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w一招「龙腾虎跃」对准$n的$l斜斜劈出一刀",
                "dodge":                -40,
                "damage_type":  "劈伤"
        ]),
        ([      "action":               
"$N的$w幻出重重刀影，一招「龙翔万里」砍向$n的$l",
                "dodge":                20,
                "damage":               40,
                "damage_type":  "砍伤"
        ]),
        ([      "action":               

"$N手中$w向外一分，使一招「龙潜深渊」反手对准$n$l一刀砍去",
                "dodge":                -20,
                "damage":               20,
                "damage_type":  "砍伤"
        ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练伏龙刀法。\n");

 //       if( (string)me->query_skill_mapped("force")!= "jingyiforce")
 //               return notify_fail("伏龙刀法必须配心法才能练。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )

                return notify_fail("你必须先找一把刀才能练刀法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="blade" || usage=="parry";
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

notify_fail("你的内力或气不够，没有办法练习伏龙刀法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按著所学练了一遍伏龙刀法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("dragon") + "/blade/" + action;
}
 
int effective_level() { return 18;}

string *parry_msg = ({
        "$n使出一招「龙舞九天」，手中的$v化作一条金龙，磕开了$N的$w。\n",
        "$n使出「伏」字诀，将$N的$w封于丈外。\n",
        "$n使出一招「降龙伏虎」，手中的$v化做漫天刀影，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「幻影金龙」，向$N拿$w的手腕砍去。\n",
});


string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手一招「云龙突现」，整个人消失在一团迷离的刀光之中。\n",
        "$n使出一招「龙舞九天」，$v直劈$N的双手。\n",
        "$n将手中的$v化做七条刀影，迫得$N连连后退。\n",
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