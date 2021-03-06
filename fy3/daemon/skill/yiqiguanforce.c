#include <ansi.h>
inherit FORCE;
mapping *action = ({
        ([      "action":
"$N使出一招「气冠冲天」，左手聚出一团日月击向$n的$l",
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「力拔山兮」，右手聚出一团日月击向$n的$l",
                "force":                250,
                "damage_type":  "瘀伤"
        ]),
	([ 	"action":
"$N使出一招「日月相照」，双手聚出一团日月击向$n的$l",
                "force":                350,
                "damage_type":  "瘀伤"
        ]),
	([	"action":
"$N使出一招「月在九天」，全身腾空而起，全身化作一团日月击向$n的$l",
                "force":                450,
                "damage_type":  "瘀伤"
        ]),
});
/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        mixed foo;
	int force;

        foo = ::hit_ob(me, victim, damage_bonus, factor);
        if( intp(foo) && (damage_bonus + foo > 0) ) {
                if( random(2*(me->query_skill("yiqiguanforce"))) > (damage_bonus + foo))
 {
                        victim->receive_wound("kee", (damage_bonus + foo));
                        victim->receive_wound("gin", (damage_bonus + foo));
                        victim->receive_wound("sen", (damage_bonus + foo));
			force = victim->query("force");
			victim->set("force", force-random(10)-1);
			victim->set("max_force", 0);
                        return
"$N的日月神功摧毁了$n的五脏六肺！！！！\n";
                }
        }
        return foo;
}
*/
int valid_enable(string usage) 
{ 
return 	usage=="iron-cloth" ||
	usage=="unarmed" ||
       usage=="force"; 
}

int valid_learn(object me) 
{
if ( me->query_skill("bolomiduo",1)
	|| me->query_skill("cloudforce",1)
	|| me->query_skill("cloudsforce",1)
	|| me->query_skill("dachengforce",1)
	|| me->query_skill("damoforce",1)
	|| me->query_skill("demon-force",1)
	|| me->query_skill("doomforce",1)
	|| me->query_skill("ghost-force",1)
	|| me->query_skill("gouyee",1)
	|| me->query_skill("huntunforce",1)
	|| me->query_skill("iceforce",1)
	|| me->query_skill("iceheart",1)
	|| me->query_skill("jiayiforce",1) 
       || me->query_skill("jingxing",1)
	|| me->query_skill("jingyiforce",1)
	|| me->query_skill("lotusforce",1)
	|| me->query_skill("manjianghong",1)
	|| me->query_skill("mystforce",1)
	|| me->query_skill("nine-moon-force",1)
	|| me->query_skill("noloveforce",1)
	|| me->query_skill("qidaoforce",1)
	|| me->query_skill("taijiforce",1)
	|| me->query_skill("tangforce",1)
	|| me->query_skill("vivienforce",1)
	|| me->query_skill("wuchenforce",1)
|| me->query_skill("xiaochengforce",1)
	|| me->query_skill("yiqiforce",1)
	
	|| me->query_skill("zixia-shengong",1))
	

		return notify_fail("你不先废了别派内功，怎能学日月神功？！\n");
 return 1; }

int practice_skill(object me)
{
        return 
notify_fail("日月神功只能用学的。\n");
}

 
int effective_level() { return 50;}

string *absorb_msg = ({
        "$n身体虚转，双手微划，无坚不摧的日月功澎湃而出。\n",
        "$n施展出日月功，浑身肌肤坚如寒铁。\n",
        "$n身型微展，日月充斥了丈许空间。\n",
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string *unarmed_parry_msg = ({
        "$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",
        "$n长袖一甩，一股大力将$N送出丈外。\n",
        "$n施展出「日月为伴」，轻描淡写的化解了$N的攻势。\n",
});
string *parry_msg = ({
        "$n衣衫澎湃，内力汩汩，$N根本不可近身。\n",
        "$n长袖一甩，一股大力将$N送出丈外。\n",
        "$n施展出「日月为伴」，轻描淡写的化解了$N的攻势。\n",
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
        return 20;
}

int learn_bonus()
{
	return -5000;
}
int practice_bonus()
{
	return -5000;
}
int black_white_ness()
{
	return 200;
}
string exert_function_file(string func)
{
        return CLASS_D("xianren") + "/yiqiguanforce/" + func;
}

string perform_action_file(string action)
{
        return CLASS_D("xianren") + "/yiqiguanforce/" + action;
}
