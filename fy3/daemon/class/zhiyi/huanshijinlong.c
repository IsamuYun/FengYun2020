// mouse@skills
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;
        extra = me->query_skill("dragon-blade",1);
        if ( extra < 40) return notify_fail("��ģ۷��������ݻ��������죡\n");
        extra = me->query_skill("dragon-steps",1);
        if ( extra < 40) return notify_fail("��ģ������ò��ݻ��������죡\n");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("[ �������� ]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("��������ֻ�ܺͷ���������ͣ�\n");
        if( (string)weapon->query("skill_type") != "blade" )
        return notify_fail("[ �������� ]ֻ�ܺͷ���������ͣ�\n");
        if ( (string) me->query_skill_mapped("blade") != "dragon-blade")
        return notify_fail("[ �������� ]ֻ�ܺͷ���������ͣ�\n");
        extra = me->query_skill("dragon-blade",1) / 10;
        extra += me->query_skill("dragon-steps",1) / 10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIY  "$N�Ųȣ������ò��ݣ�ʩչ�۷����������еľ��������������������е�"+ weapon->name() +"����һ����������$n��" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "���������������־��������\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/8;i++)
        {
        msg = HIG "$N�Ե��������������裡\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "���������������־��������\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/8;i++)
        {
        msg = HIC "$N����������������ȥ��\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "���������������־��������\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/8;i++)
        {
        msg = HIY "$N�����ص����������֣�\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -extra);   
        me->add_temp("apply/damage", -extra);
        me->start_busy(4);
        return 1;
}

