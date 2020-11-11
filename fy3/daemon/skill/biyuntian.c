#include <ansi.h>
inherit FORCE;
mapping *action = ({
                        ([      "action":               
                                        "$N使出一招「邪云蔽日」，身形一纵，双掌自上而下，拍向$n的$l",
                                "dodge":                250,
                                "parry":                250,
                                "force":                200,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                                        "$N使出一招「云映血空」，双掌一分，直切$n的$l",
                                "dodge":                200,
                                "parry":                200,
                                "force":                270,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                                        "$N使出一招「碧色妖邪」，掌掌不离$n的$l",
                                "dodge":                300,
                                "parry":                300,
                                "force":                250,
                           "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                                        "$N双掌一错，一掌虚晃，使出「云雾魔影」，对准$n的$l单掌斜劈",
                                "dodge":                400,
                                "parry":                500,
                                "force":                350,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                                        "$N身形忽左忽右，双掌齐挥，使出「鬼舞妖动」，袭向$n$l",
                                "dodge":                300,
                                "parry":                300,
                                "force":                240,
                                "damage_type":  "瘀伤"
                        ]),
                        ([      "action":               
                                        "$N使出「暗日红云」，急挥双掌，从空中当头向$n的$l出掌攻击",
                                "dodge":                500,
                                "parry":                600,
                                "force":                350,
                                "damage_type":  "瘀伤"
                        ]),
                ([      "action":               "$N使一招「鬼影藏月」，对准$n的$l「呼」地一拳",
                        "force":                350,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N扬起拳头，一招「冷血坟山」便往$n的$l招呼过去",
                        "force":                450,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N左手虚晃，右拳「死气延延」往$n的$l击出",
                        "force":                550,
                        "damage_type":  "瘀伤"
                ]),
                ([      "action":               "$N步履一沉，目露血光，双拳使出「血吟魔天」击向$n$l",
                        "force":                650,
                        "damage_type":  "瘀伤"
                ]),
});

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int lev = 0;
	int a1 = 0;
	int a2 = 0;
	int pro = 0;

	lev = me->query_skill("biyuntian",1);
	if(lev < 50)
	{
		return ("");	
	}

	a1 = (int)victim->query("int");
	a2 = (int)victim->query("spi");	
	
	pro = a1+a2-lev;
	if(pro < 4)
	{
		pro = 4;	
	}
	
	if(!random(pro))
	{
		victim->apply_condition("demon",1+(a1+a2+lev)/30);
		return (HIW"$n"NOR+HIW"的心魔被碧云天引发了!\n" NOR);
	}
	
	return ("");
}

int valid_enable(string usage) 
{ 
return 	usage=="parry" ||
	usage=="unarmed" ||
	usage=="force";
}

int valid_learn(object me)
{
        if( (int)me->query("int") < 30 )
                return notify_fail("你的才智太低,学不了碧云天。\n");

        if( (int)me->query("spi") < 30 )
                return notify_fail("你的灵性太低,学不了碧云天。\n");

        if ((int)me->query_skill("force", 1) < 100) 
        {
                return notify_fail("你的基本内功火候太浅。\n");
        }
	return 1;
}

int practice_skill(object me)
{
        return notify_fail("碧云天只能用学的。\n");
}

 
int effective_level() { return 20;}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string *unarmed_parry_msg = ({
        "$n使出一招「妖夜回廊」，贴身急进，将$N的双手牢牢锁住。\n",
        "$n掌势层层，一招「阴风四起」拍向$N的双手。\n",
        "$n使出「怨魂游天」，双掌一划，引偏了$N的攻势。\n",
        "$n一招「神魔一线」，猛击$N的面门，逼得$N中途撤招。\n",
        "$n右拳虚幌，左拳一招「鬼哭神嚎」，逼得$N后退三步。\n",
        "$n以守为攻，一招「邪魔歪道」，猛击$N的手腕。\n",
});
string *parry_msg = ({
        "$n使出一招「妖夜回廊」，贴身急进，将$N的$w牢牢锁住。\n",
        "$n掌势层层，一招「阴风四起」拍向$N拿着$w的手。\n",
        "$n使出「怨魂游天」，双掌一划，引偏了$N的$w。\n",
        "$n一招「神魔一线」，猛击$N的面门，逼得$N中途撤回手中的$w。\n",
        "$n右拳虚幌，左拳一招「鬼哭神嚎」，逼得$N后退三步。\n",
        "$n以守为攻，一招「邪魔歪道」，猛击$N握$w的手腕。\n",
});
string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
int bounce_ratio()
{
	return 40;
}

int learn_bonus()
{
	return -1000;
}
int practice_bonus()
{
	return -1000;
}
int black_white_ness()
{
	return 200;
}
string exert_function_file(string func)
{
        return CLASS_D("huashan") + "/biyuntian/" + func;
}

string perform_action_file(string action)
{
        return CLASS_D("huashan") + "/biyuntian/" + action;
}
void skill_improved(object me)
{
	int lev = 0;
	int a1 = 0;
	int a2 = 0;
	int exp = 0;
	
	lev = me->query_skill("biyuntian",1);
	a1 = (int)me->query("int");
	a2 = (int)me->query("spi");
	exp = (int)me->query("combat_exp");
	
	if(!random(a1/30+a2/30+lev/15))
	{
		if(lev > 1)
		{
			me->set_skill("biyuntian", lev-1);
		}
		me->apply_condition("demon",a1/30+a2/30+lev/15);
	}
}

