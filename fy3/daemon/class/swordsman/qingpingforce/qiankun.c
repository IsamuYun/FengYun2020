// chillgaze.c

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
	object *ob;
	int i, skill, damage;
	string msg;
	if( !me->is_fighting() )
		return notify_fail("��ŤתǬ����ֻ����ս����ʹ�á�\n");

	if( (int)me->query("force") < 50 )
		return notify_fail("�������������\n");

	if( !target || target==me ) {
		target = offensive_target(me);
		if( !target) return notify_fail("��Ҫ��˭ʩչ��ŤתǬ���ݣ�\n");
	}

	skill = me->query_skill("force");
	msg = HIR +me->name()+"˫��ת����ʩչ����ŤתǬ���ݣ���ͼ��ǿ�ҵ�������$N�Ĺ�������$n" NOR;
	me->add("force", -50);
	me->receive_damage("sen", 20);
	if(random((int)me->query("combat_exp") * skill/100) > random((int)target->query("combat_exp")))
        COMBAT_D->do_attack(target,target, target->query_temp("weapon"),TYPE_REGULAR,msg);
	else
	{
	message_vision(msg+"��\n",target,target);
	message_vision("���ǲ�û�гɹ���\n",me);
	}
	me->start_busy(1);
	return 1;
}

