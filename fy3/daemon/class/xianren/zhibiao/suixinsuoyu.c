// tie@fengyun
#include <ansi.h>
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
		return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	extra = me->query_skill("zhibiao",1) ;
	if(extra <= 100 ) return notify_fail("��ģ�ָ�ڣݲ���������\n");
	me->add_temp("apply/attack",extra/10);
       weapon = me->query_temp("weapon");
       message_vision(YEL"$N����һ�����ר���ڼ�������ָ�ڡ�����һ��[��������]���ӵ����쾡����\n"NOR,me,target);      
       msg = HIR "ֻ��$n������������һ����������Ѫ����������ƺ��������ˡ�\n" NOR;
            	message_vision(msg, me, target);
      me->add_temp("apply/attack",-extra/10);
       target->receive_wound("kee", 100,me);
	me->start_busy(3);
	return 1;
}
