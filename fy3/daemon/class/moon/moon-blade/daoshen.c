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
                return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("�������޷�ʩչ���������\n");
        if( (string)weapon->query("skill_type") != "blade" )
        return notify_fail("�������޷�ʩչ���������\n");
        if ( (string) me->query_skill_mapped("blade") != "moon-blade")
        return notify_fail("�������ֻ�ܺ�Բ����ն��ͣ�\n");
        extra = me->query_skill("moon-blade",1) / 10;
        extra += me->query_skill("moon-steps",1) / 10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIR  "\n\n$Nʹ����Բ����ն���е����Ͼ�����������"+ weapon->name() +"��������Ļ��ߣ���ն$n��" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        for(i=0;i<extra/4;i++)
        {
        msg = CYN "$N�������񣬵����ݺᣡ\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        me->start_busy(3);
        return 1;
}
