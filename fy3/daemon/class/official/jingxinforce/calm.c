
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
      int skill,lv;
	skill = me->query_skill("jingxinforce",1) ;

      if( target != me ) return notify_fail("��ֻ�������Լ��Ķ�����\n");
	if(skill < 10)
		return notify_fail("��ľ����ķ��ȼ�̫�͡�\n");
	lv = (int)me->query("calm");
	if (!lv)   me->set("calm",1);
	lv = (int)me->query("calm");

      if( (int)me->query("force") < (lv*100) )
	       return notify_fail("�������������\n");


        if( (int)me->query_temp("jingxin_calm") )
		 return notify_fail("���Ѿ����˹����ˡ�\n");
      me->add("force", -100*lv);
	if ( random(100)+lv*5 >= 50) 
	{
        message_vision(HIG"$N��������ȫ���Ȼ����һ�����ɣ�\n" NOR, me);
        me->add_temp("apply/composure", skill/10);
        me->set_temp("jingxin_calm", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/10 :), skill/2);
	  me->start_busy(1);
	}
	else 
	{
	write("���ڲ�����������ʩ�Ŷ����ʧ���ˡ�\n");
	}
	  me->start_busy(2);
        return 1;

}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/composure", - amount);
        me->delete_temp("jingxin_calm");
        tell_object(me, HIG"��Ķ����ʧȥЧ���ˡ�\n"NOR);
			if(me->query("calm") < (me->query("level")/10) && userp(me))
	{
	  me->add("calm_exp",1);
	      tell_object(me, "��ġ�������������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("calm_exp") > (me->query("calm")*me->query("calm")*100)&&(me->query("calm")<10))
		{
		me->add("calm",1);
		me->set("calm_exp",0);
	      tell_object(me, HIW"��ġ�����������������ˡ�\n"NOR);
		}
	}
}
 int help(object me)
{
        write(YEL"\n�����ķ�֮�������"NOR"\n");
	write(@HELP

      �����ʹ�ú󣬿��������������ʱ������

      �����ķ����ܵȼ�ÿ����ʮ�������Ӵ��ж�����ʱ��һ�㡣
      ������ĵȼ�ÿ����һ�������Ӵ��еĳɹ���5%��

HELP
	);
	return 1;
}

