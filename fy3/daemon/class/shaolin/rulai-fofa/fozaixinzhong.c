#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("佛在心中只能对战斗中的对手使用。\n");
             if(me->query("family/family_name") != "少林寺")
                return notify_fail("你不是少林弟子不能使用佛在心中！\n");
                    if((int) me->query_skill("rulai-fofa",1) <= 200)
                return notify_fail("你的如来佛法还不够精纯，不能使出佛在心中。\n");
        message_vision( BBLU HIY"$N双手合十，静心闭目，准备向$n诵出--佛在心中--\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(3)+3);
        me->start_busy(5);
        return 1;
}
void kill_him(object me, object target)
{
        string msg;
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
msg =BBLU HIY "$N向$n诵出" + HIR "佛在心中" +HIY "，$n只觉一片祥和之气笼罩着全身！" ;
msg +=  "\n$n的心中的心魔被佛法驱散了，人如大获全释!\n" NOR;

        message_vision(msg, me, target);
        me->remove_all_killer();
                target->unconcious();
        }
        return ;
}

