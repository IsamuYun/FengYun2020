// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("unarmed");
	if ( extra < 100) return notify_fail("���[��Ԫ�Ʒ�]���������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�ۻ�Ԫ�Ļ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add("force_factor",extra/5);
	orforce = (int) me->query("force");
	me->add("force",extra/5*100);
	me->add_temp("apply/attack",extra/10);
	weapon = me->query_temp("weapon");
	msg = HIY  "$Nʹ����Ԫ�Ʒ��еģۻ�Ԫ�Ļ��ݣ�����һ�ɿ����$n������\n" NOR;
	message_vision(msg,me,target);
	msg = HIY  "����������" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "��ħ������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "����������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "����ж����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      	me->start_busy(5);
	me->set("force_factor",0);
	me->set("force", orforce);
        me->add_temp("apply/attack",-extra/10);
	return 1;
}
