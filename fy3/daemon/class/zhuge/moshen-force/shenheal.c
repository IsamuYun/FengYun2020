// 神魔疗

#include <ansi.h>

int exert(object me, object target, int amount)
{
        if( me->is_fighting() )
                return notify_fail("目前神魔疗还不支持在战斗中疗伤？\n");

        if( (int)me->query("force") - (int)me->query("max_force") < 500 )
                return notify_fail("你的真气不够。\n");

        write( HIW "你全身放松，坐下来开始运功疗伤。\n" NOR);
        message("vision",
                HIB + me->name() + 
"坐下来运功疗伤，头顶竟出一丝丝紫气。你似乎看见一个人影，转眼就不见了。\n" 
NOR,
                environment(me), me);

        me->receive_curing("kee", me->query("max_kee"));
        me->set("force", 0);
        me->set("force_factor", 0);

        return 1;
}
 
