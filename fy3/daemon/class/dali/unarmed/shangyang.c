// mouse@skills
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
                return notify_fail("������û�գ���\n");
        extra = me->query_skill("liumaishenjian",1);
        if ( extra < 60) return notify_fail("��������񽣻��������죡\n");
        if( (int)me->query("force") < 50 )     return
        notify_fail("�������������\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )

                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add("force", -50);
        me->add_temp("apply/damage",extra*2);
        me->add_temp("apply/attack",extra);
        weapon = me->query_temp("weapon");
        msg = HIB  "$Nʳָ΢��,ʹ���������񽣵ġ�����������һ�ɽ�������˻˻������ʳָ����������$n��\n" NOR;
        message_vision(msg,me,target);
        msg = HIB  "������������������������������������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra);
        me->start_busy(1);
        return 1;
}