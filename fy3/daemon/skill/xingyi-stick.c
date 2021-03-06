// TIE@FY3
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N使出一招「鹰击长空」，身形腾空而起，手中$w挂定风声，向$n的$l狠狠砸去！",
                "damage":               40,
                "dodge":                40,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]), 
        ([      "action":               
"$N使出一招「云龙三现」，手中$w挽出团团雪花，三隐三现，棍棍不离$n的$l！",
                "damage":               40,
                "dodge":                20,
                "parry":                60,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w一振，一招「丹凤朝阳」，立现满天$w，棍棍直指$n的$l！",
                "damage":               80,
                "dodge":                10,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w抡动，过处带起阵阵啸声，一招「虎啸龙吟」，直奔$n的$l打去！",
                "damage":               200,
                "dodge":                -110,
                "parry":                -40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w一晃，竟幻然为双，一招「彩凤双鸣」，分别袭向$n的两处要害！",
                "damage":               10,
                "dodge":                100,
                "parry":                200,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N身形连转，手中$w一招「怪蟒翻身」，连连向$n的$l扫去！",
                "damage":               20,
                "dodge":                10,
                "parry":                20,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N身形窜起，手中$w一招「一鹤冲天」，直上直下地戳向$n的$l！",
                "damage":               100,
                "dodge":                -10,
                "parry":                20,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N身行一顿，手中$w斜出一招「白猿献寿」，挑向$n的$l！",
                "damage":               50,
                "dodge":                10,
                "parry":                20,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中$w舞动，化出满天棍影，一招「百鸟朝凤」竟从各个角度同时打向$n的$l！",
                "damage":               50,
                "dodge":                200,
                "parry":                200,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N使出一招「猛虎下山」身形跃起，手中$w自上而下，呼地砸向$n的$l！",
                "damage":               90,
                "dodge":                30,
                "parry":                50,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),


});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 35 )
                return 
notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");

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
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n使出一招「豹子摇头」手中$v摆开，格开了$N的$w。\n",
	"$n手中$v横摆，一招「白虎探爪」，荡开了$N的$w。\n",
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
        return CLASS_D("shaolin") + "/xingyi-stick/" + action;
}

