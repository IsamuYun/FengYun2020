// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int lev;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("biyuntian",1);
	if ( extra < 50) return notify_fail("��ı����컹�������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ħ��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add_temp("apply/attack",extra*2);
	me->add_temp("apply/damage",extra*2);

	weapon = me->query_temp("weapon");
	msg = HIR  "$N˫�ֺ�£�����ַֿ�������Ѫ������Ũ�ң�����������������أ�\n$n�ٸ���������������û�а��죬û�к�ҹ��\n" NOR;
	message_vision(msg,me,target);
	msg = HIW   "ȴ��$N��Ȼʹ���������еģ�ħ�������ݣ�\n" NOR;
	message_vision(msg,me,target);
    
    lev = extra/50;
    
    if(lev > 0)
    {
        msg =  HIM  "��  Ѫ  �  �" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIB  "��  ��  ��" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    }
    
    if(lev > 1)
    {
        msg =  HIM  "��  ҹ  ��  ��" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIB  "Թ  ��  ��" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    }
    
    if(lev > 2)
    {
        msg =  HIM  "��  ħ  ��  ��" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIB  "��  ��  ��" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    }
    
    if(lev > 3)
    {
        msg =  HIC  "ħ  ��  ��  ��" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIC  "��  ��  ��" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    }
  	  	
    me->add_temp("apply/attack",-extra*2);
    me->add_temp("apply/damage",-extra*2);

  	if(lev > 4)
  	{
  		lev = 4;	
  	}
  	
  	if(lev < 2)
  	{
  		lev = 2;	
  	}
  	
  	me->start_busy(lev);

	return 1;
}
