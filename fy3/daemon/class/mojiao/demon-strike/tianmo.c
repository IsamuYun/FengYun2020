// chillgaze.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target, int amount)
{
	object *ob;
	int i, skill, damage,lv;
	lv = (int)me->query("tianmo");
		if (!lv)   me->set("tianmo",1);
		lv = (int)me->query("tianmo");	

	if( !me->is_fighting() )
		return notify_fail("����ħ����ֻ����ս����ʹ�á�\n");

	if( (int)me->query("force") < 50*lv)
		return notify_fail("�������������\n");
	if( (int)me->query("kee") < 40*lv)
		return notify_fail("�����Ѫ������\n");
	if (me->query_temp("ontianmo")
		return notify_fail("Ŀǰ������ʹ����ħ����\n");

	skill = me->query_skill("demon-strike",1);

	me->add("force", -50*lv);
	me->receive_damage("kee", 40*lv);

		if ( random(100)+lv*5 >= 50) 
	{
	message_vision(
		HIB "\n$N˫�۱�����������������ħ���������еģ���ħ���ݣ�ɲ�Ǽ�$N���������ҵľ��硣\n" NOR, me);

        me->add_temp("apply/heavyhit", lv*5);
        me->set_temp("ontianmo", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
lv*5 :), 1+skill/10);
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
        me->add_temp("apply/heavyhit", - amount);
        me->delete_temp("ontianmo");
        tell_object(me, HIG"�����ħ��ʧȥЧ���ˡ�\n"NOR);
		if(me->query("tianmo") < (me->query("level")/10) && userp(me))
	{
	  me->add("tianmo_exp",1);
	      tell_object(me, "��ġ���ħ���������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("tianmo_exp") > (me->query("tianmo")*me->query("tianmo")*100)&&(me->query("tianmo")<10))
		{
		me->add("tianmo",1);
		me->set("tianmo_exp",0);
	      tell_object(me, HIW"��ġ���ħ�������������ˡ�\n"NOR);
		}
	}
}
 

int help(object me)
{
        write(YEL"\n������ħ��������֮��ħ����"NOR"\n");
	write(@HELP

      ħ�̶������书��ѧ���ܼ��о���������������Ѫ�����ս��ʱ�ı����ʡ�
	
	  ������ħ�������Ƶȼ�ÿ����ʮ�����ӳ�����ʱ��һ�롣
      ��ħ���ȼ�ÿ����һ������߱����ʰٷ�֮�塣
     

HELP
	);
	return 1;
}
