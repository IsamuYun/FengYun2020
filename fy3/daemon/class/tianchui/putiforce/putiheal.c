// lifeheal.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
	int lv,lv2;
	lv = me->query("putiheal");
	if (!lv)
		me->set("putiheal",1);
	lv = (int)me->query("putiheal");
	lv2 = me->query_skill("putiforce",1);
	if( me->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	if( (int)me->query("force") - (int)me->query("max_force") < 150*lv )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 5 )
		return notify_fail( "���Ѿ����˹��أ����ܲ�����������𵴣�\n");

	message_vision(
		HIY "$N�������������ڹ�������һ���һ��ף����ã��³�һ����Ѫ����ɫ�������ö��ˡ�\n"
		"���˲��ã�$N��ͷ��ð������ĺ��飬�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
		me);

	me->receive_curing("kee", 10 + (int)me->query_skill("force")/3*lv+lv2/10 );
	me->add("force", -150*lv);
	me->set("force_factor", 0);
		me->add("putiheal_exp",1);
	    tell_object(me, "��ġ������ľ��������һ�㼼�������ȡ�\n"NOR);
	    if(me->query("putiheal_exp") > (me->query("putiheal")*me->query("putiheal")*100)&&(me->query("putiheal")<10))
		{
		me->add("putiheal",1);
		me->set("putiheal_exp",0);
	      tell_object(me, HIW"��ġ������ľ������������ˡ�\n"NOR);
		}
	return 1;
}
 int help(object me)
{
        write(YEL"\n�����ķ�֮�����ľ���"NOR"\n");
	write(@HELP
	����ʹ�ú󣬿��Իָ��Լ������ˡ�
HELP
	);
	  write("\t��ǰ״̬���ָ���Ѫ�˺�"+(int)(me->query_skill("force")/3*me->query("putiheal")+me->query_skill("putiforce",1)/10)+"��\n");
	write(@HELP

      �����ķ��ȼ�ÿ����ʮ�������˵Ĺ�Ч����1�㡣
      �����ľ��ȼ�ÿ����һ�������˵Ĺ�Ч����һ����

HELP
	);
	return 1;
}

