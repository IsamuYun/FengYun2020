// counterattack.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int lv,skill;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ճ�־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (!me->query("nianzijue"))
		me->set("nianzijue",1);
	lv = me->query("nianzijue");
	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");
         if( (int)me->query("force") < 50*lv )     return    notify_fail("�������������\n");
	skill = me->query_skill("three-sword",1);
	msg = CYN "$Nʹ�����Ž����еġ�ճ���־�����ͼ����$n�Ĺ��ƣ�";

	if( ((random(lv + skill/10))*2 > random(target->query("level"))) && (random(100)>target->query_temp("against"))) {
		msg += "\n���$p��$P���˸����ֲ�����\n" NOR;
		target->start_busy( lv/2 + 1);
	} else {
		msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);
            me->add("force", -50*lv);
	if(me->query("nianzijue") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("nianzijue_exp",1);
	      tell_object(me, "��ġ�ճ�־��������һ�㼼�������ȡ�\n"NOR);
		}
	  if((me->query("nianzijue_exp") > (me->query("nianzijue")*me->query("nianzijue")*100))&&(me->query("nianzijue")< MAX_PFMLEVEL))
		{
		me->add("nianzijue",1);
		me->set("nianzijue_exp",0);

	      tell_object(me, HIW"��ġ�ճ�־����ȼ������ˡ�\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n���Ž���ճ�־���"NOR"\n");
	write(@HELP

       ���Ž�������̫��ȭΪ������չ�����ļӷ�����̫��ȭһ�������Ծ��ƶ���
       �����ˣ�ÿһ�ж�����̫��ʽ�������仯��ճ�־���Ҳ����̫��ȭ��ճ
       �־�Ϊ���������Լ�����ʽ�����ҵ��ˣ�ʹ���˲������ܻ���С�
	
      ���ʽ������ܵȼ�ÿ����һ������߼��ܳɹ��ʡ�
      ճ�־��ȼ�ÿ�������������ӶԵз��Ľ�ֱʱ��һ��.

HELP
	);
	return 1;
}