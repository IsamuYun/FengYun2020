// 黑苗内功
// fire-force 赤血毒焰

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage)
{
    return     (usage=="iron-cloth") || (usage=="force");
}

int valid_learn(object me)
{
   
    if( me->query("max_force") < me->query_skill("force",1)*5 )
        return notify_fail("你的内力太差了，强练无益！\n");

    if( me->query("max_force") < me->query_skill("fire-force",1)*15 )
        tell_object(me,
        HIY "在修炼的过程中，你已经开始感到内力不足，似乎再练下去可能走火入魔。\n" NOR);
    return 1;
}

int practice_skill(object me)
{
    return 0;
}

int effective_level() { return 20;}

string *absorb_msg = ({
        HIC"$n身体虚转，双手微划，全身内劲如毒焰般澎湃而出。\n"NOR,
        HIC"$n身型微展，全身赤红，浑身肌肤射出骇人的毒焰。\n"NOR,
});

string query_absorb_msg()
{
        return absorb_msg[random(sizeof(absorb_msg))];
}

int bounce_ratio()
{
    return 20;
}

int learn_bonus()
{
    return -5300;
}
int practice_bonus()
{
    return -5300;
}
int black_white_ness()
{
    return 200;
}
string exert_function_file(string func)
{
    return CLASS_D("heimiao") + "/fire-force/" + func;
}

string perform_action_file(string action)
{
    return CLASS_D("heimiao") + "/fire-force/" + action;
}

void skill_improved(object me)
{
    int force;
    if( me->query("max_force") > me->query_skill("force",1)*5+me->query_skill("force")*3/2 ) {
        tell_object(me, HIY "\n你发觉内力高涨得憋不过气来，急着要将内力逼出。\n\n" NOR);
        me->add("max_force",-me->query_skill("force",1));
        me->unconcious();
    }
    if( me->query("max_force") < random(me->query_skill("fire-force",1)*15) ) {
        tell_object(me, HIR "\n你突然全身发麻！走火入魔了！！....\n\n" NOR);
        me->skill_death_penalty();
        me->delete_skill("fire-force");
        me->unconcious();
    }
}
