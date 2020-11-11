// chillgaze.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target, int amount)
{
	object *ob;
	int i, skill, damage,lv;
	lv = (int)me->query("dimo");
		if (!lv)   me->set("dimo",1);
		lv = (int)me->query("dimo");	

	if( !me->is_fighting() )
		return notify_fail("�۵�ħ����ֻ����ս����ʹ�á�\n");

	if( (int)me->query("force") < 50*lv)
		return notify_fail("�������������\n");
	if( (int)me->query("sen") < 40*lv)
		return notify_fail("�������̫����ɢ��\n");

	if (me->query_temp("ondimo"))
		return notify_fail("Ŀǰ������ʹ�õ�ħ����\n");

	skill = me->query_skill("demon-strike",1);

	me->add("force", -50*lv);
	me->receive_damage("sen", 40*lv);

		if ( random(100)+lv*5 >= 50) 
	{
	message_vision(
		HIB "\n$N˫�۱����������������ħ���������еģ۵�ħ���ݣ�ɲ�Ǽ�$N�����˽���ͨ���ľ��硣\n" NOR, me);

        me->add_temp("apply/attack", skill*lv+1000);
        me->set_temp("ondimo", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill*lv+1000 :), 10+skill/10);
	  me->start_busy(1);
	}
	else 
	{
	write("���ڲ�����������ʩչ��ħ��ʧ���ˡ�\n");
	}
	  me->start_busy(2);
        return 1;

}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->delete_temp("ondimo");
        tell_object(me, HIG"��ĵ�ħ��ʧȥЧ���ˡ�\n"NOR);
		if(me->query("dimo") < (me->query("level")/10) && userp(me))
	{
	  me->add("dimo_exp",1);
	      tell_object(me, "��ġ���ħ���������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("dimo_exp") > (me->query("dimo")*me->query("dimo")*100)&&(me->query("dimo")<10))
		{
		me->add("dimo",1);
		me->set("dimo_exp",0);
	      tell_object(me, HIW"��ġ���ħ�������������ˡ�\n"NOR);
		}
	}
}
 

int help(object me)
{
        write(YEL"\n�����ħ��������֮��ħ����"NOR"\n");
	write(@HELP

      ħ�̶������书��ѧ���ܼ��о������ս��ʱ���������С�
	
	  �����ħ�������Ƶȼ�ÿ����һ����������������һ�㣬���ӳ�����ʱ�䡣
      ��ħ���ȼ�ÿ����һ�������Ӽ���ʩչ�ɹ��ʣ��������һ�����������С�
     

HELP
	);
	return 1;
}
