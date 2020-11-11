// fonxansword.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使一招「青蛇狂舞」，手中$w带着霍霍剑光，宛如一条灵蛇般刺向$n的$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出青蛇剑法中的「蛇影万道」，剑光如梭般地斩向$n的$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「杯弓蛇影」，身形陡然凌空飞出数尺，手中的$w徒然斩向$n的$l",
                "dodge":                -30,

                "damage":               20,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w中宫直进，一式「灵蛇电闪」对准$n的$l猛的刺出数剑",
                "dodge":                -40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w一招「雪地飞蛇」对准$n的$l斜斜刺出一剑",
                "dodge":                -40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w凭空一指，猛然变换招事，一招「青蛇化龙」刺向$n的$l",
                "dodge":                20,
                "damage":               40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               

"$N手中$w向外一分，使一招「蛇困忧城」反手对准$n$l一剑刺去",
                "dodge":                -20,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N横剑上前，身形一转手中$w使一招「蛇影密布」画出一道光弧刺向$n的$l",
                "dodge":                -30,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练青蛇剑法。\n");


//        if( (string)me->query_skill_mapped("force")!= "wudu-force")
 //               return notify_fail("青蛇剑法必须配合五毒心法才能练。\n");

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
notify_fail("你的内力或气不够，没有办法练习青蛇剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍青蛇剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("wudujiao") + "/sword/" + action;
}
 
int effective_level() { return 15;}

string *parry_msg = ({

        "$n使出一招「青蛇翻身咬」，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n使出「盘身」诀，将$N的$w封于丈外。\n",
        "$n使出一招「灵蛇游八方」，手中的$v化做漫天蛇影，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「青蛇抢珠」，向$N拿$w的手腕削去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手一招「蛇焰冲天」，整个人消失在一团剑光之中。\n",
        "$n使出一招「蛇舞九天」，$v直刺$N的双手。\n",
        "$n将手中的$v化做七条剑气，宛如七条毒蛇，迫得$N连连后退。\n",
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
