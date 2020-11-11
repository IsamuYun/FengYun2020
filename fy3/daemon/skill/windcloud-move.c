// yiru@hero
// windcloud-move.c
// 仙风云体术

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
        "但是$n身形飘忽，轻轻一纵，一招「仙风飞云」，轻而易举的避开这一击。\n",
        "$n身形突转，一式「金蝉脱壳」，抽身窜开了数尺。\n",
        "$n身形往上拔起，一招「御剑飞仙」，一个转折落在数尺之外。\n",
            "$n一招「天仙下凡」，身体如薄云一般，$N有力无处使。\n",
            "只见$n身影一晃，一式「云中漫步」早已避在七尺之外。\n",
                "可是$n使一招「云静风轻」，身子轻轻飘了开去。\n"
});

int valid_enable(string usage)
{
    return (usage=="dodge") || (usage=="move") || (usage=="magic");
}

void skill_improved(object me)
{
    int sk=me->query_skill("windcloud-move", 1);
        if( sk >= 120) {
        if ( (string) me->query_skill_mapped("dodge") == "windcloud-move") return;
                tell_object(me, 
             HIW "由于你仙风云体术的进步，你学会了利用仙风云体术闪躲！\n" NOR );
            me->map_skill("dodge","windcloud-move");
        }
}

int valid_learn(object me)
{
    object ob;
    int sk = me->query_skill("windcloud-move", 1);

        if( (int)me->query_skill("incarnation",1) < sk )
                return notify_fail("你的仙术修为不够，没有办法练仙风云体术。\n");

        if( (string)me->query_skill_mapped("force")!= "incarnate-body")
                return notify_fail("仙风云体术必须配合仙风道骨作为内功才能练。\n");

    if( me->query("family/family_name")!="蜀山剑派" )
        return notify_fail("仙风云体术只可以传授给本门弟子。\n");
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
    int sk = me->query_skill("windcloud-move", 1);
        if( (sk >= 120) && ( (string)me->query_skill_mapped("dodge") != "windcloud-move") ){
                tell_object(me, 
             HIW "由于你仙风云体术的进步，你学会了将仙风云体术用于闪躲！\n" NOR );
            me->map_skill("dodge","windcloud-move");
        }

    if(me->query_skill("windcloud-move")>=120)
            return notify_fail("仙风云体术到了这个地步只能从学习中提高。\n");

        if( (int)me->query("atman") < 12 )
                return notify_fail("你的灵力不够了，不能练仙风云体术。\n");
        me->add("atman", -12);
        return 1;
}

int effective_level() { return 21;}

int learn_bonus()
{
        return 120;
}
int practice_bonus()
{
        return 12;
}
int black_white_ness()
{
        return 12;
}

string perform_action_file(string action)
{
        return CLASS_D("xianren") + "/pal-steps/" + action;
}

string conjure_magic_file(string action)
{
        return CLASS_D("xianren") + "/pal-steps/" + action;
}
