// TIE@FY3
inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N脸上露出诡异的笑容，隐隐泛出绿色的双掌扫向$n的$l！",
                "damage":               40,
                "dodge":                40,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "瘀伤"
        ]), 
        ([      "action":               
"$N突然身形旋转起来扑向$n，双掌飞舞着拍向$n的$l！",
                "damage":               40,
                "dodge":                20,
                "parry":                60,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N将内力运至右手，一招「晴天蓝」大力抓向$n的$l！",
                "damage":               80,
                "dodge":                10,
                "parry":                40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌挟着一股腥臭之气拍向$n的$l！",
                "damage":               200,
                "dodge":                -110,
                "parry":                -40,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N气凝如山，一式「金戈铁马」，双拳蓄势而发，击向$n的$l！",
                "damage":               10,
                "dodge":                100,
                "parry":                200,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N身形凝重，劲发腰背，一式「木已成舟」，缓缓向$n推出！",
                "damage":               20,
                "dodge":                10,
                "parry":                20,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N步伐轻灵，两臂伸舒如鞭，一式「水中捞月」，令$n无可躲闪",
                "damage":               100,
                "dodge":                -10,
                "parry":                20,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "瘀伤"
        ]),


});

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
	return notify_fail("练流氓神拳必须空手。\n");
if ((int)me->query_skill("wuchenforce", 1) < 20)
		return notify_fail("你的无尘心法火候不够，无法练流氓神拳。\n");
if( (int)me->query("str") + (int)me->query("max_force") / 100 < 35 )
                return 
notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}

mapping query_action(object me)
{
        if (random(me->query_skill("unarmed")) > 100 &&
            me->query_skill("wuchenforce") > 70 &&
            me->query("force") > 100 ) {
                me->add("force", -100);
                return ([
                "action": "$N一个翻身，跃出数丈，左手画圆，右手画方，聚集全身的力量击向$n",
                "force": 500,
                "damage_type": "瘀伤"]);
        }
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
         if( (int)me->query("kee") < 30 )
                return 
notify_fail("你的体力不够练这门拳法，还是先休息休息吧。\n");
        me->receive_damage("kee", 30);
        return 1;
}
int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n一式「烈火锥」，双掌轮流下击，拳势如焰，格开了$N的兵器。\n",
	"$n腾空飞起，一式「八方雨」，双手双腿齐出,荡开了$N的兵器。\n",
});

string *unarmed_parry_msg = ({
 "$n一式「烈火锥」，双掌轮流下击，拳势如焰，格开了$N的兵器。\n",
	"$n腾空飞起，一式「八方雨」，双手双腿齐出,荡开了$N的兵器。\n",
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
        return -1000;
}
int practice_bonus()
{
        return -1000;
}
int black_white_ness()
{
        return 600;
}

string perform_action_file(string action)
{
        return CLASS_D("quanli") + "/liumang-strike/" + action;
}

