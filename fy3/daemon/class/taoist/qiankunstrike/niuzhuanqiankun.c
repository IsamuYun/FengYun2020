// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int mine,yours;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ŤתǬ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	mine = (int) me->query("force_factor");
	yours = (int) target->query("force_factor");
	message_vision(HIW"\n$NͻȻ����һ����Ť����ת����Ǭ������������\n\n",me);
	if(random(mine) > yours)
	{
		me->add("force_factor",yours/2);
		msg= HIY "$N��Ǭ����Ų�����еģ�ŤתǬ����ʹ����˫�Ƽд���$n����������$n" NOR;
        	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
                me->start_busy(3);
		me->add("force_factor",-yours/2);
	}		
	else
	{
		target->add("force_factor",mine/2);
		msg= HIY "$N����$n����֮�ʣ�����ֱ�ߣ���Ѹ���ޱȵ��ٶȹ���$n��" NOR;
                COMBAT_D->do_attack(target,me, 0, TYPE_REGULAR,msg,"����");
                target->add("force_factor",-mine/2);
                me->start_busy(4);
	}
	return 1;
}
