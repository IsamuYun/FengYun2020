// powerup.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill,lv;

        if( target != me ) return 
	notify_fail("��ֻ�ܶ��Լ�ʹ�û��ľ���\n");

        if( (int)me->query_temp("huixin") ) return 
	notify_fail("���Ѿ����˹����ˡ�\n");
        skill = me->query_skill("taijiforce",1);
	if(skill < 20) return notify_fail("���̫���ķ�̫���ˣ�\n");
	lv = (int)me->query("huixin");
	if (!lv)   me->set("huixin",1);
	lv = (int)me->query("huixin");
        if( (int)me->query("force") < 100*lv )     return notify_fail("�������������\n");
      	me->add("force", -100*lv);
	if ( random(100)+lv*5 >= 50) 
	{
        message_vision(
                HIY 
"$N����������֮������һ�������˺������ĵ�״̬��\n" NOR, me);
        me->add_temp("apply/karma", skill/10);
        me->set_temp("huixin", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/10 :), skill/2);
	 me->start_busy(1);
	}
	else 
	{
	write("���ڲ�����������ʩ�Ż��ľ�ʧ���ˡ�\n");
	}
	  me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/karma", - amount);
        me->delete_temp("huixin");
        tell_object(me,HIG "��Ļ��ľ�ʧȥЧ���ˣ�����������и��������\n"NOR);
		if(me->query("huixin") < (me->query("level")/10) && userp(me))
	{
	  me->add("huixin_exp",1);
	      tell_object(me, "��ġ����ľ��������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("huixin_exp") > (me->query("huixin")*me->query("huixin")*100)&&(me->query("huixin")<10))
		{
		me->add("huixin",1);
		me->set("huixin_exp",0);
	      tell_object(me, HIW"��ġ����ľ������������ˡ�\n"NOR);
		}
	}
}
 
int help(object me)
{
        write(YEL"\n̫���ķ�֮���ľ���"NOR"\n");
	write(@HELP

      ����Ϊ̫���ķ��Ļ�����ʹ�ú�����������ʱ������
	
      ̫���ķ����ܵȼ�ÿ����ʮ����������ʱ����һ�㡣
      ̫���ķ����ܵȼ�ÿ�����������ӳ���������ʱ��һ�롣
      ���ľ��ȼ�ÿ����һ�������Ӽ��ܳɹ���5%.
HELP
	);
	return 1;
}

