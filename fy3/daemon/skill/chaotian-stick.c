// 朝天棍
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N身形腾空而起，使出「 开天劈地」，手中$w隐隐发出“呼呼”之声，向$n的$l狠狠砸去！",
                "damage":               40,
                "dodge":                40,
                "parry":                40,
                "damage_type":  "挫伤"
        ]), 
        ([      "action":               
"$N使出一招「如来献佛」，手中$w挽出团团雪花，佛光顿现，罩向$n的$l！",
                "damage":               80,
                "dodge":                20,
                "parry":                60,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w一振，骤然加长了一丈之多，一招「何去何从」，满天皆是$w的影子，棍棍直指$n的$l！",
                "damage":               80,
                "dodge":                100,
                "parry":                40,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w抡动，来来回回数次，只见扬起一大片灰尘，一招「反反复复」，直奔$n的$l打去！",
                "damage":               200,
                "dodge":                -110,
                "parry":                -40,
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w朝天，怒曲成虹，一招「电闪雷鸣」，分别袭向$n的两处要害，使$n防不胜防！",
                "damage":               300,
                "dodge":                100,
                "parry":                200,
                "damage_type":  "挫伤"
        ]),
});

int valid_learn(object me)
{	
	object weapon;
        if( (int)me->query("str") < 35 )
                return notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");
	 if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("以你目前的状况，还没有资格练这门功夫。\n");

	
	 if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "staff" )
                return notify_fail("你必须先找一根木杖或者是类似的武器，才能练棍法。\n");

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

int practice_skill(object me)
{
        object weapon;

        if(me->query("TASK")<1000||(string)me->query("class")!="zhuge")
		return notify_fail("以你目前的状况，还没有资格练棍法。\n");
	if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "staff" )
                return 
		notify_fail("你必须先找一根木杖或者是类似的武器，才能练棍法。\n");

        if( (int)me->query("kee") < 60 )
                return 
		notify_fail("你的体力不够练这门棍法，还是先休息休息吧。\n");
        me->receive_damage("kee", 60);
        return 1;
}
int effective_level() { return 22;}
 
string *parry_msg = ({
        "$n使出一招「浪子无崖」手中$v朝$w挡去，格开了$N的$w。\n",
	"$n手中$v一短，一招「天罡护体」，荡开了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n身形徐徐后退，手中$v抡动，封住了$N的攻势。\n",
	"$n身形直挺挺扑到在地，手中$v径自扫向$N。\n",
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
	return -20;
}
int practice_bonus()
{
	return -10;
}
int black_white_ness()
{
	return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("zhuge") + "/chaotian-stick/" + action;
}

