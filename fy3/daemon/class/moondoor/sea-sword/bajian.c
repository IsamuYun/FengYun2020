#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("sea-sword",1);
        if ( extra < 50) return notify_fail("��ĺ�Ԩ�������������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۺ�Ԩ�˽���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        msg = HIY  "$Nʹ����Ԩ�����еģۺ�Ԩ�˽��ݣ�һ�������˽���������е�"+ weapon->name()+  "�������$n������ˮ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "���޽���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC  "���Ľ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "��������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "���ƽ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "ɱ�˽���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "�޵н���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        msg = HIY  "���ֽ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->start_busy(3);
        return 1;
}