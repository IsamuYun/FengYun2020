// mouse@skills
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        extra = me->query_skill("lingbo-steps",1);
        if ( extra < 80) return notify_fail("你的［凌波微步］还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［飘逸神仙］只能对战斗中的对手使用。\n");
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");
        message_vision( HIG "$N施展凌波微步中的绝学" + HIR "［飘逸神仙］"NOR+ HIG "，左一转，右一斜，幻出重重身影！\n" NOR,me);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
        {

        message_vision(HIC "\n $N只觉得眼前一花，四面全是$n身影！！\n" NOR,target,me);
        target->start_busy(4);
        }
        else{
        message_vision(HIC "\n  结果并没奏效！！\n" NOR,me);
        me->start_busy(1);
        }
        return 1;
}