// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce,hit,damage,lv;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
            extra = me->query_skill("daode",1);

         if ( extra < 20) return notify_fail("��ĵ��¾���������ʮ����\n");
	if( !me->is_fighting() )
		return notify_fail("�۽�����ֻ����ս����ʹ�á�\n");
	lv = (int)me->query("jinganghuti");
	if (!lv)   me->set("jinganghuti",1);
	lv = (int)me->query("jinganghuti");

	orforce = (int) me->query("force");
	if (orforce < lv*100)
		return notify_fail("����������㡣\n");

        if( (int)me->query_temp("daode_dur") )
		 return notify_fail("���Ѿ����˹����ˡ�\n");
      me->add("force", -100*lv);
	if ( random(100)+lv*5 >= 50) 
	{
        message_vision(HIG"$N�����ؾ�������̸̸����һȦ��ɫ�Ĺ�â��\n" NOR, me);
        me->add_temp("apply/durability", extra/2 + 200*lv);
        me->set_temp("daode_dur", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
extra/2+200*lv :), 10+extra/10);
	  me->start_busy(1);
	}
	else 
	{
	write("���ڲ�����������ʩչ�����ʧ���ˡ�\n");
	}
	  me->start_busy(2);
        return 1;

}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/durability", - amount);
        me->delete_temp("daode_dur");
        tell_object(me, HIG"��Ľ����ʧȥЧ���ˡ�\n"NOR);
		if(me->query("jinganghuti") < (me->query("level")/10) && userp(me))
	{
	  me->add("jinganghuti_exp",1);
	      tell_object(me, "��ġ�����塿�����һ�㼼�������ȡ�\n"NOR);
	  if(me->query("jinganghuti_exp") > (me->query("jinganghuti")*me->query("jinganghuti")*100)&&(me->query("jinganghuti")<10))
		{
		me->add("jinganghuti",1);
		me->set("jinganghuti_exp",0);
	      tell_object(me, HIW"��ġ�����塿���������ˡ�\n"NOR);
		}
	}
}
 
int help(object me)
{
        write(YEL"\n���¾�֮����壺"NOR"\n");
	write(@HELP

      ���¾��ǰ��ƳǶ���ѧ�ʣ�ֻ�и���Ľ�ʿ���������һ��ܡ�

      ���¾����ܵȼ�ÿ�������������Ӵ���������ʱ��һ�㡣
      ���¾����ܵȼ�ÿ����ʮ�����ӳ����е�����ʱ��һ�롣
      �����ĵȼ�ÿ����һ�������Ӵ��еĳɹ���5%���Լ���ʱ�������ٵ㡣

HELP
	);
	return 1;
}