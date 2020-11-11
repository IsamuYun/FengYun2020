// powerup.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill,lv;

        if( target != me ) return 
	notify_fail("��ֻ�������Լ����ٶȡ�\n");

        if( (int)me->query_temp("speedup") ) return 
	notify_fail("���Ѿ����˹����ˡ�\n");
        skill = me->query_skill("jingyiforce");
	if(skill < 20) return notify_fail("��ľ����ķ�̫���ˣ�\n");
	lv = (int)me->query("speedup");
	if (!lv)   me->set("speedup",1);
	lv = (int)me->query("speedup");
        if( (int)me->query("force") < 100*lv )     return notify_fail("�������������\n");
      	me->add("force", -100*lv);
	if ( random(100)+lv*5 >= 50) 
	{
        message_vision(
                HIR 
"$N�����ؾ������������˴���һ��������״̬��\n" NOR, me);
        me->add_temp("apply/agility", skill/10);
        me->set_temp("speedup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/10 :), skill/2);
	 me->start_busy(1);
	}
	else 
	{
	write("���ڲ�����������ʩ�ż���ʧ���ˡ�\n");
	}
	  me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/agility", - amount);
        me->delete_temp("speedup");
        tell_object(me,HIG "��ļ���ʧȥЧ���ˣ�����������и��������\n"NOR);
		if(me->query("speedup") < (me->query("level")/10) && userp(me))
	{
	  me->add("speedup_exp",1);
	      tell_object(me, "��ġ������������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("speedup_exp") > (me->query("speedup")*me->query("speedup")*100)&&(me->query("speedup")<10))
		{
		me->add("speedup",1);
		me->set("speedup_exp",0);
	      tell_object(me, HIW"��ġ����������������ˡ�\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n�����ķ�֮������"NOR"\n");
	write(@HELP

      �����ķ��ǰ��Ƴ��ķ��Ļ�����

      �����ķ����ܵȼ�ÿ����ʮ�������Ӵ����ٶ���ʱ��һ�㡣
      �����ķ����ܵȼ�ÿ�����������ӳ����е�����ʱ��һ�롣
      �����ȼ�ÿ����һ�������Ӵ��еĳɹ���5%��

HELP
	);
	return 1;
}
 
