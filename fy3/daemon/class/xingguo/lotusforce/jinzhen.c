// lifeheal.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
	int lv,lv2;
	lv = me->query("jinzhen");
	if (!lv)
		me->set("jinzhen",1);
	lv = (int)me->query("jinzhen");
	lv2 = me->query_skill("lotusforce",1);
	if( !me->is_fighting())
		return notify_fail("�����Ѩֻ����ս����ʹ�ã�\n");

	if( (int)me->query("force") < 150*lv )
		return notify_fail("�������������\n");

	if (!target)
		target = me;
	if (target == me)
		message_vision(HIB "$N���ֽ���������ɫ�������������ó�һ�����룬���Լ�����һ����\n"
		"һ��ů��������������$N��ɫ������������ˡ�\n" NOR,	me);
	else
		message_vision(	HIB "$N���ֽ���������ɫ�������������ó�һ�����룬��$N����һ����\n"
		"һ��ů��������������$N��ɫ������������ˡ�\n" NOR,	me,target);

	target->add("kee", lv2*10+lv*500 );
	if (target->query("kee")> target->query("eff_kee"))
		target->query("eff_kee",target->query("kee"));
	if (target->query("eff_kee")> target->query("max_kee"))
		target->query("eff_kee",target->query("max_kee"));
	if (target->query("kee")> target->query("eff_kee"))
		target->query("kee",target->query("eff_kee"));

	me->add("force", -150*lv);
	me->set("force_factor", 0);
		me->add("jinzhen_exp",1);
	    tell_object(me, "��ġ������Ѩ�������һ�㼼�������ȡ�\n"NOR);
	    if(me->query("jinzhen_exp") > (me->query("jinzhen")*me->query("jinzhen")*100)&&(me->query("jinzhen")<10))
		{
		me->add("jinzhen",1);
		me->set("jinzhen_exp",0);
	      tell_object(me, HIW"��ġ������Ѩ�����������ˡ�\n"NOR);
		}
	return 1;
}
 int help(object me)
{
        write(YEL"\n�����ķ�֮�����Ѩ��"NOR"\n");
	write(@HELP
	   ����ֻ����ս����ʹ�á�
HELP
	);
	  write("\t��ǰ״̬���ָ���Ѫ�˺�"+(int)(me->query_skill("force")/2*me->query("jinzhen")+me->query_skill("lotusforce",1)/10)+"��\n");
	write(@HELP

      �����ķ��ȼ�ÿ����ʮ�������˵Ĺ�Ч����1�㡣
      �����Ѩ�ȼ�ÿ����һ�������˵Ĺ�Ч����һ����

HELP
	);
	return 1;
}
