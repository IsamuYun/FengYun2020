// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��Ұ��ȭ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        extra = me->query_skill("unarmed")* 5 ;
        if(extra <= 300 ) return notify_fail("��ģ�Ұ��ȭ�ݲ���������\n");
        COMBAT_D->do_attack(me,target, 
        me->query_temp("weapon"),TYPE_REGULAR,msg);

weapon = me->query_temp("weapon");
        me->add_temp("apply/damage",extra*10);
        me->add_temp("apply/attack",extra/3);
        msg = HIR "$NͻȻ��������˫�֣����һ����������$n��ȥ��\n" NOR;
        message_vision(msg,me,target);
        msg = HIW  "ʯͷ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "���ӣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       
        me->add_temp("apply/damage",-extra*10);
        me->add_temp("apply/attack",-extra/3);
        me->start_busy(2);
        return 1;
}