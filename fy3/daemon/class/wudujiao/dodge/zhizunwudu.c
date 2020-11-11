// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        extra = me->query_skill("wudu-steps",1);
        if ( extra < 30) return notify_fail("你的［五毒步法］还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［至尊五毒］只能对战斗中的对手使用。\n");
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");
        message_vision("$N脚踩怪异方位，在$n眼前幻出万道身影！\n",me,target);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
        {

        message_vision("结果$N被扰得眼花潦乱，不知所措！\n",target);
        target->start_busy(3);
        me->start_busy(1);
        }
        else{
        message_vision("但$n看透了$N的企图，不为情形所动！\n",me);
        me->start_busy(2);
        }
        return 1;
}