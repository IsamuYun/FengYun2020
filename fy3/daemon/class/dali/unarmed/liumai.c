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
        if ( extra < 150) return notify_fail("��������񽣻��������죡\n");
        if( (int)me->query("force") < 100 )     return
        notify_fail("�������������\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )

                return notify_fail("���������ڣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add_temp("apply/damage",extra*3);
        me->add_temp("apply/attack",extra);
        me->add("force", -100);
        weapon = me->query_temp("weapon");
        msg = HIR  "$N���Ծ��,ʹ���������񽣵���߾�����" + HIC "��������" + HIR "����ʮָ���಻������$n�����\n" NOR;
        message_vision(msg,me,target);

        msg = HIG  "\n  �����󽣡���\n" NOR;

        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "\n      ���س彣����\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "\n          ������������\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "\n              ���ٳ彣����\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "\n                  ���г彣����\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "\n                      �����̽�����\n" NOR;

        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra*3);
        me->add_temp("apply/attack",-extra);
        me->start_busy(3);
        return 1;
}