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
        if ( extra < 350) return notify_fail("�����å��ȭ���������죡\n");
        if ( me->query_int()<80) return notify_fail("����츳����������ʹ��[�Ƹ�����]��\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���Ƹ����ۣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add("force_factor",extra/3);
	orforce = (int) me->query("force");
        me->add("force",extra/3);
	me->add_temp("apply/attack",extra);me->add_temp("apply/damage",extra*2);

	weapon = me->query_temp("weapon");
	msg = HIY  "$Nʹ���������µģ���å��ȭ�ݣ�һ��[�Ƹ�����]�Դ�һ˿��ϧ֮ɫ��$n��ȫ��ҪѨ������\n" NOR;
	message_vision(msg,me,target);
	msg = HIC  "��һȭ------Ц���߽�һָ�ɣ�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "�ڶ�ȭ------Ҷ��������ɽ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "����ȭ------�����������ͷ������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC  "����ȭ------����̫����������������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC "����ȭ------���¹����忴�أ���������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC "����ȭ------ãã��ˮ�����죡����������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC "����ȭ------Ц��Ҷ�俴���ƣ�������������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIC "���һȭ------���׻�������ˮ����������������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);me->start_busy(5);
	me->set("force_factor",0);
	me->set("force", orforce);
        me->add_temp("apply/attack",-extra);me->add_temp("apply/damage",-extra*2);

	return 1;
}
