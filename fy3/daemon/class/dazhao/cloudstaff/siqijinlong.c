// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int hit,damage,lv,orforce,extra;
	object weapon;
	lv = (int)me->query("siqijinlong");
	if (!lv)
		me->set("siqijinlong",1);
	lv = (int)me->query("siqijinlong");
	if (me->query("level")< 40)
		return notify_fail("�������ȼ�������\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	orforce = (int) me->query("force");
	if (orforce < lv*50)
		return notify_fail("����������㡣\n");
	me->add("force", -lv*50);
	hit = me->query_skill("literate",1/2);
    damage = me->query_skill("cloudstaff",1);
	extra = me->query_skill("buddhism") / 10;
	me->add_temp("apply/attack", hit);	
	me->add_temp("apply/damage", damage+extra+lv*50);
	msg = HIR  "$N�ͺ���ţ���������˫�ۣ��趯���е�"+ weapon->name() +"����������ݵ�һ�� ##������Ұ##������������$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIG  "$N΢̽˫�ۣ�ƾ��һ��,���е�"+ weapon->name() +"��׼$nʹ������������ݵĵڶ���  ##��������##  ��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIC  "$Nһ����Х����Ȼ̽�����е�"+ weapon->name() +"ʹ������������ݵ����� ##������Ԩ## �� �ó��������׷���������������$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIY  "$N�����е�"+ weapon->name() +"�趯��ɣ���$nʹ������������ݵ����� ##�������## ��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -hit);
	me->add_temp("apply/damage", -damage-extra-lv*50);
	me->start_busy(4);
	if(me->query("siqijinlong") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("siqijinlong_exp",1);
	      tell_object(me, "��ġ���������������һ�㼼�������ȡ�\n"NOR);
		}
	  if((me->query("siqijinlong_exp") > (me->query("siqijinlong")*me->query("siqijinlong")*100))&&(me->query("siqijinlong")< MAX_PFMLEVEL))
		{
		me->add("siqijinlong",1);
		me->set("siqijinlong_exp",0);

	      tell_object(me, HIW"��ġ�����������ȼ������ˡ�\n"NOR);
		}
	return 1;
}
int help(object me)
{
        write(YEL"\n�����ȷ�֮���������"NOR"\n");
	write(@HELP

      ����ʹ�ú�һ���Ķι����з���

      ����ʶ�ּ��ܵȼ�ÿ�������������Ӵ�������һ�㡣
      �����ȷ����ܵȼ�ÿ����һ�������Ӵ����˺�һ�㡣
      ��˷𷨼��ܵȼ�ÿ����ʮ�������Ӵ����˺������и�һ�㡣
      ��������ȼ�ÿ����һ�������Ӵ����˺���ʮ�㡣

HELP
	);
	return 1;
}