// by xgchen@fy
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int orforce;
        object weapon;
        if(me->is_busy())
                return notify_fail("������̫æ�ˣ���\n");
        extra = me->query_skill("lingxiyizhi",1);
        if ( extra < 181) return notify_fail("�����Ϭһָ��ָ�����������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        orforce = (int) me->query("force");

    if (orforce<3000)  return notify_fail("�������������\n");
          weapon = me->query_temp("weapon");
          me->add_temp("apply/attack",extra*extra);
      me->set("force_factor",0);
          me->add("force_factor",extra);
        msg = HIG  "$Nʹ��һ�У۷������ݣ���$n�����\n" NOR;
        message_vision(msg,me,target);
        msg = WHT  "                           ��!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT  "                           ��!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT  "                           ��!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT  "                           ��!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("force_factor",-extra/5);
        me->add_temp("apply/attack",-extra*extra);

        me->start_busy(3);
        return 1;
}
