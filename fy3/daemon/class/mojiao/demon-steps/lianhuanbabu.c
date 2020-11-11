// powerup.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target, int amount)
{
        int skill,lv;

        if( target != me ) return 
	notify_fail("��ֻ�������Լ��ı��ʡ�\n");

        if( (int)me->query_temp("lianhuanbabu") ) return 
	notify_fail("���Ѿ����˹����ˡ�\n");
        skill = me->query_skill("demon-steps",1);
	if(skill < 50) return notify_fail("��������ħ����̫���ˣ�\n");
	lv = (int)me->query("lianhuanbabu");
	if (!lv)   me->set("lianhuanbabu",1);
	lv = (int)me->query("lianhuanbabu");
        if( (int)me->query("force") < 100*lv )     return notify_fail("�������������\n");
      	me->add("force", -100*lv);
	if ( random(100)+lv*5 >= 50) 
	{
        message_vision(
                HIY 
"$Nʹ�������ħ�����˲����Ų��������仯�˰˸����ƣ�˲�佫�����ħ�������ӵ����£���\n" NOR, me);
        me->add_temp("apply/heavyhit", skill/20);
        me->set_temp("lianhuanbabu", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/20 :), skill/2);
	 me->start_busy(1);
	}
	else 
	{
	write("���ڲ�����������ʩ�������ħ�����˲�ʧ���ˡ�\n");
	}
	  me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/heavyhit", - amount);
        me->delete_temp("lianhuanbabu");
        tell_object(me,HIG "��������ħ�����˲�ʧȥЧ���ˣ�����������и��������\n"NOR);
		if(me->query("lianhuanbabu") < (me->query("level")/10) && userp(me))
	{
	  me->add("lianhuanbabu_exp",1);
	      tell_object(me, "��ġ������ħ�����˲��������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("lianhuanbabu_exp") > (me->query("lianhuanbabu")*me->query("lianhuanbabu")*100)&&(me->query("lianhuanbabu")<10))
		{
		me->add("lianhuanbabu",1);
		me->set("lianhuanbabu_exp",0);
	      tell_object(me, HIW"��ġ������ħ�����˲������������ˡ�\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n�����ħ����֮�����ħ�����˲���"NOR"\n");
	write(@HELP

      �����ħ������ħ�̵ľ�����ѧ��

      �����ħ�������ܵȼ�ÿ������ʮ�������Ӵ�����ʱ������һ�㡣
      �����ħ�������ܵȼ�ÿ�����������ӳ����е�����ʱ��һ�롣
      �����ħ�����˲��ȼ�ÿ����һ�������Ӵ��еĳɹ���5%��

HELP
	);
	return 1;
}
 
