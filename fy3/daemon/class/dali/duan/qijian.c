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
        extra = me->query_skill("unarmed")*2;
//        if ( extra > 450) extra = 450;
        if ( extra < 50) return notify_fail("��Ķ���һ��ָ���������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۻ���Ϊ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        me->add_temp("apply/damage",extra*2);
        me->add_temp("apply/attack",extra/3);
        weapon = me->query_temp("weapon");
        msg = HIR "$N���Ծ��,ʹ���˶���һ��ָ�ľ���" + HIC "�ۻ���Ϊ����" HIR + "��ʳָ����$n�����\n" NOR;
//        message_vision(msg,me,target);
//        msg = HIY  "����������������������������������Ϊ������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*2);
        me->add_temp("apply/attack",-extra/3);
        me->start_busy(2);
        return 1;
}