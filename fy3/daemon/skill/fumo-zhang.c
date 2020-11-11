inherit SKILL;
mapping *action = ({
  ([    "action":               "$N运足力气将$w抡了几个大圆，呼！地一声向$n当头砸下",
    "dodge":            65,
    "parry":            -55,
    "damage":           285,
    "damage_type":      "砸伤"
  ]),
  ([    "action":               "只听$N一声高叫：还不缚手就擒！手中的$w一绞，扫向$n$l",
    "dodge":            50,
    "parry":            -65,
    "damage":           265,
    "damage_type":      "砸伤"
  ]),
  ([    "action":               "$N使出一招「群魔伏首」，手中的$w带出飞沙走石般的杖风压向$n的$l",
    "dodge":            55,
    "parry":            -55,
    "damage":           280,
    "damage_type":      "砸伤"
  ]),
  ([    "action":               "只见$N略略一退，旋即一个跨步，$w划出一道弧光刺向$n$l",
    "dodge":            55,
    "parry":            50,
    "damage":           270,
    "damage_type":      "刺伤"
  ]),
  ([    "action":               "$N横持$w，暗运真气，忽然间只见杖头一跳，灵蛇般钻向$n的$l",
    "dodge":            -55,
    "parry":            50,
    "damage":           165,
    "damage_type":      "刺伤"
  ]),
  ([    "action":               "$N的$w望上一挑，中途却使了个巧劲，杖尾嗖！地一翻，砸向$n$l",
    "dodge":            -65,
    "parry":            -60,
    "damage":           275,
    "damage_type":      "砸伤"
  ]),
});

int valid_learn(object me)
{
    object ob;

    if( (int)me->query("max_force") < 100 )
        return notify_fail("你的内力不够，没有办法学伏魔杖。\n");
    if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "staff" )
        return notify_fail("你必须先找一条禅杖才能学伏魔杖。\n");

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

int effective_level() { return 28;}

int practice_skill(object me)
{
    if( (int)me->query("kee") < 50 || (int)me->query("force") < 20 )
        return notify_fail("你现在太累了，强练无益。\n");
    me->receive_damage("kee", 30);
    me->add("force", -5);
    write("你按着所学练了一遍伏魔杖。\n");
    return 1;
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
    return 40;
}

string perform_action_file(string action)
{
    return CLASS_D("linjiabao") + "/fumo-zhang/" + action;
}
