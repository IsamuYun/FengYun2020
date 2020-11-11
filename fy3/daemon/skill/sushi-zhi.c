// 俗世指 written by tiandi

inherit SKILL;

mapping *action = ({
	([	"action":		"$N“呼”地一指点出，这一招由中宫直进，指未到，指风已把$n压得揣不过气来",
		"dodge":		-70,
		"parry":		80,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N身形不动，右手作「天星八沾」状。$n稍一犹豫，$N的中指指节已敲向$n的$l",
		"dodge":		-30,
		"force":		200,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"只见$N一转身，一指由胁下穿出，趁$n还未缓身之时，疾刺$n的$l",
		"dodge":		-30,
		"parry":		150,
		"damage_type":	"瘀伤"
	]),
	([	"action":		"$N双掌一错，十指如穿花蝴蝶一般上下翻飞。$n只觉得全身都在$N指力笼罩之下",
		"dodge":		-100,
		"parry":		250,
		"damage_type":	"瘀伤"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练俗世指必须空手。\n");
	
	if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		return notify_fail("以你目前的状况，还没有资格练俗世指。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		return notify_fail("以你目前的状况，还没有资格练俗世指。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你的体力不够了，休息一下再练吧。\n");
	me->receive_damage("kee", 30);
	return 1;
}
int effective_level() { return 17;}

string *parry_msg = ({
        "$n一招「弹指问天」，猛击$N的$w，逼得$N中途撤回手中的$w。\n",
        "$n右拳虚幌，左指一招「长空」，凌空发出数指，逼得$N后退三步。\n",
});

string *unarmed_parry_msg = ({
        "$n脚走阴阳，一招「逍遥浴血」，攻$N之必救。\n",
        "$n十指齐射，一道接着一道，$N只觉所有内力被罡气所破，消失得无影无踪。\n",

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
        return CLASS_D("zhuge") + "/sushi-zhi/" + action;
}

int learn_bonus()
{
	return 50;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 0;
}

