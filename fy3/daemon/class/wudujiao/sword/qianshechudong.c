// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        object weapon;
        extra = me->query_skill("qingshe-sword",1);
        if ( extra < 50) return notify_fail("��ģ����߽����ݻ��������죡\n");
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "wudu-steps")
                        return notify_fail("��ǧ�߳�������Ҫ���嶾�����ݵ���ͣ�\n");
        tmp = me->query_skill("wudu-steps",1);
        if ( tmp < 50 )return notify_fail("��ģ��嶾�����ݻ��������죡\n");
        
        if( !target ) target = offensive_target(me);
        if( !target

        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ǧ�߳�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        msg = HIR  "\n\n$N���е�$w�ó�ǧ�佣��ʹ�����߽����Ĳ�����ѧ ---ǧ-��-��-��--- ����\n\n\n������̽ͷ��\n$N����$wֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "����΢��о��\n$N����$wб��$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "���߷�����\n$N����$w���$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "�������˷���\n$N����$w�ʹ�$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "���������Σ�\n$N����$w����$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(4);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        return 1;

}