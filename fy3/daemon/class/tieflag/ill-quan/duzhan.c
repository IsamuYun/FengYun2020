// tiandi@happyfy3
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,lv,hit;
	object weapon;
	lv = me->query("duzhan");
	if (!lv)  me->set("duzhan",1);
	lv = me->query("duzhan");
	hit = me->query_skill("literate",1);
	extra = me->query_skill("ill-quan",1);
	if ( extra < 20) return notify_fail("��Ĳ�άĦȭ���������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۶�ս��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	me ->add_temp("apply/attack",hit*lv);
	me ->add_temp("apply/damage",extra);
	msg = MAG  "$N��˫ȭ���۳���ɫ�����ţ�����ȥ����ж���������ֻ��$N�ٺ�һ������$n��ȥ��" NOR;
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me ->add_temp("apply/attack",-hit*lv);
	me ->add_temp("apply/damage",-extra);
	me->start_busy(2);
	if (random(hit*lv)> target->query_skill("literate",1)) {
		target->apply_condition("commondu",lv*3);
		target->set("statusnow","�ж�");
		message_vision("$Nմ������ɫ�Ķ���\n",target);
			}
	if(me->query("duzhan") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("duzhan_exp",1);
	      tell_object(me, "��ġ���ս�������һ�㼼�������ȡ�\n"NOR);
		}
	  if((me->query("duzhan_exp") > (me->query("duzhan")*me->query("duzhan")*100))&&(me->query("duzhan")< MAX_PFMLEVEL))
		{
		me->add("duzhan",1);
		me->set("duzhan_exp",0);

	      tell_object(me, HIW"��ġ���ս���ȼ������ˡ�\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n��άĦȭ֮��ս��"NOR"\n");
	write(@HELP
     �����ڹ�����ͬʱ��ʹ��ĵ����ж���
      
     ����ʶ�ֵĵȼ�ÿ����һ�������Ӵ��е�����һ�㡣
     ��άĦȭ�ĵȼ�ÿ����һ�������Ӵ��е��˺�һ�㡣
     ��սÿ����һ�������ӵ����ж����Լ��ж�ʱ�䡣

HELP
	);
	return 1;
}

