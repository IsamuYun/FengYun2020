// long-steps.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,force;
	object weapon;
	extra = me->query_skill("long-steps",1);
	force=me->query("force");	
	if( me->query("TASK") < 1900  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("����Ŀǰ��״������û���ʸ�����һ�С�\n");

	if ( extra < 100) return notify_fail("��ģ�"+HIC"��"+HIY"��"+HIR"̫"+HIW"��"+HIB"��"+NOR"�ݻ��������죡\n");
	if( !target ) target = offensive_target(me);
	if(( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )&&extra>150&&me->query_temp("five")>1)
		return notify_fail("��"+HIC+"��"+NOR+"��"+HIB+"˫��"+NOR"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��"+HIC+"��"+NOR+"��"+HIW+"����"+NOR"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if (force<500) return notify_fail("����������㡣\n");
	if(target->is_busy())
		return notify_fail(target->name()+"��ð���ǣ���������̶�������Ѿ��ٻ��ˣ�\n");
	message_vision( HIM "$N"HIM"˫�ֺϳ�ʮ��״������ߴ�ﹾ�಻֪������Щʲô����Ȼ֮��$N"HIM"����Χ����һ�Ű�ɫ������\n͸����ؼ��һ˿���ʣ�$n"HIM"����������״�������Լ�Ϯ��������\n\n"+HIW+"$N"HIW"ңָ���գ�����һ�ߣ�һ�����ǰ������������ͻһ�ſڣ����һ���׹�ֱ����$n"HIW"˫Ŀ������������\n" NOR ,me,target);
	if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp")*2)
		{
	message_vision("���$N����һ�������׹�������˫Ŀ��������ʼ�ٻ��ˣ�\n",target);
	target->start_busy(2);
		}
	else {
	message_vision("ֻ��$n��æ����˫�ۣ������ض����$N����ʽ,��������$N���𷴻���\n",me,target);
       		if (extra<131||me->query_temp("five")<2)
	    			 {
	     			COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);
	    			}
	    		else {
		    message_vision(HIR"\n����$N"HIR"���з�����˫�ֺϳ����֣�ֻ��ɲ�Ǽ�һ�����������Ծ�����³������������Ƶ�$n"HIR"ֻ�ܻ���Ϊ�أ�\n"NOR,me,target);
				if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp")*2)
					{
					message_vision("���$N�ӹ��˵�һ�У�ȴû�ܱܿ����У�����������θ���������ʼ�е㽩Ӳ�ˣ�\n",target);
					target->start_busy(3);
					me->add("force",-200);
					}
				else {
				message_vision("$n�þ�ȫ��������������һԾ���ٶȱܿ���$N������Ĺ�����\n"NOR,me,target);
                           		me->start_busy(2);
					me->add("force",-200);
		  	            }
		 	 
			     }
	    }
	return 1;
}
