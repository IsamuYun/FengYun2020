// ��������  written by tiandi

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
		return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	extra = me->query_skill("sushi-zhi",1);
	if(extra <= 80 ) return notify_fail("��ģ�����ָ�ݲ���������\n");
	if( me->query("TASK") < 1600  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("����Ŀǰ��״������û���ʸ�����һ�С�\n");
	if(extra> 220) extra=220;
	extra=extra*3;
	if(me->query("force")<300) return notify_fail("�������������\n");
	if( me->query("TASK") < 1500  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("����Ŀǰ��״������û���ʸ�����һ�С�\n");
	weapon = me->query_temp("weapon");
	me->add("force",-100);
	if(!me->query_temp("five")||me->query_temp("five")<1)
		{
		msg = HIR "$N���д����һ������������ƶ��У�ʮָ΢����ֻ�������������������������͡���ʮ��ָ������$n,������������ʹ�˳�ȥ��\n"NOR;
        	me->add_temp("apply/damage",extra*2);
		me->add_temp("apply/attack",extra);
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		me->add_temp("apply/damage",-extra*2);
        	me->add_temp("apply/attack",-extra);
		me->start_busy(2);
		}
	else if(random(10)<5)
		{
		msg = HIR "$N˫��һ��ʳָ������ƶ�������һ�С�����ɽ�ӡ�����һ������֮����һ��һ�Ҵ���$n��\n"NOR;
			if(target->query("gender")=="Ů��")
			{
			msg += "$n���۵������ƺ�������$N��һ����$n����äĿ�ض㿪$N����һָ��";	
			me->add_temp("apply/damage",extra*5);
			me->add_temp("apply/attack",extra*5);
        		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
			me->add_temp("apply/damage",-extra*5);
        		me->add_temp("apply/attack",-extra*5);
			me->start_busy(3);
			me->add_temp("five",-1);
			}
			else 
			{
			msg += "$n���Ӿ�������ʮ����Ṧ���㿪$N����һָ��";	
			me->add_temp("apply/damage",extra*2);
			me->add_temp("apply/attack",extra);
        		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
			me->add_temp("apply/damage",-extra*2);
        		me->add_temp("apply/attack",-extra);
			me->start_busy(2);
			}
		}
		else
		{
		msg = HIR "$N����һ����βָ�������ͣ�����һ�����ߣ�һ�С���ȷ�ɡ�����һ�ɴ���֮����һǰһ�����$n��\n"NOR;
			if(target->query("gender")=="����")
			{
			msg += "$n��$N����˸գ������������ʽ����ʯ���󺣣�ֻ�û����з��ء�";	
			me->add_temp("apply/damage",extra*5);
			me->add_temp("apply/attack",extra*5);
        		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
			me->add_temp("apply/damage",-extra*5);
        		me->add_temp("apply/attack",-extra*5);
			me->start_busy(3);
			me->add_temp("five",-1);
			}
			else 
			{
			msg += "$n�������ɵ���������$N��ʮָһ�䣬ͬʱѰ����ÿһ˿�����Ļ��ᡣ";	
			me->add_temp("apply/damage",extra*2);
			me->add_temp("apply/attack",extra);
        		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
			me->add_temp("apply/damage",-extra*2);
        		me->add_temp("apply/attack",-extra);
			me->start_busy(2);
			}
		}
	return 1;
}
