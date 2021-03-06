inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N猛喝一声,聚起全身功力,双手拇指一并,一股炽热刚猛的剑气如炮弹般射向$n$l，刹时间无数迅雷疾风，相互冲撞激,威不可当",
                "dodge":                -30,
                "parry":                30,
                "force":                80,
                "damage_type":  "刺伤",
                "weapon":               "刚猛的剑气",
        ]),
        ([      "action":               
"$N默运真气,左手虚指，右手一挥「商阳剑」刺向$n的$l",
                "dodge":                -30,
                "parry":                30,
                "force":                60,
                "damage_type":  "刺伤",
                "weapon":               "两道剑气",
        ]),
        ([      "action":               

"$N身法忽然加快,右手「少冲剑」连点把$n的退路全部封杀，左手「少泽剑」急按$n的$l",
                "dodge":                -30,
                "parry":                30,
                "force":                70,
                "damage_type":  "刺伤",
                "weapon":               "一缕指风",
        ]),
        ([      "action":               
"$N真气急运九大周天,全身真气充盈,不吐不快,右手「少泽剑」、「少冲剑」、「少商剑」一起刺向$n的$l",
                "dodge":                -30,
                "parry":                30,
                "force":                140,
                "damage_type":  "刺伤",
                "weapon":               "数道剑气",
        ]),
        ([      "action":               
"$N右手拇指连点,使出「少商剑」,指端真气激荡，如虚如幻地刺至$n的$l",
                "dodge":                -30,
                "parry":                30,
                "force":                90,

                "damage_type":  "刺伤",
                "weapon":               "一道剑气",
        ]),
        ([      "action":               
"$N大喝一声,拇指一扬丹田真气汹涌而至，使出「少商剑」捺向$n的$l，刹时间剑气纵横，便似有无数迅雷疾风相互冲撞激",
                "dodge":                -30,
                "parry":                30,
                "force":                100,
                "damage_type":  "刺伤",
                "weapon":               "数道剑气",
        ]),      
});

int valid_learn(object me) 
{
        int extra;
   //     if( (string)me->query("gender") != "男性" )
   //             return notify_fail("六脉神剑是只有男子才能练的武功。\n");
        extra = me->query_skill("duan-yiyangzhi",1);
        if ( extra < 220) 

                return notify_fail("你的段氏一阳指还不够纯熟，无法学习六脉神剑！\n");
        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("六脉神剑必须空手。\n");
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

        if( (int)me->query("sen") < 30 )
                return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("你的内力不够了。\n");

        me->receive_damage("sen", 30);
        me->add("force", -10);

        return 1;
}
 
 int effective_level() { return 40;}

string *parry_msg = ({
        "$n一招「少泽剑」，急出一指，一道劲风悄无声息的点歪了$N的$w。\n",
        "$n神色悠闲，一招「商阳剑」，倏地一指递出，一条刚劲的剑气点向$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n并起二指，踏步挺身，「少冲剑」、「中冲剑」带着凛凛指风封住$N的周身大穴。\n",

        "$n身形蓦地消逝，一招「少商剑」，一指剑气，把$N逼得连连后退。\n",
        "$n化出无数身影，一招「关冲剑」猛的挥出一指，一道剑气点向$N。\n",
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
        return -100;
}
int practice_bonus()
{
        return -100;
}

int black_white_ness()
{
        return 50;
}

string perform_action_file(string action)
{
        return CLASS_D("dali") + "/unarmed/" + action;
}
