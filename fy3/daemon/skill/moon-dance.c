#include <ansi.h>
inherit SKILL;
mapping *action = ({
        ([      "action":
"$N使出一招「惊天变」，天崩地裂，手中$w闪电般击向$n的$l",
		"damage":		3000,
		"dodge":		500,
		"parry":		500,	
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「仙魔乱」，心摇神驰，$w幻出重重诡异之景袭向$n的$l",
		"damage":		5000,
		"dodge":		1000,
		"parry":		1000,	
                "damage_type":  "瘀伤"
        ]),
	([ 	"action":
"$N使出一招「鬼神泣」，鬼哭神嚎，层层凄厉伤神的幻音围绕在$n的耳边",
		"damage":		7000,
		"dodge":		1500,
		"parry":		1500,	
                "damage_type":  "瘀伤"
        ]),
	([	"action":
"$N使出一招「翻江海」，翻江倒海，空气似被无限挤压，一波接一波冲向$n的$l",
		"damage":		9000,
		"dodge":		2000,
		"parry":		2000,	
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「换天地」，改天换地，手中$w忽左忽右，忽上忽下，飘忽不定击向$n的$l",
		"damage":		3000,
		"dodge":		500,
		"parry":		500,	
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「日月暗」，日月无光，全身腾空而起，手中$w抖得笔直猛然攻向$n的$l",
		"damage":		5000,
		"dodge":		1000,
		"parry":		1000,	
                "damage_type":  "瘀伤"
        ]),
	([ 	"action":
"$N使出一招「血漫天」，血色漫天，$w聚起的杀气犹如实质般击向$n的$l",
		"damage":		7000,
		"dodge":		1500,
		"parry":		1500,	
                "damage_type":  "瘀伤"
        ]),
	([	"action":
"$N使出一招「裂乾坤」，地动山摇，$w劲气凝于一点，风驰电掣般击向$n的$l",
		"damage":		9000,
		"dodge":		2000,
		"parry":		2000,	
                "damage_type":  "瘀伤"
        ]),
});

int valid_enable(string usage) 
{ 
return 	(usage=="whip") || (usage=="force");
}

int valid_learn(object me)
{
	object ob;
    
    if( (int)me->query_spi() < 80 )
        return notify_fail("你的灵性太差了，无法学习这门武功。\n");

    if( (int)me->query_int() < 80 )
        return notify_fail("你的才智太低了，无法学习这门武功。\n");

    if( (int)me->query("spi")*3 < me->query_skill("moon-dance",1) )
        return notify_fail("你的灵性太低了，无法继续领悟这门武功。\n");

    if( (int)me->query_skill("force",1)/2 < me->query_skill("moon-dance",1) )
        return notify_fail("你的内功心法太差了，无法继续领悟这门武功。\n");

    if( (int)me->query("max_force") < 2500 || (int)me->query("force") < 2500 )
        return notify_fail("你的内力不足，没有办法练水月神舞, 多练些内力再来吧。\n");

	if( !(ob = me->query_temp("weapon"))
		||	(string)ob->query("skill_type") != "whip" )
		return notify_fail("你必须先找一条鞭子才能练水月神舞。\n");

    if( me->query("family/family_name")!="仙灵岛" )
        return notify_fail("非仙灵岛水月宫弟子无法学此武功。\n");
    
    return 1;
}

int practice_skill(object me)
{
        return 
notify_fail("水月神舞只能用学的。\n");
}

 
int effective_level() { return 58;}

string *parry_msg = ({
        HIW"$n施展出「水月神舞」，轻描淡写的化解了$N的攻势。\n"NOR,
        HIW"$n急速旋转，手中的$v幻化出九重鞭影，$N顿时不知从何处攻击。\n"NOR,
});

string query_parry_msg(object weapon)
{
    return parry_msg[random(sizeof(parry_msg))];
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string *absorb_msg = ({
        HIC"$n身型微展，天地人合一，释放水月神舞护体仙气。\n"NOR,
        HIC"$n身体急转，全身内劲化作仙灵之气澎湃而出。\n"NOR,
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
    return 80;
}

int learn_bonus()
{
        return -6800;
}
int practice_bonus()
{
        return -6800;
}
int black_white_ness()
{
        return 200;
}

string perform_action_file(string action)
{
        return CLASS_D("xianlingdao") + "/moon-dance/" + action;
}

string exert_function_file(string func)
{
        return CLASS_D("xianlingdao") + "/moon-dance/" + func;
}
