#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,hit,damage,okee,lv;
        object weapon;
        extra = me->query_skill("bloodystrike",1);
        if ( extra < 100) return notify_fail("������ڴ���ӡ���������죡\n");
        if( !target ) target = offensive_target(me);
		hit = me->query_skill("bloodystrike",1);
		damage = me->query_skill("bloodystrike",1);
		lv = me->query("fefawubian");
		if (!lv)
			me->set("fefawubian",1);
		lv = me->query("fefawubian");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۷��ޱߣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

		if (me->query("force")< lv*100)
			 return notify_fail("�������������\n");

        me->add_temp("apply/attack",hit*2);
        me->add_temp("apply/damage",damage/10);
		weapon = me->query_temp("weapon");

		me->add("force", -lv*100);
        msg = HIR "$Nʹ�����ڴ���ӡ�еģ۷��ޱߣݣ��ó�������Ӱ����$n��" NOR;

		okee= target->query("kee");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

            me->add_temp("apply/attack",-hit*2);
            me->add_temp("apply/damage",-damage/10);

		if(target->query("kee") < okee && target->query("level")<extra/10)
		{
		message_vision(HIB"$N��$n�ķ����⣬��ʱ�޷�ʹ���κ�ҩƷ�ˣ�\n"NOR,target,me);
		if (!target->query_temp("no_eat"))
			{
       			target->set_temp("no_eat", 1);
				target->remove_call_out("remove_effect");
		        seteuid(ROOT_UID);
			target->start_call_out( (: call_other, __FILE__, "remove_effect", target, 100*lv :), extra/10);
				seteuid(getuid());
			}
		}
	if(me->query("fefawubian") <= (target->query("level")/10) && !userp(target))
		{
	 	 me->add("fefawubian_exp",1);
	      tell_object(me, "��ġ����ޱߡ������һ�㼼�������ȡ�\n"NOR);
		}
	  if(me->query("fefawubian_exp") > (me->query("fefawubian")*me->query("fefawubian")*100)&&(me->query("fefawubian")<MAX_PFMLEVEL))
		{
		me->add("fefawubian",1);
		me->set("fefawubian_exp",0);
	      tell_object(me, HIW"��ġ����ޱߡ��ȼ������ˡ�\n"NOR);
		}

        me->start_busy(2);
        return 1;
}
void remove_effect(object target, int amount)
{	
        target->delete_temp("no_eat");
        message_vision(HIG"������$N���ϵķ�ӡ����ʧЧ�ˡ�\n"NOR,target);
}
int help(object me)
{
        write(YEL"\n���ڴ���ӡ֮���ޱߣ�"NOR"\n");
	write(@HELP

      ����������Ϊ��ͨ����������Ч��ȴ��ʹ��˲��������

      ���ڴ���ӡ���ܵȼ�ÿ����һ�������Ӵ����������㣬��΢����˺���
      ���ڴ���ӡ���ܵȼ�ÿ����ʮ�����ӳ���������һ�롣
      ���ޱߵĵȼ�ÿ����һ�����������ӶԵ���Ч�ȼ�ʮ����

HELP
	);
	return 1;
}