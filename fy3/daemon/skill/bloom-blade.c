inherit SKILL;
mapping *action = ({
        ([      "action":               "$N使一招「杀人见血」，手中$w连连向下斜劈，一刀削向$n的$l！",
                "dodge":                -870,
                "parry":                -700,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N身形急转，刀随人动，$w随著一招「腥风血雨」，刀风滚滚向$n的$l砍去！",
                "dodge":                -670,
                "parry":                -600,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N身行跃起，抡动手中$w，一招「血海深仇」，凌空劈向$n的$l",
                "dodge":                -570,
                "parry":                -500,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中$w舞动，刀光缭绕，一招「血肉相连」，从四面八方齐向往$n杀去！",
                "dodge":                -470,
                "parry":                -400,

                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中$w化作片片刀光，一招「茹毛饮血」，幻起一片刀影向$n罩去",
                "dodge":                -370,
                "parry":                -200,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中$w泛出一片血影，一招「含血喷人」直劈$n$l",
                "dodge":                -270,
                "parry":                -100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N使一招「血肉模糊」，手中$w盘转而进，刀光霍霍斩向$n的$l",
                "dodge":                -170,
                "damage_type":  "割伤"
        ]),
});
int valid_learn(object me)
{
        object ob;

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
                return notify_fail("你必须先找一把刀，才能练血刀大法。\n");
        if( (int)me->query("kee") < 40 )

                return notify_fail("你的体力不够练血刀大法，还是先休息休息吧。\n");
        me->receive_damage("kee", 40);
        return 1;
}
int effective_level() { return 8;}
string *parry_msg = ({
        "$n使出一招「碧血丹心」，手中的$v快似闪电般格开了$N的$w。\n",
        "$n手中$v泛出道道弧光，冷气森森，一招「血浓于水」，从侧面划向$N之必救。\n",
        "$n身形转动，手中的$v光华闪闪，一招「剖肝泣血」，反削$N的$w。\n",
});
string *unarmed_parry_msg = ({
"$n使出一招「呕心沥血」，手中的$v浑然波出，$N的攻势随波而散。\n",
"$n手中的$v拆招化式，游刃有余。\n",
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
        return 100;
}
int practice_bonus()
{
        return 50;
}
int black_white_ness()
{
        return 30;
}
string perform_action_file(string action)
{
        return CLASS_D("bloomdoor") + "/bloom-blade/" + action;
}
