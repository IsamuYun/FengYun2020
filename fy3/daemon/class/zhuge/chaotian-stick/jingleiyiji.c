//����һ�� writted by tiandi

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me,object target)
{
        string msg;
        object weapon, weapon2;
        int skill, ap, dp, str,force,str1,force1,damage;
        skill  = me->query_skill("chaotian-stick",1);
 	 str = me->query("str");
	 force = me->query("force");
	
	 if( !target ) target = offensive_target(me);
	 if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                   return notify_fail("��"+HIY"����һ��"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	str1 = target->query("str");
	force1 = target->query("force");
         if( me->query("TASK") < 1800  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("����Ŀǰ��״���������ǲ���ʹ����һ���ˡ�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
            return notify_fail("��ʹ�õ��������ԡ�\n");
	
	 if (!objectp(weapon2 = target->query_temp("weapon")))
	        return notify_fail("��ʹ�õ�ʱ�����ԡ�\n");

        if( skill < 100)
            return notify_fail("��ĳ�����ȼ�����, ����ʹ�á�"+HIY"����һ��"NOR+"����\n");

        if( me->query("force") < 400 )
            return notify_fail("��������������޷����á�"+HIY"����һ��"NOR+"����\n");

        msg = HIR
    "\n\n$N"HIR"����Ծ��,ʹ��"+HIY"������һ����"NOR+""+HIR"��˫���ս�"NOR""+weapon->name()+""NOR+HIR"�Ӱ���г�$n"HIR"ֱ��������\nֻ��$N"HIR"���ڰ������������ߣ��������ǳ�ɳ�����ľ�Էǣ�$N"HIR"�ѽ�$n"HIR"�˱ܵĿ�϶�������ʵʵ��\n"NOR;
        
	 
        ap = random(me->query_skill("staff") + skill)*str*force;
        dp = random(target->query_skill("dodge"))*str1*force1;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            me->add("force",-400);
     	     msg += HIC"\n$n"HIC"ֻ��һ����ɽ����֮�����Լ�ӿ�������������ؼ������ˣ�����"NOR""+weapon2->name()+""HIC"˳������һ��\n��$N"HIC"����ͣϢ��һ������"NOR""+weapon2->name()+""HIC"�ϡ�\n���ֻ����������һ����$n"HIC"���е�"NOR""+weapon2->name()+""HIC"һ��Ϊ����\n"NOR;
            damage= skill+(int)me->query_str()*10;
            target->receive_damage("kee", damage, me);
	     target->receive_wound("kee", damage/3, me);
            weapon2->unwield();
	         weapon2->move(target);
	     weapon2->reset_action();
	     weapon2->set("name", "һ��Ϊ����"+ weapon2->query("name") );
	     weapon2->set("value", 0);
	     weapon2->set("weapon_prop", 0);
	         weapon2->set("no_drop",0);
	     weapon2->set("long", "һ���������������ж�Ϊ���ڣ��ƿ����룬�����Ǳ�"HIW+me->name()+NOR"���ϵġ�\n");
	         me->start_busy(3);
		}
        else
        {
            msg += NOR"����$n�������Ա�һ��,�ܹ���$N���ƴ�������һ����\n"NOR;
            me->start_busy(2);
        }
	 message_vision(msg, me, target);
        return 1;
}


