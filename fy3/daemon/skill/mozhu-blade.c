//TIE@FY3
inherit SKILL;
mapping *action = ({
        ([      "action":               "$N脸上露出似笑非笑的笑容，突然使出一招「蛛丝马迹」，手中$w直劈$n的$l！",
                "damage":               70,
                "dodge":                200,
                "parry":                200,    
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N使出一招「坐收渔利」掌中$w泛出闪闪刀光，映得$n眼花缭乱，趁机平削$n的$l！",
                "damage":               80,
                "dodge" :               100,
                "parry" :               100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N单掌虚晃，$w反手一招「精益求精」狠狠砍向$n的$l",
                "damage":               80,
                "dodge" :               100,
                "parry" :               100,
                "damage_type":  "割伤"

        ]),
        ([      "action":               "$N身形一矮，一招「垂手而得」，$w往$n的$l斜斜撩出一刀",
                "damage":               40,
                "dodge" :               10,
                "parry" :               10,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中$w幻出满天刀光，一招「豁然贯通」，身行如飞，无声无息地转到$n的背后，猛剁$n的$l",
                "damage":               90,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N的$w走弧形，一招「饥不择食」，封住$n的退路，刀尖直刺$n的$l",
                "damage":               30,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N一招「难解难分」，$w挂风，自上而下，电闪般砍向$n的$l",

                "damage":               50,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N一招「南柯一梦」，$w发疯般狂砍，攻得$n心惊胆战！",
                "damage":               200,
                "dodge" :               -200,
                "parry" :               -100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中$w一招「假途灭虢」，刀人合一，冲杀过去，突然回手一刀，劈向$n的$l",
                "damage":               100,
                "dodge" :               -200,
                "parry" :               -100,
                "damage_type":  "割伤"
        ]),

});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 200 )
                return notify_fail("你的内力不够，没有办法练墨蛛刀法。\n");


        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀才能练刀法。\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)

{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀，才能练刀法。\n");

        if( (int)me->query("kee") < 40 )
                return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
        me->receive_damage("kee", 40);
        return 1;
}
int effective_level() { return 22;}

string *parry_msg = ({

        "$n使出一招「事与愿违」，手中$v虚点一招，突然回招换式，护住$n的全身。\n",
        "$n手中$v虚刺，半途突然翻转，一招「适可而止」，护住全身要害。\n",
        "$n一招「拭目以待」，身影闪过，又飘回原地，手中$v＂铛＂的一声磕开了$N的$w。\n",
        "$n一招「事在人为」，身形虚晃，将$N的招式引开，$v却直袭$N之必救。\n",
});

string *unarmed_parry_msg = ({
"$n一招「目空一切」，用手中的$v荡开了$N的招式。\n",
"$n故意丢个破绽，一招「目不暇接」，手中单刀反挥向$N之必救。\n",
"$n手中$v舞得风雨不透，一招「莫名其妙」，逼得$N回手撤招。\n",
"$n一招「迷途知返」，全然不顾$N的攻击，$v直向$N砍去，逼得$N回招自保。\n",
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
        return -150;
}
int practice_bonus()
{
        return -150;
}
int black_white_ness()
{
        return 30;
}

string perform_action_file(string action)
{
        return CLASS_D("wudujiao") + "/blade/" + action;
}