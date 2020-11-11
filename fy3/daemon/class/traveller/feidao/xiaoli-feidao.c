#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("小李飞刀只能对战斗中的对手使用。\n");
        if((int) me->query_skill("feidao",1) <= 200)
                return notify_fail("你的飞刀绝技还不够精纯，不能发出小李飞刀。\n");

        message_vision(RED"$N目不转睛地盯着$n，准备发出致命一击。\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(3)+3);
        me->start_busy(5);
        return 1;
}
void kill_him(object me, object target)
{
        string msg;
if(me->query("class")=="traveller" && me->is_fighting() && target->is_fighting() && environment(me) == environment(target))
        {
msg = HIY "$N使出飞刀绝技中例无虚发的" + HIR "小李飞刀" +HIY "，$n只觉得眼前一花，咽喉已被对穿而过！！！" ;
msg +=  "\n一股血箭喷涌而出．．$n的眼睛死鱼般的突了出来．．\n" NOR;

        message_vision(msg, me, target);
                target->die();
        }
else{
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
msg = HIY "$N使出飞刀绝技中例无虚发的" + HIR "小李飞刀" +HIY "，$n只觉得眼前一花，咽喉已被$w对穿而过！！！" ;
msg +=  "\n一股血箭喷涌而出．．$n的眼睛死鱼般的突了出来．．\n" NOR;

        message_vision(msg, me, target);
//                target->die()
                target->add("kee",-me->query("kee")/2);
        }
}
        return ;
}

