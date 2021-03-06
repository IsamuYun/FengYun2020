//LMD@FYTX
inherit SKILL;
mapping *action = ({
        ([      "action":               "$N面露平和笑容，凭空划下，使出一招「斜风细雨」，手中$w如梦似幻般地直劈$n的$l！",
                "damage":               70,
                "dodge":                200,
                "parry":                200,    
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N使出一招「雨打风吹」掌中$w泛出森森刀光，映得$n眼花缭乱，趁机平削$n的$l！",
                "damage":               80,
                "dodge" :               100,
                "parry" :               100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N单掌虚晃，$w反手一招「狂风暴雨」狠狠砍向$n的$l",
                "damage":               80,
                "dodge" :               100,
                "parry" :               100,
                "damage_type":  "割伤"

        ]),
        ([      "action":               "$N身形一纵，一招「柔雨丝丝」，$w往$n的$l斜斜撩出一刀",
                "damage":               40,
                "dodge" :               10,
                "parry" :               10,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中$w幻出满天刀光，一招「雨过天晴」，身行如飞，无声无息地转到$n的背后，猛剁$n的$l",
                "damage":               90,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N的$w走弧形，一招「心雨无息」，封住$n的退路，刀尖直刺$n的$l",
                "damage":               30,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N一招「柔风细雨」，$w挂风，自上而下，电闪般砍向$n的$l",

                "damage":               50,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N一招「雨打莲花」，$w发疯般狂砍，攻得$n心惊胆战！",
                "damage":               200,
                "dodge" :               -200,
                "parry" :               -100,
                "damage_type":  "割伤"
        ]),
        
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 200 )
                return notify_fail("你的内力不够，没有办法练唤雨刀法。\n");



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
int effective_level() { return 20;}

string *parry_msg = ({
        "$n使出一招「细雨无声」，手中$v虚点一招，突然回招换式，护住$n的全身。\n",
        "$n手中$v虚刺，突然翻转，一招「飞花雾雨」，护住全身要害。\n",
        "$n一招「飞雨迎春」，身影闪过，又飘回原地，手中$v＂铛＂的一声磕开了$N的$w。\n",
        "$n一招「霪雨菲菲」，身形虚晃，将$N的招式引开，$v却直袭$N之必救。\n",
});


string *unarmed_parry_msg = ({
"$n一招「狂风暴雨」，用手中的$v荡开了$N的招式。\n",
"$n故意丢个破绽，一招「雨后乍晴」，手中单刀反挥向$N之必救。\n",
"$n手中$v舞得风雨不透，一招「漫天细雨」，逼得$N回手撤招。\n",
"$n一招「稀雨如油」，全然不顾$N的攻击，$v直向$N砍去，逼得$N回招自保。\n",
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
        return CLASS_D("lou") + "/blade/" + action;
}