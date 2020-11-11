#include <ansi.h>
inherit FORCE;
mapping *action = ({
        ([      "action":
"$N使出一招「呆手呆脚」，手脚并用胡乱击向$n的$l",
                "force":        30,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「呆头呆脑」，头一摆笔直撞向$n的$l",
                "force":        40,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「呆气十足」，不管自身防备，挺胸抡向$n的$l",
                "force":        50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「呆瓜拜寿」，全身扑腾向地，姿势煞是难看，硬要以手捞$n的双脚",
                "force":         60,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「呆子相亲」，双手抱向$n的$l",
                "force":        40,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出一招「呆鸡打鸣」，脖子一伸，嘴巴一张，咬向$n的$l",
                "force":        50,
                "damage_type":  "瘀伤"
        ]),
});

int valid_enable(string usage) 
{ 
return  usage=="unarmed" ||
        usage=="force";
}

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("发呆神功只需要发呆就可以了。\n");
}

 
int effective_level() { return 30;}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
string *unarmed_parry_msg = ({
        "$n慌慌张张，就地乱滚，跌跌撞撞的躲开了$N的攻击。\n",
        "$n惊吓不已，双手乱挥，险险挡住了$N的攻势。\n",
});
string *parry_msg = ({
        "$n慌慌张张，就地乱滚，跌跌撞撞的躲开了$N的攻击。\n",
        "$n惊吓不已，双手乱挥，险险挡住了$N的攻势。\n",
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
        return 10;
}

int learn_bonus()
{
        return -50000;
}
int practice_bonus()
{
        return 0;
}

int black_white_ness()
{
        return 0;
}

string exert_function_file(string func)
{
        return CLASS_D("player") + "/idle-force/" + func;
}
string perform_action_file(string action)
{
        return CLASS_D("player") + "/idle-force/" + action;
}


void skill_improved(object me)
{
        if( (int)me->query_skill("idle-force", 1)  > 1000 ) 
        {
                tell_object(me, HIW "\n你的发呆神功再也无法进步了！\n\n" NOR);
                                me->set_skill("idle-force", 1000);
        } 
}
string belong()
{
	return "common";
}
