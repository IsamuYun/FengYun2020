#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{

        string dodskill,msg;
        int extra;
        object weapon;
        extra = me->query_skill("bloom-blade",1);
        if ( extra < 90) return notify_fail("��ģ�Ѫ���󷨣ݻ��������죡\n");
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "douzhuan-steps")
                        return notify_fail("��Ѫ���񵶣���Ҫ��ת���Ʋ�������ͣ�\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��Ѫ���񵶣�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        msg = HIR  "$NͻȻ���Դ�,����������\n��һ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�ڶ�����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "��������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "���ĵ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "���嵶��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "��������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "���ߵ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�ڰ˵���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�ھŵ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "��ʮ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(2);
        return 1;
}
