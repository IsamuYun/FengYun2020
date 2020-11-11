// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int lev;
	int fr;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����߾�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	if (!weapon) return notify_fail("�����߾�ֻ�ܺ�����������ͣ�\n");
	if( (string)weapon->query("skill_type") != "sword" )
	return notify_fail("�����߾�ֻ�ܺ�����������ͣ�\n");
	if ( (string) me->query_skill_mapped("sword") != "wuliang-sword")
	return notify_fail("�����߾�ֻ�ܺ�����������ͣ�\n");
	
	extra = me->query_skill("wuliang-sword",1);
	if ( extra < 100) return notify_fail("��ģ����������ݻ��������죡\n");
	
	fr = me->query_skill("foreknowledge", 1);

	me->add_temp("apply/attack", extra+fr/10);
	me->add_temp("apply/damage", extra+fr/10);

	msg = HIW  "$N����һ��'�����ٷ�'������ȫ��֮���ӳ����������о��춯�ص�һʽ�������ޣ������ߣ�����\n\n" NOR;

	message_vision(msg,me);

        msg = HIY  "����������\n$N�����һ������������$w��Х��������$n��$l��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg = HIW  "��������\n$N����$w���ⱬ������������󺣰�����$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg = HIG  "ɽʯ������\n$N����$w������ǧ���Ȼײ��$n��$l��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg = HIM  "����������\n$N����Ծ������$w�����������ƣ�����$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg = HIC  "����������\n$N����һ��������$wȦת��������Ļ�Ȼһ�壬����$n��$l��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg = HIB  "����������\n$N����һ��������$w�󿪴�ϣ���Բ��������������$n����Χס��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        msg = HIR  "����������\n$N����$w�ӽ���˲�仯ΪһƬ��⣬������˷�����$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	if(extra > 210)
	{
        msg =  HIW  "\n�߾���һ��Ǭ�����������Ǭ��������������\n$N�Ľ��ƺ�Ȼ���ˣ�������һ���ӳ������ű߼ʣ������·���\n" NOR;
        if(random((fr/100)*(int)me->query("combat_exp")) >= random((int)target->query("combat_exp")))
        {
			message_vision(msg+"\n",me,target);
			message_vision( HIY "ֻ���Ɀ׾���ٶ۵�һ�������Ĵ̹�����Ȼ����������Ļ��ꡣ\n$N�޴Ӷ�ܣ��ľ�������\n" NOR,target);
			target->receive_damage("kee",extra*fr/100);
			target->receive_damage("sen",extra+fr);
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
		}
		else
		{
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		}		
	}

	if(extra > 240)
	{
        msg =  HIG  "\n����Ǭ��������������$N�����Ȼ����������𶯡����Ȿ����ббָ��$n����һ�������Ȼ��ȫ����ֹ��\n������Χ�Ŀ��������ݷ�Ҳ��ͣ�١�\n" NOR;
		if(random((fr/50)*(int)me->query("combat_exp")) >= random((int)target->query("combat_exp")))
		{
			message_vision(msg+"\n",me,target);
			message_vision( HIY "��ˮǬ�ݣ��仯��������սᣬ����������\n$Nֻ��ȫ��һ�����ѣ��ƺ����е�����������ʧ�ˣ�\n" NOR, target);
			target->receive_damage("gin",extra*fr/50);
			target->receive_damage("kee",extra*fr/50);
			target->receive_damage("sen",extra*fr/50);
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,"");
		}
		else
		{
			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		}
	}

	me->add_temp("apply/attack", -(extra+fr/10));
	me->add_temp("apply/damage", -(extra+fr/10));

  	lev = 4 - fr/200;
  	if(lev < 2)
  	{
  		lev = 2;	
  	}
	me->start_busy(lev);

	return 1;
}
