// counterattack.c

#include <ansi.h>

inherit SSERVER;
void surekill(object me, object target);
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("[一气贯日月]只能对战斗中的对手使用。\n");
        if((int) me->query_skill("yiqiguanforce",1) < 1000)
                return notify_fail("你的[日月神功]还不够精纯，不能发出[一气贯日月]。\n");

        message_vision(RED"$N看着$n，无精打睬的向$n随手挥了一下。\n"NOR,me,target);
msg = HIY "$N使出[一气贯日月]，$n只觉得眼前一花，全身经脉皆断！！！" ;
msg +=  "\n一股血箭从口中喷涌而出．．$n临死前还不相信世上竟有此等功夫．．\n" NOR;

        message_vision(msg, me, target);
                target->die();
        return 1;
}

