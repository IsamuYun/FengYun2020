#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        "$n身形不定,轻轻巧巧地绕着$N转了个圈子,使出一招" + HIC "「洛神凌波」" NOR + "，$N的招式尽数落空。\n",
        "$n对$N微微一笑,$N一怔之下,$n已经绕到了$N的身后,用的正是" + HIW "「一笑倾国」" NOR + "。\n",
        "$n使一招"+ HIR "「贵妃醉酒」" NOR + ",身形左右一晃,$N眼前一花,$n的身影已经不见踪迹。\n",
        "$n身形一变,快捷无伦的三个起伏,一招" + HIY "「红拂夜奔」" NOR + "用得天衣无缝。\n",
        "可是$n使一招"+ HIM "「迷离靓影」" NOR +"，步法飘忽不定，$N的攻击失去了准头。\n",
        "$n向上一拔,突然变招下坠,一式"+ HIG "「绿珠坠楼」" NOR + "令$N的攻击全盘落空。\n",

});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法学习玉女身法。\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的气或内力不够，不能练玉女身法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

int effective_level() { return 25;}

int learn_bonus()
{
        return -90;
}
int practice_bonus()
{
        return -50;
}
int black_white_ness()
{
        return 40;
}

string perform_action_file(string action)
{
        return CLASS_D("wudujiao") + "/dodge/" + action;
}