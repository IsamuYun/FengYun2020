// netherbolt.c

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int damage, ap, dp;
	int extradam,lv;

	if( !target ) target = offensive_target(me);
	 lv = (int)me->query("netherbolt");
	if (!lv)   me->set("netherbolt",1);
	lv = (int)me->query("netherbolt");

        if((int)me->query_skill("spells") < 130 )
                return notify_fail("��ķ��������ߣ�\n");

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("��Ҫ��˭ʩչ���������\n");

	if((int)me->query("mana") < 55*lv )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 10*lv )
		return notify_fail("��ľ���û�а취��Ч���У�\n");

	me->add("mana", -50*lv);
	me->receive_damage("sen", 10*lv);

	if( random(me->query("max_mana")) < 30 ) {
		write("��ʧ���ˣ�\n");
		return 1;
	}

	msg = HIC "$N�����૵��������ģ�����һ�ӣ����о���һ���������$n��\n\n" NOR;

	ap = me->query_skill("spells");
	ap += me->query_skill("taoism",1);
	extradam = ap;
	dp = target->query("level")*10;
	if( random(ap + dp) > dp ) {
		damage = (int)me->query("level") * 20 + random((int)me->query("eff_sen") / 20) + random(extradam);
		damage -= (int)target->query("level") * 20 + random((int)target->query("eff_sen") / 20);
		if( damage > 0 ) {
			msg +=  HIR "������͡���һ��������$p����͸��������ϳ�һ��������Ѫ��ֱ�䵽\n"
					"��������ĵ��£�\n" NOR;

			target->receive_damage("kee", damage*3, me);
			target->receive_wound("kee", damage/3*lv, me);
			me->improve_skill("necromancy", 1, 1);
	if(me->query("netherbolt") < (target->query("level")/10) && !userp(target))
	{
    	    me->add("netherbolt_exp",1);
	      tell_object(me, "��ġ���ڤ֮���������һ�㼼�������ȡ�\n"NOR);
	}
	  if(me->query("netherbolt_exp") > (me->query("netherbolt")*me->query("netherbolt")*100)&&(me->query("netherbolt")<10))
		{
		me->add("netherbolt",1);
		me->set("netherbolt_exp",0);
	      tell_object(me, HIW"��ġ���ڤ֮�������������ˡ�\n"NOR);
		}

		} else
			msg += "������͡���һ��������$p����͸�������������Ϣ��������£�\n";
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
        write(YEL"\n�������֮��ڤ֮��"NOR"\n");
	write(@HELP

 ���һ����ɫ�����������ˣ��������
����ڤ������ɱ�����ϸߵ�һ�������������ɳ������ӵ�����Ҳ�����ԡ�


     ��ڤ֮��ÿ����һ�����˺�Ч������һ�ɡ�

HELP
	);
	return 1;
}

