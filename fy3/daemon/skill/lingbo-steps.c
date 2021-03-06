// lingbo-steps.c

inherit SKILL;

string *dodge_msg = ({
        "可是$n施展凌波微步，只是轻描淡写地向旁踏出一步，就巧妙地避开了$N的攻势。\n",
        "只见$n施展凌波微步，神光离合，乍阴乍阳，动无常则，进止难期。\n",
        "只见$n施展凌波微步，步法轻盈，仿佛轻云之蔽月，不知怎的就到了数丈之外。。\n",
        "只见$n身影滴溜溜地一转，体迅飞鸟，飘忽若神，施展的正是凌波微步。\n",
        "只见$n左脚轻轻地踏出一步，施展凌波微步，若往若返，把$N牵得团团乱转。\n",
        "只见$n施展凌波微步，身行漂浮不定，莫名其妙地避开$N的重重攻势。\n",
        "$n的身影飘飘兮若流风之回雪，施展的正是凌波微步，$N连$n的衣角都沾不到！\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练凌波微步。\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的气或内力不够，不能练习凌波微步。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
int effective_level() { return 20;}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return 0;
}
int black_white_ness()
{
        return 10;
}

string perform_action_file(string action)
{
        return CLASS_D("dali") + "/steps/" + action;
}
