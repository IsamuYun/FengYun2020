#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
        int extra,extra1,tmp;
	object weapon;
       if( !target ) target = offensive_target(me);
       if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[��˼����]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("vivien-sword",1);
	if ( extra < 100) return notify_fail("���[��˼����]���������죡\n");
       dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "vivien-steps")
			return notify_fail("����˼���ã���Ҫ�����鲽���ݵ���ͣ�\n");
	tmp = me->query_skill("vivien-steps",1);
        if ( tmp < 80 )return notify_fail("��ģ����鲽���ݻ��������죡\n");
        extra1 = me->query_skill("vivien-sword",1)/5;
        me->add_temp("apply/attack",extra1);   
        me->add_temp("apply/damage",extra1);   
	msg = GRN  "$Nʹ����˼�����е���߾������˼���ãݣ�����ͻȻ���������֣����е�"+ weapon->name()+"�������������Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIW "ãã����һ�֣���ʧ��������\n" NOR;
       msg =  WHT "������ʧ��$NͻȻ������һ����" + MAG "\n��˼���õ�һʽ����ɽһ����" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  WHT "������ʧ��$NͻȻ������һ����" + HIM "\n��˼���õڶ�ʽ������һ����" NOR; 
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  WHT "������ʧ��$NͻȻ������һ����" + RED "\n��˼���õ���ʽ������һ����" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  WHT "������ʧ��$NͻȻ������һ����" + HIC "\n��˼���õ���ʽ����Ůһ����" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  WHT "������ʧ��$NͻȻ������һ����" + GRN "\n��˼���õ���ʽ����ˮһ����" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  WHT "������ʧ��$NͻȻ������һ����" + HIR "\n��˼���õ���ʽ����˼һ����" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  WHT "������ʧ��$NͻȻ������һ����" + YEL "\n��˼���õ���ʽ������һ����" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  WHT "������ʧ��$NͻȻ������һ����" + BLU "\n��˼�������һʽ����˼���ã�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->set_temp("apply/attack",-extra1);   
        me->add_temp("apply/damage",-extra1);   
	me->start_busy(4);
	return 1;
}
