#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int lvl,lv,hit,dor,damage;
        object weapon;

	lv = me->query("xixuejian");
	if (!lv)  me->set("xixuejian",1);
	lv = me->query("xixuejian");
	weapon = me->query_temp("weapon");
	dor = me->query_skill("dormancy",1);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����Ѫ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

            lvl = (int) me->query_skill("fy-sword",1);
	hit = me->query_skill("literate",1);
	if (me->query("force")< lv*200)
		return notify_fail("�����������!\n");
	msg = MAG  "\n$N�����е�"+weapon->name()+"ɢ�����������ֺ�ɫ��â��$n����̬ӳ������"+weapon->name()+"�ϣ�" NOR;
	msg += MAG  "\n$N����¶��һ˿�������ɫ��аа�ض���"+weapon->name()+"�ȵ������գ�" NOR;
	me->add("force",-lv*200);
	if (random(lvl/10+hit/10+dor/10) > target->query("level"))
		{
		msg += RED  "\nֻ����$n��ͷ���϶�����һ�ƺ��˲�䱻����"+weapon->name()+"�У�\n" NOR;
		damage = target->query("kee")/10;
		if (damage > lv*5000)
			damage = lv*5000;
		target->receive_damage("kee", damage);
		me ->add("kee",damage/10);
		if (me->query("kee")>me->query("eff_kee"))
			me->set("kee",me->query("eff_kee"));
		}
		else
			msg += RED  "\nֻ����$n��ͷ���϶�����һ�ƺ����Ī������ط���$n�������У�\n" NOR;
      	            message_vision(msg, me, target);
		me ->start_busy(3);
		if(me->query("xixuejian") < (target->query("level")/10) && !userp(target))
		{
	 		 me->add("xixuejian_exp",1);
			 tell_object(me, "��ġ���Ѫ���������һ�㼼�������ȡ�\n"NOR);
		}
		if((me->query("xixuejian_exp") > (me->query("xixuejian")*me->query("xixuejian")*100))&&(me->query("xixuejian")< MAX_PFMLEVEL))
		{
		me->add("xixuejian",1);
		me->set("xixuejian_exp",0);
		tell_object(me, HIW"��ġ���Ѫ�����ȼ������ˡ�\n"NOR);
		}
	return 1;
}
int help(object me)
{
        write(YEL"\n������ƽ�֮��Ѫ����"NOR"\n");
	write(@HELP

      ��Ѫ�����м�Ϊ�Ե���ʹ���������ȡ�з�����Ѫ��Ϊ���á�
      ��ν����������������

      ����ʶ�֣�������ƽ���������ÿ����һ�����������Ӵ��е�����һ�㡣
      ��Ѫ���ĵȼ�ÿ����һ����������ȡ���ֵ������Ѫ������ǧ��

HELP
	);
	return 1;
}


