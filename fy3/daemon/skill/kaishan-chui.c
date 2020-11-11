inherit SKILL;

mapping *action = ({
        ([      "action":               "$N哪管三七二十一，举起$w朝着$n当头就是一家伙",
                "force":               700,
                "dodge":                600,
                "parry":                200,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               "只见$N眼冒凶光，青筋凸起，抄起$w就朝$n的$l狠命扫了过去",
               "damage":               550,
                "dodge":                400,
                "parry":                400,
                "damage_type":  "砸伤"
                ]),
        ([      "action":               "只听轰！地一声$N的$w在地上砸得尘土飞扬！紧接着$N就势翻了个跟头，又是一下向$n砸了过去",
                "damage":               570,
                "force" :               500,
                "dodge":                500,
                "parry":                700,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               "只见$N稍一运气，手中的$w上中下连扫三圈，逼得$n连退不迭",
                "damage":               540,
                "force" :               400,
                "dodge":                100,
                "parry":                400,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               "$N使出了一招「五丁开山」，手中的$w举重若轻，势若疯虎地向$n$l连连砸去",
                "force":               300,
                "damage" :              350,
                "dodge":                100,
                "parry":                400,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               "但见$N一个转身，手中$w由下而上一荡，$n只听一阵风声擦耳而过！\n$n正在暗叫侥幸之时，$N的$w就势一转，又砸了回来",
                "dodge":                150,
                "parry":                500,
                "damage":               525,
                "force" :               600,
                "damage_type":  "砸伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("str") < 40 )
                return notify_fail("开山锤要足够的臂力才能发挥作用。\n");
        if( (int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够，没有办法学开山锤。\n");
        if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "hammer" )
                return notify_fail("你必须先找一把锤子才能学开山锤。\n");

        return 1;
}

int valid_enable(string usage)
{
 return (usage=="hammer") || (usage=="parry");
}

int effective_level() { return 32;}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string *parry_msg = ({
        "$n后退一步，一招［荡气回肠］手中的$v猛的砸向$N的$w。\n",
        "$n身形微顿，手中的$v一招［围韩救赵］反捣$N的必救之处。\n",
        "$n手中的$v从下往上急挥，一招［恶鬼还阳］磕开了$N手中的$w\n",
});

string *unarmed_parry_msg = ({
        "$n一招［钟鼓齐鸣］，手中的$v从偏锋击向$N的太阳大穴。\n",
        "$n手中的$v从左划右，一招［横扫千军］封住了$N的攻势。\n",
        "$n凌空三连翻，一招［披沙拣金］手中的$v反击$N的后脑，逼得$N中途撤招。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 60 || (int)me->query("force") < 60 )
                return notify_fail("你现在太累了，强练无益。\n");
        me->receive_damage("kee", 60);
        me->add("force", -60);
        write("你按着所学练了一遍开山锤。\n");
        return 1;
}

int learn_bonus()
{
        return -100;
}
int practice_bonus()
{
        return -100;
}
int black_white_ness()
{
        return 10;
}
string perform_action_file(string action)
{
        return CLASS_D("linjiabao") + "/kaishan-chui/" + action;
}
