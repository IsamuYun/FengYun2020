#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam;

	if( !target ) target = offensive_target(me);

        if((int)me->query_skill("cursism") < 30 )
                return notify_fail("��Ľ�ͷ�������ߣ�\n");

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("��Ҫ��˭ʩչ�����ͷ��\n");
      if (userp(target) && target->query("combat_exp")<1000000)
                return notify_fail("�㲻���Զ������ʩչ�����ͷ��\n");
	if((int)me->query("kee") < 25 )
		return notify_fail("�����Ѫ������\n");

	me->receive_wound("kee", 25);
	msg = HIC "$N�����к��һ����һ��ϸ�緢˿��Ѫ������$n��\n\n" NOR;

	ap = me->query_skill("cursism");
	extradam = ap/2;
        ap = ( ap * ap /100 * ap / 4 ) * (int)me->query("sen") ;
        dp = target->query("combat_exp")*3/2;
        if( random(200)>150 && random(ap + dp) > dp ) {
		damage = me->query("bellicosity") /50 ;
			msg +=  HIR "Ѫ��������Ϣ������$n�����ڣ�����\n" NOR;
       		         message_vision(msg, me, target);
			target->receive_damage("kee", damage, me);
			target->receive_wound("kee", damage/3, me);
		        if( damage > 0 ) COMBAT_D->report_status(target);

	} else
		{
		msg += "���Ǳ�$n�����ˣ���\n";
	        message_vision(msg, me, target);
		target->kill_ob(me);
		me->kill_ob(target);
		}
	me->start_busy(5);
	return 1;
}

