// five.c writted by tiandi

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target)
{
	  string msg;
		int damage, ap, dp;
		int extradam;
        if( !me->is_fighting() )
                return notify_fail("[��ľˮ����]ֻ����ս����ʹ�á�\n");
		if( !target ) target = offensive_target(me);
		if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("��Ҫ��˭ʩչ���������\n");

        if( (int)me->query("force") - (int)me->query("max_force") < 300 )
                return notify_fail("�������������\n");
      
        msg=  me->name() + 
"��æ��ͻȻ���һ�����ŲȰ��Բ������������дʡ�"+HIY+"��----"+HIB+"ľ----"+HIC+"ˮ----"+HIR+"��----"+HIM+"��----"+NOR+"����\n\n";
      		message_vision(msg, me);
          
	 if( !me->query_temp("five")||me->query_temp("five")==0)
		{
		msg=HIY"     ������������������  [��]  ������������������\n\n"NOR;
		me->add_temp("five",1);
      		}
	else  if( me->query_temp("five")==1)
			{
			msg=HIB"     ������������������  [ľ]  ������������������\n\n"NOR;

			me->add_temp("five",1);
      		}
	else  if( me->query_temp("five")==2)
			{
			msg=HIC"     ������������������  [ˮ]  ������������������\n\n"NOR;

			me->add_temp("five",1);
      		}
	else  if( me->query_temp("five")==3)
			{
			msg=HIR"     ������������������  [��]  ������������������\n\n"NOR;

			me->add_temp("five",1);
      		}
	else  if( me->query_temp("five")==4)
			{
			msg=HIM"     ������������������  [��]  ������������������\n\n"NOR;

			me->set_temp("five",0);
      		}
		ap = me->query_skill("force");
		extradam = ap/2;
		ap = ( ap * ap /100 * ap / 4 ) * (int)me->query("sen") ;
		dp = target->query("combat_exp");
		if( random(ap + dp) > dp ) {
		damage = (int)me->query("max_mana") / 40 + random((int)me->query("eff_sen") / 20) + random(extradam);
		damage -= (int)target->query("max_mana") / 30 + random((int)me->query("eff_sen") / 15);
		if( damage/2 > 0 ) {
			msg +=  "������͡���һ����$n����Ī���������Ѫ�ˣ�\n"NOR;
			target->receive_damage("kee", damage);
			target->receive_wound("kee", damage/3);
			} else
			msg += "������͡���һ������âһ�����š�����\n"NOR;
	} else
		msg += "���Ǳ�$n�㿪�ˡ�\n"NOR;
		message_vision(msg, me,target);
		if( damage/2 > 0 ) COMBAT_D->report_status(target);
		me->add("force",-300);
		me->start_busy(2);
        return 1;
}
 
