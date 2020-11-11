// roar.c

#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
	object *ob;
	int i, skill, damage,lv,fekee;
	      
	skill = me->query_skill("bolomiduo",1) ;

	if( !me->is_fighting() )
		return notify_fail("�����Ͻ�գ�ֻ����ս����ʹ�á�\n");
	if( target != me ) return notify_fail("��ֻ�������Լ��ķ�����\n");

	lv = (int)me->query("roar");
	if (!lv)   
		me->set("roar",1);
	lv = (int)me->query("roar");
	if( (int)me->query("force") < 150 *lv)
		return notify_fail("�������������\n");
	fekee = (int)me->query("max_kee")/10;
	if( (int)me->query("kee") < fekee*lv)
		return notify_fail("�����Ѫ������\n");

	skill = me->query_skill("bolomiduo",1);
       if( (int)me->query_temp("wunan") )
		 return notify_fail("���Ѿ����˹����ˡ�\n");
      me->add("force", -150*lv);
	  
	  me->receive_damage("kee", fekee*lv);

	if ( random(100)+lv*5 >= 50) 
	{
       	message_vision(HIR "$N�����ͻȻӽ���ͳ����������Ͻ�շ𷨣���ʱ�е�������ü�Ӳ�ޱȣ�\n" NOR, me);
        me->add_temp("apply/defense", lv*skill/2);
        me->set_temp("wunan", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
lv*skill/2 :), lv*30);
	  me->start_busy(1);
	}
	else 
	{
	write("���ڲ�����������ʩ�����Ͻ��ʧ���ˡ�\n");
	}
	  me->start_busy(2);
        return 1;

}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/defense", - amount);
        me->delete_temp("wunan");
        tell_object(me, HIG"������Ͻ��ʧȥЧ���ˡ�\n"NOR);
	if(me->query("roar") < (me->query("level")/10) && userp(me))
	{
	      me->add("roar_exp",1);
	      tell_object(me, "��ġ����Ͻ�ա������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("roar_exp") > (me->query("roar")*me->query("roar")*100)&&(me->query("roar")<10))
		{
		me->add("roar",1);
		me->set("roar_exp",0);
	      tell_object(me, HIW"��ġ����Ͻ�ա����������ˡ�\n"NOR);
		}
	}
}
 int help(object me)
{
        write(YEL"\n�����۶��ľ�֮���Ͻ�գ�"NOR"\n");
	write(@HELP

      ������Ժ�ط��������������Ѫ����ȡ��ʱ����
	  �����۶��ľ��ȼ�ÿ�������������ӷ���һ�㡣
	  ���Ͻ�յȼ�ÿ����һ�������ӷ���һ�����ӳ�����ʱ����ʮ�롣

HELP
	);
	return 1;
}


