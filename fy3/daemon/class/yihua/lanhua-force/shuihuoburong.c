// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	int lvl;
	string msg,msg1,msg2,msg3;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ˮ���ݣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	lvl = (int)me->query_skill("binghuostrike",1) / 20;
	if(lvl<1) {		return notify_fail("��ĺ����һ��ƻ��������!��\n");
		}	
	extra = me->query_skill("binghuostrike",1) / 5;
	extra=extra*lvl*lvl;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg1 = HIY  "$N˫������,ȫ���˹�,�ϻ����֮����,���ֳʰ�,���ֳʺ�,����һ��:ʹ�������һ��Ƶľ�ѧ\n\n" NOR;	
	msg2 = BLINK HIR  "						    !!!ˮ*��*��*��!!!\n\n" NOR;
	msg3 = BLINK MAG  "					      !!!!!!��    "+chinese_number(lvl)+"    ��!!!!!!\n" NOR;
	msg=msg1+msg2+msg3;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra);
	me->start_busy(1);
	return 1;
}
