#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������޹���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
      if( (int)me->query("force") < 100 )     return
        notify_fail("�������������\n");

	if((int)me->query_skill("dagou-stick",1) < 100)
		return notify_fail("��Ĵ򹷰���������������\n");
	extra = me->query_skill("staff") / 7;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N���һ���������޹��ݣ������������е�"+ weapon->name() +"��"+
weapon->name() +
"���������Ӱ������ڵذ����$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
      if((int)me->query_skill("dagou-stick",1) > 150)
       msg =HIR  "$N�����е�"+ weapon->name() +"��"+
weapon->name() +
"��$n���һ������й��Ŵ򹷣�" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
      if((int)me->query_skill("dagou-stick",1) > 200)
      msg =HIR "$N�����е�"+ weapon->name() +"��"+
weapon->name() +
"ָ��$n�ı��ģ������·���ӣ�" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
       me->add("force", -100);
	me->start_busy(2);
	return 1;
}
int help(object me)
{
        write(YEL"\n�򹷰﷨֮�����޹���"NOR"\n");
	write(@HELP

       �򹷰���Ϊ���߹�����ԭ������ؤ��ʱ���������װ�����տ�ޱȣ���
       ���߹�һ����Ѫ��������ʹ���򹷰����ľ��У������еĴ򹷹�����һ
       Ƭ��ɽ�����Ĺ�Ӱ����ʵ��ˣ�ר���û����ֵ�ȫ�����ؽڡ���������
       ��ɱ�к��ơ�

       Ҫ��	
               (ѧ���ޣ�
               ���ã����� 100 ���ϣ�
                    �򹷰����ȼ� 100 ����

HELP
	);
	return 1;
}
