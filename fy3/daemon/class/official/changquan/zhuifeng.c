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
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
    extra = me->query_skill("changquan",1);
    hit = me->query_skill("literate",1);
    damage = me->query_skill("strategy",1);
         if ( extra < 20) return notify_fail("������ֳ�ȭ��������ʮ����\n");
	lv = (int)me->query("zhuifeng");
	if (!lv)
		me->set("zhuifeng",1);
	lv = (int)me->query("zhuifeng");

         if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��׷���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	orforce = (int) me->query("force");
	if (orforce < lv*20)
		return notify_fail("����������㡣\n");
            me->add_temp("apply/attack",hit);
            me->add_temp("apply/damage",damage + lv*100);
	weapon = me->query_temp("weapon");
	me->add("force", -extra/2);
	msg = HIY  "$N����ֱ�룬һ�����ֳ�ȭ�еģ�׷���ʹ�����쾡�£������������$n������" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(2);
            me->add_temp("apply/attack",- hit);
            me->add_temp("apply/damage",-damage - lv*100);
	if(me->query("zhuifeng") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("zhuifeng_exp",1);
	      tell_object(me, "��ġ�׷�硿�����һ�㼼�������ȡ�\n"NOR);
		}
	  if((me->query("zhuifeng_exp") > (me->query("zhuifeng")*me->query("zhuifeng")*100))&&(me->query("zhuifeng")< MAX_PFMLEVEL))
		{
		me->add("zhuifeng",1);
		me->set("zhuifeng_exp",0);

	      tell_object(me, HIW"��ġ�׷�硿�ȼ������ˡ�\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n���ֳ�ȭ֮׷�磺"NOR"\n");
	write(@HELP

      ����ʹ�ú󣬵��ι����з���

      ����ʶ�ּ��ܵȼ�ÿ����һ�������Ӵ�������һ�㡣
      �������ܵȼ�ÿ����һ�������Ӵ����˺�һ�㡣
      ׷��ȼ�ÿ����һ�������Ӵ����˺�һ�ٵ㡣

HELP
	);
	return 1;
}
