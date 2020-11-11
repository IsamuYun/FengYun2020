// yiru@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    string msg;
    int ap, dp, extra;
    object weapon;
    if( me->query("gender") != "女性" )
        return notify_fail("你的［莲花幻步］还不够纯熟！\n");
    extra = me->query_skill("lotus-steps",1);
    if ( extra < 90 )
        return notify_fail("你的［莲花幻步］还不够纯熟！\n");
    if( !target ) target = offensive_target(me);
    if( !target
      || !target->is_character()
      || !me->is_fighting(target) )
        return notify_fail("［莲花百幻］只能对战斗中的对手使用。\n");
    message_vision(HIM"\n$N"HIM"脚踏七七四十九变的莲花幻步，身形令人琢磨不定！\n" NOR,me,target);

    extra=(int)me->query_skill("lotus-steps",1);
    dp=(int)target->query("level");
    ap=(int)me->query("level");

    if( extra>=210 )
    if( random(dp) < random(ap+extra) )
    {
        message_vision(HIB"$N"HIB"被扰得眼花潦乱，根本无法向$n"
        HIB"发动攻击！\n"NOR,target,me);
        if( target->is_busy() )
            target->start_busy( target->query_busy() + 3 );
        else
            target->start_busy(7);
        return 1;
    }

    if( random(ap+dp) > dp )
    {
        message_vision("$N定了定神，仔细观察$n的步法。\n",target,me);
        target->start_busy(3);
        return 1;
    }

    msg = HIR"但$N"HIR"还是看出了$n"HIR"的身法，向$n"HIR"迅然攻击！\n"NOR;
    message_vision(msg,target,me);

    me->start_busy(1);
    // var ap is not used now. so use for others.
    ap = random(3)+1;
    for(dp=0;dp<ap;dp++)
        COMBAT_D->do_attack(target,me,
        target->query_temp("weapon"),TYPE_REGULAR,"");
    return 1;
}
