// fonxansword.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N使一招「花香草绿」，手中$w闪电刺向$n的$l",
                "dodge":                -20,
                "damage":               230,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N横剑上前，身形一转手中$w使一招「云雾缭绕」画出一道光弧刺向$n的$l",
                "dodge":                -30,
                "damage":               350,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练兰花剑法。\n");

        if( (string)me->query_skill_mapped("force")!= "lanhua-force")
                return notify_fail("兰花剑法必须配合兰花心法才能练。\n");

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
notify_fail("你的内力或气不够，没有办法练习兰花剑法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("你按著所学练了一遍兰花剑法。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("yihua") + "/lanhua-sword/" + action;
}
 
int effective_level() { return 18;}

string *parry_msg = ({
        "$n使出一招「彩蝶飞飞」，手中的$v化作一片蝶影，磕开了$N的$w。\n",
        "$n使出「封」字诀，将$N的$w封于丈外。\n",
        "$n使出一招「绵绵细雨」，手中的$v化做漫天水滴，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「丹凤朝阳」，向$N拿$w的手腕削去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手一招「波光淋漓」，整个人消失在一团剑光之中。\n",
        "$n使出一招「雨后春笋」，$v直刺$N的双手。\n",
        "$n将手中的$v化做数条飞蝶，迫得$N连连后退。\n",
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
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}

