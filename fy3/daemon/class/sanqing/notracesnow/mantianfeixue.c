// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill,lv;
      
	lv = (int)me->query("mantianfeixue");
	if (!lv)   me->set("mantianfeixue",1);
	lv = (int)me->query("mantianfeixue");

        if( (int)me->query("force") < 100*lv )     return
        notify_fail("�������������\n");
        if( (int)me->query_temp("feixue") ) return 
	notify_fail("���Ѿ���ʩչ�������ѩ���ˡ�\n");
	skill = me->query_skill_eff_lvl("notracesnow");
	if(skill < 100) return notify_fail("���̤ѩ�޺�̫���ˣ�\n");
	 me->add("force", -100*lv);

	if ( random(100)+lv*5 >= 50) 
	{

        message_vision( HIR
"$N�й����������о�Ȼ��������������е�ѩ����\n" NOR, me);
        me->add_temp("apply/dodge", skill);
        me->set_temp("feixue", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill :), skill/10+10);
	}
	else 
		return notify_fail("���ڲ�����������ʧ���ˡ�\n");
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("feixue");
        tell_object(me, "��ģ������ѩ��ʩչ��ϣ������ȶ���������\n");
		if(me->query("mantianfeixue") < (me->query("level")/10) && userp(me))
	{
	  me->add("mantianfeixue_exp",1);
	      tell_object(me, "��ġ������ѩ�������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("mantianfeixue_exp") > (me->query("mantianfeixue")*me->query("mantianfeixue")*100)&&(me->query("mantianfeixue")<10))
		{
		me->add("mantianfeixue",1);
		me->set("mantianfeixue_exp",0);
	      tell_object(me, HIW"��ġ������ѩ�����������ˡ�\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n̤ѩ�޺�֮�����ѩ��"NOR"\n");
	write(@HELP

      ����ʹ�ú��������������������㣬��ս��״̬�¿���ʹ�á�

      ̤ѩ�޺ۼ��ܵȼ�ÿ����һ�������Ӵ�������������ʱ��һ�㡣
      ̤ѩ�޺ۼ��ܵȼ�ÿ����ʮ�����ӳ����е�����ʱ��һ�롣
      �����ѩ�ȼ�ÿ����һ�������Ӵ��еĳɹ���5%��

HELP
	);
	return 1;
}


 
