// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        extra = me->query_skill("dodge");
        if ( extra < 300) return notify_fail("你的纵跃闪躲之术还不够纯熟！\n");
        
        if(me->query("env/invisibility"))
                return notify_fail("你正在施展［物幻空灵］\n");
        if( !me->is_fighting() )
           return notify_fail("只能在战斗中使用！\n");
        if(me->query("force") < 100)
                return notify_fail("你的内力不够！\n");
        me->add("force",-100);
  message_vision( HIR "$N"HIR"使出菩提虚空步法的一式＂物幻空灵＂，敛气凝神，步踩虚空，\n
  身影在众人的眼前倏地消失，杳然无踪．．．．\n\n" NOR,me,target);
        me->set("env/invisibility",1);
        me->start_busy(3);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra/2);
        return 1;
}
void remove_effect(object me)
{
        me->delete("env/invisibility");
        tell_object(me, "你的物幻空灵施展完毕，身行停了下来。\n");
}

