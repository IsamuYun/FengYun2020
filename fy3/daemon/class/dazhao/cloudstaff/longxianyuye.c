// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int hit,damage,lv,orforce;
	object weapon;
	lv = (int)me->query("longxianyuye");
	if (!lv)
		me->set("longxianyuye",1);
	lv = (int)me->query("longxianyuye");
	extra = me->query_skill("buddhism",1);
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������Ұ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	orforce = (int) me->query("force");
	if (orforce < lv*20)
		return notify_fail("����������㡣\n");
	me->add("force", -lv*20);
    hit = me->query_skill("literate",1);
    damage = me->query_skill("cloudstaff",1);
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack", hit+lv*100);	
	me->add_temp("apply/damage", damage/2+extra/5);
	msg = HIR  "$N�ͺ���ţ���������˫�ۣ����е�"+ weapon->name() +HIR"�ó�һ�����׷���������������$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -hit-lv*100);
	me->add_temp("apply/damage", -damage/2-extra/5);
	me->start_busy(2);
	if(me->query("longxianyuye") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("longxianyuye_exp",1);
	      tell_object(me, "��ġ�������Ұ�������һ�㼼�������ȡ�\n"NOR);
		}
	  if((me->query("longxianyuye_exp") > (me->query("longxianyuye")*me->query("longxianyuye")*100))&&(me->query("longxianyuye")< MAX_PFMLEVEL))
		{
		me->add("longxianyuye",1);
		me->set("longxianyuye_exp",0);

	      tell_object(me, HIW"��ġ�������Ұ���ȼ������ˡ�\n"NOR);
		}

	return 1;
}

int help(object me)
{
        write(YEL"\n�����ȷ�֮������Ұ��"NOR"\n");
	write(@HELP

      ����ʹ�ú󣬵��ι����з���

      ����ʶ�ּ��ܵȼ�ÿ����һ�������Ӵ�������һ�㡣
      �����ȷ����ܵȼ�ÿ�������������Ӵ����˺�һ�㡣
      ��˷𷨼��ܵȼ�ÿ�����弶�����Ӵ����˺�һ�㡣
      ������Ұ�ȼ�ÿ����һ�������Ӵ�������һ�ٵ㡣

HELP
	);
	return 1;
}
