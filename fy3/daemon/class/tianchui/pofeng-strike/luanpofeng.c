// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce,hit,damage,lv;
	object weapon;
	lv = (int)me->query("luanpofeng");
	if (!lv)
		me->set("luanpofeng",1);
	lv = (int)me->query("luanpofeng");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
    extra = me->query_skill("pofeng-strike",1);
    hit = me->query_skill("literate",1);
    damage = me->query_skill("str");
         if ( extra < 20) return notify_fail("����÷��ƻ�������ʮ����\n");
         if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����÷��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	orforce = (int) me->query("force");
	if (orforce < lv*30)
		return notify_fail("����������㡣\n");
            me->add_temp("apply/attack",hit);
            me->add_temp("apply/damage",damage+lv*130);
	weapon = me->query_temp("weapon");
	me->add("force", lv*30);
	msg = HIR  "$N˫��Ѫ�죬��ָ�������������Ʒ��ƿն�����������������Ѹ���ޱȵػ���$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(2);
            me->add_temp("apply/attack",- hit);
            me->add_temp("apply/damage",-damage - lv*130);
	if(me->query("luanpofeng") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("luanpofeng_exp",1);
	      tell_object(me, "��ġ����÷硿�����һ�㼼�������ȡ�\n"NOR);
		}
	  if((me->query("luanpofeng_exp") > (me->query("luanpofeng")*me->query("luanpofeng")*100))&&(me->query("luanpofeng")< MAX_PFMLEVEL))
		{
		me->add("luanpofeng",1);
		me->set("luanpofeng_exp",0);

	      tell_object(me, HIW"��ġ����÷硿�ȼ������ˡ�\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n�÷���֮���÷磺"NOR"\n");
	write(@HELP

      ����ʹ�ú󣬵��ι����з���
HELP
	);
	write("\t��ǰ״̬���������мӳ�"+(int)(me->query_skill("literate"))+"��,�����˺��ӳ�"+(int)(me->query("str")+me->query("luanpofeng")*130)+"��\n.");
	
	write(@HELP
      ����ʶ�ּ��ܵȼ�ÿ����һ�������Ӵ�������һ�㡣
      ������������ÿ����һ�������Ӵ����˺�һ�㡣
      ���÷�ȼ�ÿ����һ�������Ӵ����˺�һ����ʮ�㡣

HELP
	);
	return 1;
}
