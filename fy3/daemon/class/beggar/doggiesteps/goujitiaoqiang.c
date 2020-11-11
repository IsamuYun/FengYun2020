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
		return notify_fail("�۹�����ǽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if((int)me->query("kee")*8/(int)me->query("max_kee") > 1)
		return notify_fail("�㲻���򲻵��Ե�ʱ��ʹ�������У�\n");
	weapon = me->query_temp("weapon");
	extra = 2*me->query_skill("doggiesteps",1) / 5;
   me->add_temp("apply/attack", extra);
    me->add_temp("apply/damage", extra);
	msg = HIR  "$N���һ���������类�Ƽ���Ұ����˫��һǰһ�󣬺�������$n�߳���" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
 me->add_temp("apply/damage", -extra);
   me->add_temp("apply/attack", -extra);
	me->start_busy(2);
	return 1;
}

int help(object me)
{
        write(YEL"\nҰ������֮������ǽ��"NOR"\n");
	write(@HELP

       Ұ��������˵��ؤ�������³���Դ��˲����������Դ˲����������⡣
       �˲�����ؤ�����������о���չ��������һ��һ�Ĳ�����ͬʱ�ڲ���
       ʩչʱ���ܹ����Ƚ��������й�����ǽȴ�ǵ�������פî�𵶣���һ��
       ����׷ɱ���˵�Ұ��ʱ���������Լ�׷ɱ��������ʱ�ķ��ˣ���������
       �������ġ�

       Ҫ��	
               (ѧ���ޣ�
               ���ã��Լ���Ѫ����ƽʱ��1/8ʱ��

HELP
	);
	return 1;
}
