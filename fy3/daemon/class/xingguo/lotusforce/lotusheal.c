// lifeheal.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
	int lv,lv2;
	lv = me->query("lotusheal");
	if (!lv)
		me->set("lotusheal",1);
	lv = (int)me->query("lotusheal");
	lv2 = me->query_skill("lotusforce",1);
	if( me->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	if( (int)me->query("force") - (int)me->query("max_force") < 150*lv )
		return notify_fail("�������������\n");

	if (!target || target == me)
		return notify_fail("һƬ����ֻ�ܶ�����ʹ�á�\n");

	message_vision(
		HIY "$N�������������ڹ���˫�ִ���$n�ı���ʼ���ˣ�ͬʱ�������һƬ���������ƹ�������һ�㡣\n"
		"���˲��ã�$n��ͷ��ð������ĺ��飬�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
		me,target);

	me->receive_curing("kee", 10 + (int)me->query_skill("force")/2*lv+lv2/10 );
	me->add("force", -150*lv);
	me->set("force_factor", 0);
		me->add("lotusheal_exp",1);
	    tell_object(me, "��ġ�һƬ���ġ������һ�㼼�������ȡ�\n"NOR);
	    if(me->query("lotusheal_exp") > (me->query("lotusheal")*me->query("lotusheal")*100)&&(me->query("lotusheal")<10))
		{
		me->add("lotusheal",1);
		me->set("lotusheal_exp",0);
	      tell_object(me, HIW"��ġ�һƬ���ġ����������ˡ�\n"NOR);
		}
	return 1;
}
 int help(object me)
{
        write(YEL"\n�����ķ�֮һƬ���ģ�"NOR"\n");
	write(@HELP
	����ʹ�ú󣬿��Իָ����˵����ˣ����ɶ��Լ�ʹ�á�
HELP
	);
	  write("\t��ǰ״̬���ָ���Ѫ�˺�"+(int)(me->query_skill("force")/2*me->query("lotusheal")+me->query_skill("lotusforce",1)/10)+"��\n");
	write(@HELP

      �����ķ��ȼ�ÿ����ʮ�������˵Ĺ�Ч����1�㡣
      һƬ���ĵȼ�ÿ����һ�������˵Ĺ�Ч����һ����

HELP
	);
	return 1;
}

