#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����ķ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if((int)me->query("kee")*8/(int)me->query("max_kee") > 1)
		return notify_fail("�㲻���򲻵��Ե�ʱ��ʹ�������У�\n");
	weapon = me->query_temp("weapon");
	if( (int)me->query("force") < 100 )     return
        notify_fail("�������������\n");
        if( (int)me->query_skill("doggiesteps",1)<150) return
        notify_fail("���Ұ��������̫���졣\n");
	if( (int)me->query("force") < 100 )     return
        notify_fail("�������������\n");
	if((string) me->query("class") != "beggar" )
		return notify_fail("�㲻��ؤ��ĵ��ӣ�����ʹ�á����ķ�����\n");
        extra = me->query_skill("doggiesteps",1) / 20;
        me->add_temp("apply/attack", extra);	
	msg = HIR  "$N���β�����Ѹ���ޱȵ���$n��ǰ�߳�һ�ȣ�" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
	msg = HIR  "$N����һ�Σ�Ѹ���ޱȵ���$n�����߳�һ�ȣ�" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");	
	msg = HIR  "$N����һ�Σ�Ѹ���ޱȵ���$n�����߳�һ�ȣ�" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
	msg = HIR  "$N��һ������Ѹ���ޱȵ���$n����߳�һ�ȣ�" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
        me->add_temp("apply/attack", -extra);
	me->start_busy(2);
        me->add("force", -100);
	me->start_busy(4);
	return 1;
}

int help(object me)
{
        write(YEL"\nҰ������֮���ķ���"NOR"\n");
	write(@HELP

       Ұ��������˵��ؤ�������³���Դ��˲����������Դ˲����������⡣
       �˲�����ؤ�����������о���չ��������һ��һ�Ĳ�����ͬʱ�ڲ���
       ʩչʱ���ܹ����Ƚ������������ķ���˼����ƾ��˲������������ڴ�
       ȺҰ��֮��������磬����ɨ�����ܣ�����Ұ���޷�����

       Ҫ��	
               (ѧ���ޣ�
               ���ã�Ұ�������ȼ� 150 ���ϣ�
                     ���� 100 ���ϣ�

HELP
	);
	return 1;
}
