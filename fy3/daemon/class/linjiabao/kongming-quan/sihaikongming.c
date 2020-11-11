//lion@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    string msg;
    int myexp,yourexp,lvl;
    object weapon;

    if( !target ) target = offensive_target(me);
    if( !target
      ||      !target->is_character()
      ||      !me->is_fighting(target) )
        return notify_fail("���ĺ�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    
    if( (int)me->query_skill("kongming-quan",1) < 50 )
    {
    	return notify_fail("��Ŀ���ȭ������������\n");
    }
    
    myexp = (int) me->query("combat_exp");
    yourexp = (int) target->query("combat_exp");
    lvl = (int) me->query_skill("unarmed");
    
    msg = CYN "$Nʹ������ȭ�еģ��ĺ������ݣ��ó�������Ӱ����$n��\n" NOR;
    message_vision(msg, me, target);
    if( yourexp+myexp < random(2*myexp) )
    {
        msg = "���$n����һ��ģ������Ȼ��֪���Լ�����ʲô��\n";
        target->start_busy(3);
        me->start_busy(1);
        target->add_temp("apply/damage",lvl);
        target->add_temp("apply/attack",lvl);
        COMBAT_D->do_attack(target,target, target->query_temp("weapon"), TYPE_REGULAR,msg);
        target->add_temp("apply/damage",-lvl);
        target->add_temp("apply/attack",-lvl);
    }
    else{
        msg = "���ǣ�$n����������û�б�$N�Ի�\n";
        me->add_temp("apply/attack", lvl);
        me->add_temp("apply/damage", lvl);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -lvl);
        me->add_temp("apply/damage", -lvl);
        me->start_busy(2);
    }
    return 1;
}
