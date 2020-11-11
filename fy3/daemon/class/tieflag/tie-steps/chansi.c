// chansi.c
//written by kouga
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        int skill,lv;
	string msg;
	object weapon;
	lv = me->query("chansi");
	if (!lv)  me->set("chansi",1);
	lv = me->query("chansi");

	skill = me->query_skill("tie-steps",1);
	if(skill < 100) return notify_fail("�����Ѫʮ����̫���ˣ�\n"); 
	if( !target ) target = offensive_target(me);	
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۲�˿�ƣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
        if( (int)me->query("force") < 100*lv )     return
        notify_fail("�������������\n");
        if( (int)target->query_temp("chansi") ) return 
	notify_fail("���Ѿ���ʩչ�۲�˿�ƣ��ˡ�\n");
       	if(random((int)target->query("level")) < random((int)me->query("level"))+lv)
	{
		me->add("force", -100*lv);
        	message_vision( HIR
		"$N����һԾ��ʹ���۲�˿�ƣݣ�$n�����������Ӱ�죬�����ɬ������\n" NOR, me,target);
        	target->add_temp("apply/dodge", -skill*2);
		target->add_temp("apply/parry",-skill*2);       
        	target->set_temp("chansi", 1);
        	seteuid(ROOT_UID);
        	target->start_call_out( (: call_other, __FILE__, "remove_effect", me,target, 
-skill*2 :), lv*10);
			seteuid(getuid());
        	me->start_busy(4);
	}
	else
	{
		msg = "��ϧ$N������$n����������ѸȻ������";
		COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
        	me->start_busy(2);
	}
        return 1;
}

void remove_effect(object me,object target, int amount)
{
        target->add_temp("apply/dodge", - amount);
	target->add_temp("apply/parry",- amount);
        target->delete_temp("chansi");
        message_vision("$N���ڰ����ˣ۲�˿�ƣݵ�Ӱ�졣\n",target);
		if(me->query("chansi") < (target->query("level")/10) && !userp(target))
	{
	  me->add("chansi_exp",1);
	      tell_object(me, "��ġ���˿�ơ������һ�㼼�������ȡ�\n"NOR);
	  if(me->query("chansi_exp") > (me->query("chansi")*me->query("chansi")*100)&&(me->query("chansi")<10))
		{
		me->add("chansi",1);
		me->set("chansi_exp",0);
	      tell_object(me, HIW"��ġ���˿�ơ����������ˡ�\n"NOR);
		}
	}
}
int help(object me)
{
        write(YEL"\n��Ѫ֮��˿�ƣ�"NOR"\n");
	write(@HELP

      ���п��Լ���ʩ��Ŀ�����ʱ�����������������������
	
      ��Ѫʮ��ʽ�ȼ�ÿ����һ�������Ŀ������������㡣
      ��˿��ÿ����һ�����ӳ���������ʱ��ʮ�룬��������ɹ���.

HELP
	);
	return 1;
}

 
