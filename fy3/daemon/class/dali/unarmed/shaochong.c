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
        if ( extra < 80) return notify_fail("��������񽣻��������죡\n");
        if( (int)me->query("force") < 50 )     return
        notify_fail("�������������\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )

                return notify_fail("���ٳ彣��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add("force", -50);
        me->add_temp("apply/damage",extra*2);
        me->add_temp("apply/attack",extra);
        weapon = me->query_temp("weapon");
        msg = HIM  "$NСָ΢��,ʹ���������񽣵ġ��ٳ彣����һ�ɽ�������˻˻������Сָ����������$n��\n" NOR;
        message_vision(msg,me,target);       
        msg = HIM  "�����������������������������������ٳ彣����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra);
        me->start_busy(1);
        return 1;
}