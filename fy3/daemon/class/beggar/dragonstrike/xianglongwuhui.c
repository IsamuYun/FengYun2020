//by xgchen@fy

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
        int myexp,yourexp,lvl,fo;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۽����޻ڣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
     if( (int)me->query("force") < 20 )     return
        notify_fail("�������������\n");
	weapon = me->query_temp("weapon");
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
        fo = (int) target->query_skill("force")+1;
        lvl = (int) target->query_skill("yiqiguanforce")+1;
	msg = HIR "$N���۽���ʮ���ƣݵ�ʮ��ʽ�ܻ��ͨ���ó�ʮ�˸���Ӱһ������$n��ʮ�˴�Ҫ����" NOR;
	if(random(yourexp) < myexp)
	{
	if( random(2))
	{
		message_vision(msg + "\n", me, target);
		msg = "���$n��$N���˸���æ���ң�\n";
		message_vision(msg, me, target);
		target->start_busy(3);
	}
	else
	{
                        me->add_temp("apply/attack", lvl*fo*fo);
                        me->add_temp("apply/damage",lvl*fo);
		        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
			me->start_busy(2);
                        me->add_temp("apply/attack", -lvl*fo*fo);
                        me->add_temp("apply/damage",-lvl*fo);
	}
	}
	else
	{
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->start_busy(2);
	}
    me->add("force", -20);
	return 1;
}
int help(object me)
{
        write(YEL"\n����ʮ����֮�����޻ڣ�"NOR"\n");
	write(@HELP

       ����ʮ������Ϊ��³��������ԭ��Ϊ��Ұ��ʮ��ҧ�������߹�����ȥ��
       �澫�����Ҹ���Ϊ������ʮ���ơ������Ʒ���ؤ�����������о���չ��
       ������һ��һ�ĸ��ͣ����ҹ��ؼ汸�����н����޻ھ��ǽ�ʮ������Ϊ
       һ�ƣ��ӿ������϶��£�˫��һ����¡������ɹ��������ҿ����ŵС�

       Ҫ��	
               (ѧ���ޣ�
               ���ã����� 20 ���ϣ�

HELP
	);
	return 1;
}
