// heart_sense.c

#include <ansi.h>

inherit SSERVER;

int conjure(object me, object target)
{
	int lvl;
	if( !target ) target = me;
	lvl = (int) me->query_skill("essencemagic",1);
	lvl = lvl + (int) me->query("spi");
	if( (int)me->query("atman") < 50 ) return notify_fail("�������������\n");
	me->add("atman", -50);
	if( random(lvl) <= 65) {
        write("����Ϊ�԰�ʶ��ͨ�����в��������ʧ���ˡ�\n");
                return 1;
	}
	target->receive_curing("sen", 50);
	if(me != target)
	message_vision( HIY "$N��Ŀ����ӡ�÷���һ����â��ס$n��ȫ��...\n" NOR, me, target);
	else
	message_vision( HIY "$N��Ŀ����ӡ�÷���һ����â��ס$N��ȫ��...\n" NOR, me);
	return 1;
}
