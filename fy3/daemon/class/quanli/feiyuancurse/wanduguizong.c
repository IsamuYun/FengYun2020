// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("��Ҫ��˭ʩչ[�򶾹���]��\n");
        if (userp(target) && target->query("combat_exp")<1000000)  
                return notify_fail("�㲻���Զ���ʩչ[�򶾹���]��\n");
        if( environment(me)->query("no_du") )
                return notify_fail("���ﲻ׼�¶���\n");
if((int)me->query("kee") < 100 )
		return notify_fail("�����Ѫ������\n");
me->receive_wound("kee", 100);
	extra = me->query_skill("feiyuancurse",1) ;
	if( extra <=60) return notify_fail("���[��ԩ������]������������\n");
		msg = HIC "$N�����ע��͵͵����$n������\n\n" NOR;

	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	lvl = (int) me->query_skill("feiyuancurse") / 20;
  if( myexp * lvl > yourexp )
	{
msg +=  HIR "����֮��������Ϣ������$n�����ڣ�����\n" NOR;
       		         message_vision(msg,me,target);
target->apply_condition("wanzhuo",random(10)+3);

	} else
		{
		msg += "���Ǳ�$n�����ˣ���\n";
	        message_vision(msg,me,target);
		target->kill_ob(me);
		me->kill_ob(target);

		}
me->start_busy(2);
	return 1;
}
