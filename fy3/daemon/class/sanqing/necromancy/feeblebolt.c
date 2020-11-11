// feeblebolt.c

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam,lv;
	if( !target ) target = offensive_target(me);
	 lv = (int)me->query("feeblebolt");
	if (!lv)   me->set("feeblebolt",1);
	lv = (int)me->query("feeblebolt");

        if((int)me->query_skill("spells") < 550 )
                return notify_fail("��ķ��������ߣ�\n");

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("��Ҫ��˭ʩչ���������\n");

	if((int)me->query("mana") < 155*lv )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("��ľ���û�а취��Ч���У�\n");

	me->add("mana", -155*lv);
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("��ʧ���ˡ�\n");
		return 1;
	}
	msg = HIW "$N�����૵��������ģ�����һ�ӣ����о���һ�Ű׹�����$n��\n\n" NOR;

	ap = me->query_skill("spells");
	ap += me->query_skill("taoism",1);
	extradam = ap/2;
	dp = target->query("level")*10;
	if( random(ap + dp) > dp ) {
		damage = (int)me->query("max_mana") / 10 + random((int)me->query("eff_sen") / 10) + random(extradam);
		damage -= (int)target->query("max_mana") / 30 + random((int)target->query("eff_sen") / 15);
		if( damage > 0 ) {
			msg +=  HIR "������͡���һ�����׹��$p����͸��������ϳ�һ�������ĺ���ֱ�䵽\n"
					"��������ĵ��£�\n" NOR;
			target->receive_damage("kee", damage, me);
			target->receive_wound("kee", damage/3*lv+damage, me);
			me->improve_skill("necromancy", 1, 1);
		} else
			msg += "������͡���һ�����׹��$p����͸�������������Ϣ��������£�\n";
	} else
		msg += "���Ǳ�$n�㿪�ˡ�\n";

	message_vision(msg, me, target);
	if( damage > 0 )
		{
		 COMBAT_D->report_status(target);
	if(me->query("feeblebolt") < (target->query("level")/10) && !userp(target))
	{
    	    me->add("feeblebolt_exp",1);
	      tell_object(me, "��ġ�����֮���������һ�㼼�������ȡ�\n"NOR);
	}
	  if(me->query("feeblebolt_exp") > (me->query("feeblebolt")*me->query("feeblebolt")*100)&&(me->query("feeblebolt")<10))
		{
		me->add("feeblebolt",1);
		me->set("feeblebolt_exp",0);
	      tell_object(me, HIW"��ġ�����֮�������������ˡ�\n"NOR);
		}
	if (random(100) <lv)
		{
		target->apply_condition("sanqing_drug",random(10)+10);
		target->set("statusnow","�κ���");
		message_vision(HIG"$N�Ĳ���֮�������⹦Ч������$n���Ͽ�ʼ�����ˡ�\n"NOR,me,target);
		}
	}
	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else 				target->kill_ob(me);
		}
		me->kill_ob(target);
	}

	me->start_busy(2);
	return 1;
}
 int help(object me)
{
        write(YEL"\n�������֮����֮��"NOR"\n");
	write(@HELP

���һ����ɫ�����������ˣ�ʹ���˲�
����ѣ���˺���ֻ�е��и���ķ�ʦ����ᡣ

     ����֮��ÿ����һ�����˺�Ч������һ�ɣ���ѣ�ļ�������1%��

HELP
	);
	return 1;
}




