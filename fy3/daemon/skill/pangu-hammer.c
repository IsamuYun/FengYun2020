// cloudstaff.c

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N左手化出一个圆圈，右手中的$w一招［威镇四方］向$n的$l挥去！",
                "force":               700,
                "dodge":                600,
                "parry":                200,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N一弹手中的$w，一招［气盖山河］，手中的$w向$n的$l雷霆般地砸下。",
                "damage":               150,
                "dodge":                400,
                "parry":                400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N暴喝一声，腾空飞起，以泰山压顶之式扑下，手中的$w带着轰轰雷声一招［千钧一发］击向$n的$l。",

                "damage":               70,
		"force" :		200,
                "dodge":                500,
                "parry":                700,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":               
"$N手中的$w一转，一招［狂风暴雨］从四面八方盖向$n的$l",
                "damage":               40,
		"force" :		200,
                "dodge":                100,
                "parry":                400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
        ([      "action":
"$N一抖手中的$w，一招［夏日狂阳］幻出一片刀光剑影，虚虚实实的挥向$n的$l",
                "force":               100,
		"damage" : 		50,
                "dodge":                100,
                "parry":                400,
                "post_action":  (: call_other, WEAPON_D, "bash_weapon" :),
                "damage_type":  "挫伤"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("level") < 40 )
                return 
notify_fail("你的等级还不够学习盘古九式。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="hammer");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   return notify_fail("盘古九式只能通过向师傅学习来提升。\n");
}
int effective_level() { return 20;}
 
string *parry_msg = ({
        "$n后退一步，一招［荡气回肠］手中的$v猛的砸向$N的$w。\n",
	"$n身形微顿，手中的$v一招［围韩救赵］反捣$N的必救之处。\n",
	"$n手中的$v从下往上急挥，一招［恶鬼还阳］磕开了$N手中的$w\n",
});

string *unarmed_parry_msg = ({
	"$n一招［钟鼓齐鸣］，手中的$v从偏锋击向$N的太阳大穴。\n",
	"$n手中的$v从左划右，一招［横扫千军］封住了$N的攻势。\n",
	"$n凌空三连翻，一招［披沙拣金］手中的$v反击$N的后脑，逼得$N中途撤招。\n",
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
	return 50;
}
int practice_bonus()
{
	return -100;
}
int black_white_ness()
{
	return 10;
}
string perform_action_file(string action)
{
        return CLASS_D("tianchui") + "/pangu-hammer/" + action;
}

string belong()
{
	return "tianchui";
}


