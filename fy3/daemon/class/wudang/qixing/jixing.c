// TIE@FY3
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
	string msg;
	int lvl,lv,skill;

//	if(!me->is_fighting())
//	return notify_fail("���Ƿ��еģۻ��Ǿ���ֻ������ս����ʩչ��\n");
//	if( !target ) target = offensive_target(me);
	if( !target ) target = me;

            if((int)me->query_skill("spells") < 80 )
                return notify_fail("��ķ��������ߣ�\n");
	if (!me->query("jixing"))
		me->set("jixing",1);
	lv = me->query("jixing");
	skill = me->query_skill("qixing",1);
	if (skill < 50)
		return notify_fail("������Ƿ��������ȼ���\n");

	if( !target
	||	!target->is_character()
	||	target->is_corpse() )
	
		return notify_fail("��Ҫ��˭ʩչ���������\n");

	if(target->query_temp("in_jixing"))
	return notify_fail("�����ڲ�����Ҫʩչ���Ǿ���\n");

	if((int)me->query("mana") < 300 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 50 )
		return notify_fail("��ľ���û�а취��Ч���У�\n");

	me->add("mana", -300);
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 300 ) {
		write("��ʧ���ˣ�\n");
		return 1;
	}
	msg = HIC "$N���������дʣ�һ����â��$Nͷ�������������$n��Χ��\n\n" ;
	if ( random(100)+lv*5 >= 50) 
	{
            target->add_temp("apply/damage", skill);
            target->set_temp("in_jixing", 1);
	msg +="��â����һ��������ע����$n��ȫ����\n";
        	seteuid(ROOT_UID);
	target->start_call_out( (: call_other, __FILE__, "remove_jixing",me,target, skill :),
	 lv*10+10);
	seteuid(getuid());
	me->start_busy(2);
	} else
		msg += "�������Ͼ���ʧ�ˡ�\n";
	if(me == target) 
	{
	msg = replace_string(msg, "$n","$N");
	message_vision(msg+NOR,me);
	}
	else
	message_vision(msg+NOR, me, target);
	return 1;
}

void remove_jixing(object me,object target, int lvl)
{
   target->delete_temp("in_jixing");
   target->add_temp("apply/damage",-lvl);
   message_vision(HIY "\n\n$N����һ�����ƺ��йɹ�ã������⡣\n\n" NOR, target);
	if(me->query("jixing") < (me->query("level")/10) && userp(me))
	{
	  me->add("jixing_exp",1);
	      tell_object(me, "��ġ����Ǿ��������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("jixing_exp") > (me->query("jixing")*me->query("jixing")*100)&&(me->query("jixing")<10))
		{
		me->add("jixing",1);
		me->set("jixing_exp",0);
	      tell_object(me, HIW"��ġ����Ǿ������������ˡ�\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n���Ƿ�֮���Ǿ���"NOR"\n");
	write(@HELP

      ���п�������ʩ��Ŀ�����ʱ�����˺���
	
      ���Ǿ��ȼ�ÿ����һ���������ʱ�����˺�һ�㡣
      ���Ǿ�ÿ����һ�����ӳ���������ʱ��ʮ�룬���ӳɹ���5%.

HELP
	);
	return 1;
}