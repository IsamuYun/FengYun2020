#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) )
		return notify_fail("��Ůɢ����ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	if (!weapon) return notify_fail("��Ůɢ��ֻ�ܺ�����������ͣ�\n");
	if( (string)weapon->query("skill_type") != "sword" )
	return notify_fail("��Ůɢ��ֻ�ܺ�����������ͣ�\n");
	if ( (string) me->query_skill_mapped("sword") != "lanhua-sword")
	return notify_fail("��Ůɢ��ֻ�ܺ�����������ͣ�\n");
	extra = me->query_skill("lanhua-sword",1) / 10;
	extra += me->query_skill("lanhua-steps",1) /10;
	me->add_temp("apply/attack", extra);    
	me->add_temp("apply/damage", extra);
	msg = HIC  "$N��̤�����������ݣ�ͬʱʹ���������������еľ��裭��" + HIW"��Ůɢ��"WHT + "�ݣ����е�"+ weapon->name() +"����" + HIC"��" + HIY"��" + HIG"���ԲȦ����$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//	msg =  HIW "����һ������ʧ��������\n" NOR;
//	message_vision(msg, me, target);
	for(i=0;i<extra/5;i++)
	{
//	msg = HIC  "$N��̤�����������ݣ�ͬʱʹ���������������еľ��裭��" + HIW"��Ůɢ��"WHT + "�ݣ����е�"+ weapon->name() +"����" + HIC"��" + HIY"��" + HIG"���ԲȦ����$n��" NOR;
//	message_vision(msg, me, target);
	msg = HIC "$N����һ��һ��,�ַ�һ����\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
