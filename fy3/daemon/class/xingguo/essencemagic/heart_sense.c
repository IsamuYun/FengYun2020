// heart_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
	if( !target || !target->is_character() )
		return notify_fail("��Ҫ��˭ʹ����ʶ��ͨ��\n");
	if( target->is_corpse() )
		return notify_fail("�������ˣ�ֻ�л��˲��ܾ��ѡ�\n");
        if((int) me->query_skill("essencemagic",1) < 80)
                return notify_fail("��İ�ʶ��ͨ�������");
	if( (int)me->query("atman") < 50 ) return notify_fail("�������������\n");
        if( me->query("sen") <= 30 )
                return notify_fail("����񲻹���\n");
	me->add("atman", -50);
	me->receive_damage("sen", 30);
	message_vision( HIY "$Nһ�ַ���$n���������, һ������$n�ĺ���, �����۾���������...\n" NOR, me, target);
	if( random(me->query("max_atman")) > 100 && target->query_temp("is_unconcious"))
		target->revive();
	else
		me->unconcious();
	if( me->is_fighting() )
		me->start_busy(3);
	return 1;
}
int help(object me)
{
        write(YEL"\n��ʶ��֮ͨ��ʶ��"NOR"\n");
	write(@HELP

         ���Խ�����״̬��ͬ����ѡ�
		 ����Ҫ��ʩ��������״̬�µ�ͬ�����ϡ�����
     

HELP
	);
	return 1;
}

