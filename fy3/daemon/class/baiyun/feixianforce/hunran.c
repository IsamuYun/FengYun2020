// powerup.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill,lv;

        if( target != me ) return 
	notify_fail("��ֻ�������Լ�������������\n");

        if( (int)me->query_temp("hunran") ) return 
	notify_fail("���Ѿ����˹����ˡ�\n");
		if (me->query("hunrantime")-time()>0)
			return notify_fail("����Ƶ��ʹ�ô��У��������ʹ�á�\n");
        skill = me->query_skill("feixianforce",1);
	if(skill < me->query("level")*9 ) return notify_fail("��ķ��ɾ�̫���ˣ�\n");
	lv = (int)me->query("hunran");
	if (!lv)   me->set("hunran",1);
	lv = (int)me->query("hunran");
        if( (int)me->query("force") < 500 + 100*lv )     return notify_fail("�������������\n");
      	me->add("force", -500-100*lv);
	if ( random(100)+lv*5 >= 50) 
	{
        message_vision(
                HIC 
"$N������ɾ���˫�ֳ�����״���ػ�������ǰ���ݵ�һ��һ������⻷������$N����\n" NOR, me);
        me->add_temp("apply/dodge",999999 );
        me->set_temp("hunran", 1);
		me->set("hunrantime", (int) time()+ 3600);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
999999 :), 10+lv*6);
	}
	else 
	{
	write("���ڲ�����������ʩ�Ż�Ȼ���ʧ���ˡ�\n");
	}
	  me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("hunran");
        tell_object(me,HIG "��Ļ�Ȼ���ȥЧ���ˣ�����������и��������\n"NOR);
		if(me->query("hunran") < (me->query("level")/10) && userp(me))
	{
	  me->add("hunran_exp",1);
	      tell_object(me, "��ġ���Ȼ��ɡ������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("hunran_exp") > (me->query("hunran")*me->query("hunran")*100)&&(me->query("hunran")<10))
		{
		me->add("hunran",1);
		me->set("hunran_exp",0);
	      tell_object(me, HIW"��ġ���Ȼ��ɡ����������ˡ�\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n���ɾ�֮��Ȼ��ɣ�"NOR"\n");
	write(@HELP

      ���ɾ�����߾��磬˲������������������޵о��硣

      ���ɾ����ܵȼ������������ȼ��ľű��ſ�ʹ�ô��С�
      ���ڴ���̫���Ե�������һСʱ��ֻ��ʹ��һ�Ρ�
      ��Ȼ��ɵȼ�ÿ����һ�������Ӵ��еĳɹ���5%�Լ�����ʱ�����롣

HELP
	);
	return 1;
}
 
