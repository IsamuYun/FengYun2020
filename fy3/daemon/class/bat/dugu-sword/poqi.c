// tie@fengyun
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int force,extra;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	extra = me->query_skill("dugu-sword",1) ;
	if(extra < 176 ) return notify_fail("��ģ۶��¾Ž��ݲ���������\n");
       force = target->query("max_force");
       message_vision(HIB"$N���˶��¾Ž�������ʽ����һ����������Ȼ����, �����ǽ�����񾪣� \n"NOR,me,target);      
       msg = HIB "$n�����������Ѩ�ƺ��������У�������ʧ��\n" NOR;
            	message_vision(msg, me, target);
if(target->query("max_force")>200) {target->set("max_force",force/2 );}
	me->start_busy(3);
	return 1;
}
