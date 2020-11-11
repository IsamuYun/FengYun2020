#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("moon-steps",1);
if ( extra < 60) return notify_fail("你的［圆月步法］还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［月神］只能对战斗中的对手使用。\n");
        if(target->is_busy())
                return notify_fail(target->name()+"已经手忙脚乱了！\n");
message_vision(HIY"$N提气凝神，施展出［月神］绝技 , 身形瞬间变得飘渺不定，！\n"NOR,me,target);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
        {
        message_vision("结果$N心神涣散，眼花潦乱，无从分辨！\n",target);
        target->start_busy(3);
        }
        else{
        msg = "可惜$N以守为攻，峄然不动！";
        COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);  
        me->start_busy(1);
        }
        return 1;
}

