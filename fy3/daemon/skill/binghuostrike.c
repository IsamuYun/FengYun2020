// spicyclaw.c

inherit SKILL;

mapping *action = ({
	([	"action":		"$N左掌呈红色,一股巨大的热流扑向$n!",
		"dodge":		-30,
		"parry":		-70,
		"force":		460,
		"damage_type":	"抓伤"
	]),
	([	"action":		"$N右掌呈白色,一股强大的冷雾扑向$n!",
		"dodge":		-70,
		"parry":		-40,
		"force":		580,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N左右双掌相和,突然分开,瞬间爆发出:!轰!的一声巨响!",
		"parry":		-90,
		"force":		600,
		"damage_type":	"抓伤"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练寒冰烈火掌必须空手。\n");
	if( (int)me->query("max_force") < 150 )
		return notify_fail("你的内力太弱，无法练寒冰烈火掌。\n");
	return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 25 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	if( (int)me->query("force") < 3 )
		return notify_fail("你的内力不够了，休息一下再练吧。\n");
	me->receive_damage("kee", 25);
	me->add("force", -3);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if( damage_bonus < 100 ) return 0;

	if( random(damage_bonus/5) > victim->query_str() ) {
		victim->receive_wound("kee", (damage_bonus - 100) / 2 );
		switch(random(3)) {
			case 0: return "你听到「喀啦」一声轻响，竟似是骨碎的声音！\n";
			case 1: return "$N劲力一吐，$n的$l发出「喀」地一声爆响！\n";
			case 2: return "只听见$n的$l「喀」地一声 ...\n";
		}
	}
}
int effective_level() { return 18;}

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

string *parry_msg = ({
        "$n急划$N的脉门，逼得$N中途撤回手中的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n急划$N的脉门，逼得$N中途撤招。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
string perform_action_file(string action)
{
        return CLASS_D("yihua") + "/binghuostrike/" + action;
}


