#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("����ֻ�ܺͶ��Ͻ�����ͣ�\n");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("����ֻ�ܺͶ��Ͻ�����ͣ�\n");
        if ( (string) me->query_skill_mapped("sword") != "duan-sword")
        return notify_fail("����ֻ�ܺͶ��Ͻ�����ͣ�\n");
        extra = me->query_skill("duan-sword",1) / 10;
        extra += me->query_skill("duan-steps",1) /10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIG  "$N��̤�۶��ϲ����ݣ�ͬʱʹ���۶��Ͻ������еľ��裭��" + HIR"����"HIG + "�ݣ����е�"+ weapon->name() +"����" + HIC"��" + HIY"��" + HIG"������߻���$n��" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//      msg =  HIW "����һ������ʧ��������\n" NOR;
//      message_vision(msg, me, target);
        for(i=0;i<extra/4;i++)
        {
//      msg = HIG  "$N��̤�۶��ϲ����ݣ�ͬʱʹ���۶��Ͻ������еľ��裭����" + HIR"����"HIG + "�ݣ����е�"+ weapon->name() +"����" + HIC"��" + HIY"��" + HIG"������߻���$n��" NOR;
//      message_vision(msg, me, target);
        msg = HIC "$N������ʵ����裬�ֳ�һ����\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        me->start_busy(4);
        return 1;
}
