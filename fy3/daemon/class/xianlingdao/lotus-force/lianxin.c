// yiru@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    string msg;
    int ap, dp, extra;
    object weapon;
    if( me->query("gender") != "Ů��" )
        return notify_fail("��ģ������ò��ݻ��������죡\n");
    extra = me->query_skill("lotus-steps",1);
    if ( extra < 90 )
        return notify_fail("��ģ������ò��ݻ��������죡\n");
    if( !target ) target = offensive_target(me);
    if( !target
      || !target->is_character()
      || !me->is_fighting(target) )
        return notify_fail("�������ٻã�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    message_vision(HIM"\n$N"HIM"��̤������ʮ�ű�������ò�������������ĥ������\n" NOR,me,target);

    extra=(int)me->query_skill("lotus-steps",1);
    dp=(int)target->query("level");
    ap=(int)me->query("level");

    if( extra>=210 )
    if( random(dp) < random(ap+extra) )
    {
        message_vision(HIB"$N"HIB"���ŵ��ۻ����ң������޷���$n"
        HIB"����������\n"NOR,target,me);
        if( target->is_busy() )
            target->start_busy( target->query_busy() + 3 );
        else
            target->start_busy(7);
        return 1;
    }

    if( random(ap+dp) > dp )
    {
        message_vision("$N���˶�����ϸ�۲�$n�Ĳ�����\n",target,me);
        target->start_busy(3);
        return 1;
    }

    msg = HIR"��$N"HIR"���ǿ�����$n"HIR"��������$n"HIR"ѸȻ������\n"NOR;
    message_vision(msg,target,me);

    me->start_busy(1);
    // var ap is not used now. so use for others.
    ap = random(3)+1;
    for(dp=0;dp<ap;dp++)
        COMBAT_D->do_attack(target,me,
        target->query_temp("weapon"),TYPE_REGULAR,"");
    return 1;
}
