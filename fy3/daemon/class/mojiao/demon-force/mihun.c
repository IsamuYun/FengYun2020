// chillgaze.c

#include <ansi.h>

inherit SSERVER;

int exert(object me, object target, int amount)
{
	object *ob;
	int i, skill, damage,lv;
	lv = (int)me->query("mowuchen");
		if (!lv)   me->set("mowuchen",1);
		lv = (int)me->query("mowuchen");	

	if( !me->is_fighting() )
		return notify_fail("���Ի�󷨣�ֻ����ս����ʹ�á�\n");

	if( (int)me->query("force") < 50*lv)
		return notify_fail("�������������\n");

	if( !target || target==me ) {
		target = offensive_target(me);
		if( !target) return notify_fail("��Ҫ��˭ʩչ���Ի�󷨣ݣ�\n");
	}

	skill = me->query_skill("demon-force",1);

	me->add("force", -50*lv);
	me->receive_damage("sen", 20);

	message_vision(
		HIB "\n$N����������죬˫�۱���쳣���ʣ�ȫ���Ķ���������������������ţ�ϳ���\n" NOR, me, target);
	
	if(( (random(lv + skill/10))*2 < random(target->query("level")) ) && (random(100)>target->query_temp("against"))) {
		message_vision("$N�ܿ��ת��ͷȥ���ܿ���$n��Ŀ�⡣\n", target, me);
		me->start_busy(3);
		return 1;
	}

	damage = random(skill)  - target->query("level") ;
	if( damage < 100 ) {
		message_vision("����$N��$n��ע�������޶�....��\n", target, me);
		me->start_busy(3);
		return 1;
	}

	target->receive_damage("kee", damage);
		target->start_busy(3*lv);
	message_vision("$N��$n�Ĺ����������󣬲��Խ��غ�$n������ͬ���Ľ��࣬����������\n", target, me);
		me->start_busy(3*lv);
			if(me->query("mihun") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("mihun_exp",1);
	      tell_object(me, "��ġ��Ի�󷨡������һ�㼼�������ȡ�\n"NOR);
		}
	  if((me->query("mihun_exp") > (me->query("mihun")*me->query("mihun")*100))&&(me->query("mihun")< 10))
		{
		me->add("mihun",1);
		me->set("mihun_exp",0);

	      tell_object(me, HIW"��ġ��Ի�󷨡��ȼ������ˡ�\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n�����ħ�ķ�֮�Ի�󷨣�"NOR"\n");
	write(@HELP

       ħ�̶������书��ѧ����ǣ�Ƶз����ж�����Ⱥս���������ԡ�
	
      �����ħ�ķ����ܵȼ�����߼��ܳɹ��ʡ�
      �Ի�󷨵ȼ�ÿ����һ�������ӶԵз��Ľ�ֱʱ�����룬��������߼��ܳɹ��ʡ�

HELP
	);
	return 1;
}
