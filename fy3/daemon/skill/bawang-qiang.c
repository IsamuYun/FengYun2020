//by lion

inherit SKILL;

mapping *action = ({
        ([      "action":
"$N使一招「迎门三不过」，手中$w连续刺向$n面门，哽嗓，前心",
                "damage":               350,
                "dodge":                500,
                "parry":                600,
                "force" :               300,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N运足精神，抖起$w，一招「拨草寻蛇」刺向$n$l",
                "damage":               320,
                "dodge":                600,
                "parry":                300,
                "force" :               350,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N一个跨步，使一招「高山流水」，手中$w势若飞瀑刺向$n的$l",
                "damage":               255,
                "dodge":                520,
                "parry":                345,
                "force":                200,
                "damage_type":  "刺伤"
        ]),
         ([      "action":
"$N一按枪把，啪！地一声抖出五朵枪花。上下左右，虚虚实实刺向$n全身要害",
                "damage":               225,
                "dodge":                600,
                "parry":                500,
                "force" :               450,
                "damage_type":  "刺伤"
        ]),
         ([      "action":
"只见$N一个斜跨，使个「举火烧天势」，手中$w带出一道寒气，由下而上疾挑$n$l",
                "damage":               235,
                "dodge":                200,
                "parry":                80,
                "force":                600,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"只见$N手腕一翻，手中$w从意想不到的角度刺向$n的$l。\n这一招「灵蛇出洞」快若闪电，毒辣无比",
                "damage":               445,
                "dodge":                500,
                "parry":                400,
                "force":                300,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N使个「飞鸟投林势」，身形斜飞，从侧面突出一枪，径刺$n$l",
                "damage":               240,
                "dodge":                150,
                "parry":                60,
                "force" :               250,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N似欲退走，可是忽地一个转身，百忙中使出一招「回马枪」，$w一挺刺向$n$l",
                "damage":               1130,
                "dodge":                100,
                "parry":                200,
                "force" :               1200,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;
        if( (int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够，没有办法练霸王枪法。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("你必须先找一柄枪才能练枪法。\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="spear") || (usage=="parry");
}

string *parry_msg = ({
        "$n使出一招「仙人指路」，手中的$v荡开$N的$w。\n",
        "$n使出「横扫千军」，将$N的$w封于丈外。\n",
        "$n使出一招「天涯何处」，手中的$v化做漫天残照，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「久历歧途」，向$N拿$w的手腕刺去。\n",
});

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string query_parry_msg(object weapon)
{
                return parry_msg[random(sizeof(parry_msg))];
 }

int effective_level() { return 15;}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "spear" )
                return
notify_fail("你必须先找一柄长枪或者是类似的武器，才能练枪法。\n");
        if( (int)me->query("kee") < 50 
        ||    (int)me->query("force") < 30  )
                return
notify_fail("你的体力不够练这门枪法，还是先休息休息吧。\n");
        me->receive_damage("kee", 50);
        me->add("force", -30);
        write("你按着所学练了一遍霸王枪法。\n");
        return 1;
}

int learn_bonus()
{
        return -300;
}
int practice_bonus()
{
        return -200;
}
int black_white_ness()
{
        return 82;
}
string perform_action_file(string action)
{
        return CLASS_D("linjiabao") + "/bawang-qiang/" + action;
}
