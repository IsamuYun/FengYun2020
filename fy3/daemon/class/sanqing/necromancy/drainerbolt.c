// drainerbolt.c

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam,lv;
	if( !target ) target = offensive_target(me);
	 lv = (int)me->query("drainerbolt");
	if (!lv)   me->set("drainerbolt",1);
	lv = (int)me->query("drainerbolt");



	if((int)me->query_skill("spells") < 20 )
		return notify_fail("��ķ��������ߣ�\n");

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("��Ҫ��˭ʩչ���������\n");

	if((int)me->query("mana") < 25*lv )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 20*lv )
		return notify_fail("��ľ���û�а취��Ч���У�\n");

	me->add("mana", -25*lv);
	me->receive_damage("sen", 20*lv);

	if( random(me->query("max_mana")) < 20 ) {
		write("��ʧ���ˡ�\n");
		return 1;
	}

	msg = HIM "$N�����૵��������ģ�����һ�ӣ����о���һ���Ϲ�����$n��\n\n" NOR;

	ap = me->query_skill("spells");
	ap += me->query_skill("taoism",1);
	extradam = ap/2;
	dp = target->query("level")*10;
	if( random(ap + dp) > dp ) {
		damage = (int)me->query("max_mana") / 40 + random((int)me->query("eff_sen") / 20) + random(extradam);
		damage -= (int)target->query("max_mana") / 30 + random((int)target->query("eff_sen") / 15);
		if( damage > 0 ) {
			msg +=  HIR "������͡���һ�����Ϲ��$p����͸��������ϳ�һ���������߲ʹ�������������\n"
					"��ת�����ִ�$N����ע��$P�����ڣ�\n" NOR;
			me->receive_heal("gin", target->receive_damage("gin", damage, me));
			target->receive_wound("gin", damage/3*lv, me);
			me->improve_skill("necromancy", 1, 1);
	if(me->query("drainerbolt") < (target->query("level")/10) && !userp(target))
	{
    	    me->add("drainerbolt_exp",1);
	      tell_object(me, "��ġ�����֮���������һ�㼼�������ȡ�\n"NOR);
	}
	  if(me->query("drainerbolt_exp") > (me->query("drainerbolt")*me->query("drainerbolt")*100)&&(me->query("drainerbolt")<10))
		{
		me->add("drainerbolt",1);
		me->set("drainerbolt_exp",0);
	      tell_object(me, HIW"��ġ�����֮�������������ˡ�\n"NOR);
		}

		} else
			msg += "������͡���һ�����Ϲ��$p����͸�������������Ϣ��������£�\n";
	} else
		msg += "���Ǳ�$n�㿪�ˡ�\n";

	message_vision(msg, me, target);
	if( damage > 0 ) COMBAT_D->report_status(target);

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

     ���һ����ɫ�����������ˣ�
���ǳɹ�������ӵ���������ȡ���ɾ�����


     ����֮��ÿ����һ�����˺�Ч������һ�ɡ�

HELP
	);
	return 1;
}

