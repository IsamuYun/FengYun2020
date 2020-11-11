#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":               
HIC"$N使出飞燕三式中的最后一式［天厥燕回巢］，手中的$w"+HIC+"闪电般直刺$n"+HIC+"的$l！"NOR,
                "force" :               90,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
HIC"$N使出飞燕三式中的第一式［燕子冲天飞］，手中的$w"+HIC+"闪电般直刺$n"+HIC"的$l！"NOR,
                "force":               100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
HIC"$N使出飞燕三式中的第二式［南山白燕落］，手中的$w"+HIC+"闪电般直刺$n"+HIC+"的$l！"NOR,
                "force":               120,
                "damage_type":  "割伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力不够，没有办法练飞燕三式。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 200
        ||      (int)me->query("force") < 300 )
                return 
notify_fail("你的内力或气不够，没有办法练习飞燕三式。\n");
        me->receive_damage("kee", 150);
        me->add("force", -200);
        write("你按著所学练了一遍飞燕三式。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("yihua") + "/feiyan-shenjian/" + action;
}
 
int effective_level() { return 25;}

string *parry_msg = ({
        "$n随风轻轻飘落，手中$v平指，缓缓拍向$N脸颊，\n",
        "$n随意挥洒， 轻而易举的架住了$N的$w。\n",
        "$n深吸一口气，手中的$v化作千百剑芒，护住了全身。\n",
        "$n手中的$v急剧抖动，封住了$N的所有攻势。\n",
});

string *unarmed_parry_msg = ({
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
        return 100;
}
int practice_bonus()
{
        return 150;
}
int black_white_ness()
{
        return 50;
}