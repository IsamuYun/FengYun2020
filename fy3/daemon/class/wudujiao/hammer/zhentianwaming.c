// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("baichan-hammer",1);
        if ( extra < 50) return notify_fail("你的白蟾锤法还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［震天蛙鸣］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        msg = HIY  "$N使出白蟾锤法中的［震天蛙鸣］，集全身力气于双臂，爆呵一声抖手一锤！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N紧跟一招，双锤带动呼呼风声，跟上一锤！！" NOR;

        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N步履如磐石，中宫直入，两臂一振，又是一锤！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N呼啸声不止，抖擞精神，两臂一振，最后一锤！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->start_busy(5);
        return 1;
}