// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce,hit,damage,lv;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
            extra = me->query_skill("liuyun-steps",1);

         if ( extra < 20) return notify_fail("������Ʋ�����������ʮ����\n");
	if( !me->is_fighting() )
		return notify_fail("��������ˮ��ֻ����ս����ʹ�á�\n");
	lv = (int)me->query("xingyunliushui");
	if (!lv)   me->set("xingyunliushui",1);
	lv = (int)me->query("xingyunliushui");

	orforce = (int) me->query("force");
	if (orforce < lv*100)
		return notify_fail("����������㡣\n");

        if( (int)me->query_temp("liuyun_dodge") )
		 return notify_fail("���Ѿ����˹����ˡ�\n");
      me->add("force", -100*lv);
	if ( random(100)+lv*5 >= 50) 
	{
        message_vision(HIG"$N��Ȼ���÷�������Ư�����ƣ�����������ˮһ����޶��ʣ�\n" NOR, me);
        me->add_temp("apply/dodge", extra/2);
        me->set_temp("liuyun_dodge", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
extra/2 :), 10+extra/10);
	  me->start_busy(1);
	}
	else 
	{
	write("���ڲ�����������ʩչ������ˮʧ���ˡ�\n");
	}
	  me->start_busy(2);
        return 1;

}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("liuyun_dodge");
        tell_object(me, HIG"���������ˮʧȥЧ���ˡ�\n"NOR);
			if(me->query("xingyunliushui") < (me->query("level")/10) && userp(me))
	{
	  me->add("xingyunliushui_exp",1);
	      tell_object(me, "��ġ�������ˮ�������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("xingyunliushui_exp") > (me->query("xingyunliushui")*me->query("xingyunliushui")*100)&&(me->query("xingyunliushui")<10))
		{
		me->add("xingyunliushui",1);
		me->set("xingyunliushui_exp",0);
	      tell_object(me, HIW"��ġ�������ˮ�����������ˡ�\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n���Ʋ���֮������ˮ��"NOR"\n");
	write(@HELP

      ���Ʋ����ǳ�͢�����Ĳ���������ʹ�ú��������������������㡣

      ���Ʋ������ܵȼ�ÿ�������������Ӵ�������������ʱ��һ�㡣
      ���Ʋ������ܵȼ�ÿ����ʮ�����ӳ����е�����ʱ��һ�롣
      ������ˮ�ȼ�ÿ����һ�������Ӵ��еĳɹ���5%��

HELP
	);
	return 1;
}

