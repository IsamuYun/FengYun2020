// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int attack,int damage);
int perform(object me, object target)
{
        int skill,lv,extra,orforce,attack,damage;
		lv = (int)me->query("mowuchen");
		if (!lv)   me->set("mowuchen",1);
		lv = (int)me->query("mowuchen");	
        if( target != me ) return 
	notify_fail("��ֻ�ܽ���Ī�޳��������Լ������ϡ�\n");
		lv = (int)me->query("mowuchen");
		if (!lv)   me->set("mowuchen",1);
		lv = (int)me->query("mowuchen");	
		if(me->is_busy())
		return notify_fail("������û�գ���\n");
            extra = me->query_skill("nodust-steps",1);
		if( !me->is_fighting() )
		return notify_fail("��Ī�޳���ֻ����ս����ʹ�á�\n");

	orforce = (int) me->query("force");
	if (orforce < lv*100)
		return notify_fail("����������㡣\n");


        if( (int)me->query_temp("wuchen") ) return 
	notify_fail("���Ѿ���ʩչ��Ī�޳����ˡ�\n");
	skill = me->query_skill("nodust-steps",1);
	if(skill < 10) return notify_fail("����޳���̫���ˣ�\n");
	 me->add("force", -100*lv);
	 attack = skill + random(skill);
	 damage = skill + random(skill/3*2);
	 	if ( random(100)+lv*5 >= 50) 
	{
        message_vision( HIR
"$N����һԾ��ʹ���޳������еģ�Ī�޳��ݣ���Ӱ��磬˲Ϣ������Ĺ������������£�\n" NOR, me);
	//	write("��ʱ���������"+attack+",��ʱ�˺������"+damage+"\n");
        me->add_temp("apply/attack", attack);
		me->add_temp("apply/damage", damage);
        me->set_temp("wuchen", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
attack,damage :), 20*lv);
	}
			else 
	{
	write("���ڲ�����������ʩչĪ�޳�ʧ���ˡ�\n");
	}

        me->start_busy(3);
		return 1;
}


void remove_effect(object me, int attack,int damage)
{
        me->add_temp("apply/attack", - attack);
		me->add_temp("apply/damage", - damage);
	//	write("��ʱ���н�����"+attack+",��ʱ�˺������"+damage+"\n");
        me->delete_temp("wuchen");
        tell_object(me, HIG"���Ī�޳�ʧȥЧ���ˡ�\n"NOR);
			if(me->query("mowuchen") < (me->query("level")/10) && userp(me))
	{
	  me->add("mowuchen_exp",1);
	      tell_object(me, "��ġ�Ī�޳��������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("mowuchen_exp") > (me->query("mowuchen")*me->query("mowuchen")*100)&&(me->query("mowuchen")<10))
		{
		me->add("mowuchen",1);
		me->set("mowuchen_exp",0);
	      tell_object(me, HIW"��ġ�Ī�޳������������ˡ�\n"NOR);
		}
	}
}
 
int help(object me)
{
	int skill;
	skill = me->query_skill("nodust-steps",1);
 write(YEL"\n�޳�����֮Ī�޳���"NOR"\n");
write(@HELP
������������ݵ�������Ȼ�Ǹ��գ�û����֪������ʦ����˭������˵��
���������֣�Ҳ����˵�������Ǹ����ˣ����书֮�ӣ�֮������������զ�ࡣ
�˲����ƺ��������֣�������������ȥ�������������Բ��ɹ�����


HELP
);
	  write("\t��ǰ״̬���������мӳ�"+skill+"~"+skill*2+"��.�����˺��ӳ�"+skill+"~"+(int)(skill+skill/3*2)+"�㡣�����ӳ�"+me->query("mowuchen")*20+"�롣\n");
	write(@HELP

      �޳����ȼ�ÿ����һ����������������1~2��,�����˺�1~2�㡣
      Ī�޳��ȼ�ÿ����һ��������ʱ�����Ӷ�ʮ��,ͬʱ��߳ɹ��ʡ�

HELP
	);
	return 1;
}
