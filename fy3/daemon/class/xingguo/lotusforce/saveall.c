// saveall.c  by tiandi �ն�����

#include <ansi.h>

int exert(object me, object target, int amount)
{
	object *mem;
	int msize,lv,i,mm,extra;
	lv = me->query("saveall");
	if (!me->query("saveall"))
		me->set("saveall",1);
	lv = me->query("saveall");
	if( !me->is_fighting() )
		return notify_fail("�ն�����ֻ����ս��ʱʹ�á�\n");
	mem = me->query_team();
	msize = sizeof(mem);
	if (msize < 2)
		return notify_fail("�ն�����ֻ�ܶ�����еĻ��ʹ�á�\n");

	if( (int)me->query("force") < 100 * lv )
		return notify_fail("�������������\n");
	if( (int)me->query("kee") < me->query("eff_kee")/2 )
		return notify_fail("�����Ѫ������\n");
	extra = me->query_skill("lotusforce",1);
	if (extra < 300)
		return notify_fail("��ļ��ܻ�����������\n");
	message_vision(HIW"$N˫�ֳʹ��������������������մ�أ�������ͬ�����ϡ�\nȴ��$N��ͬ�鶼Ѫɫ���ã�Ψ��$N�Լ��Ѿ���ɫɷ�ס�\n" NOR,me);
	me->set("kee",1);
	me->set("force", 100+extra);
	if (lv < msize-1)
		mm = lv;
	else 
		mm = msize;
	for(i=0;i<mm;i++)
		{
		if( mem[i] != me && (environment(me) == environment(mem[i])) && random(extra)>100)
			{
			mem[i]->set("eff_kee",mem[i]->query("max_kee"));
			mem[i]->set("kee",mem[i]->query("max_kee"));
			mem[i]->set("eff_gin",mem[i]->query("max_gin"));
			mem[i]->set("gin",mem[i]->query("max_gin"));
			mem[i]->set("eff_sen",mem[i]->query("max_sen"));
			mem[i]->set("sen",mem[i]->query("max_sen"));
			mem[i]->set("force",mem[i]->query("max_force"));
			mem[i]->set("atmane",mem[i]->query("max_atman"));
			mem[i]->set("mana",mem[i]->query("max_mana"));
			message_vision(HIY"\n�������$N���ϣ�$N�ָ��������״̬��\n" NOR,mem[i]);
			}
		else 
			if (mem[i] != me)
				message_vision(HIY"\n����$N�����������������$n����һ��֮����$n��δ�о����κα仯��\n" NOR,me,mem[i]);
		}
	if(me->query("saveall") < (target->query("level")/10) && !userp(target))
	{
	 	 me->add("saveall_exp",1);
	      tell_object(me, "��ġ��ն������������һ�㼼�������ȡ�\n"NOR);
		}
	  if((me->query("saveall_exp") > (me->query("saveall")*me->query("saveall")*100))&&(me->query("saveall")< 10))
		{
		me->add("saveall",1);
		me->set("saveall_exp",0);

	      tell_object(me, HIW"��ġ��ն��������ȼ������ˡ�\n"NOR);
		}
	return 1;
}
int help(object me)
{
        write(YEL"\n�����ķ�֮�ն�������"NOR"\n");
	write(@HELP

      �˹����µ��֮һ�������������ͬ���������
	
	  �����ķ�ÿ����һ�������پ���������������Ѫһ�㡣
      �ն�������ÿ����һ�������Ӵ��е���Ч����һ����
     

HELP
	);
	return 1;
}

