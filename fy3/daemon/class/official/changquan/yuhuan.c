// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce,hit,damage;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
    extra = me->query_skill("changquan",1);
    hit = me->query_skill("literate",1);
    damage = me->query_skill("strategy",1);
         if ( extra < 200) return notify_fail("������ֳ�ȭ���������ټ���\n");
	if (!me->query("yuhuan"))
		me->set("yuhuan",1);
         if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ԧ��ȭ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	orforce = (int) me->query("force");
	if (orforce < extra )
		return notify_fail("����������㡣\n");
            me->add_temp("apply/attack",hit);
            me->add_temp("apply/damage",damage);
	weapon = me->query_temp("weapon");
	me->add("force", -extra);
	msg = HIY  "$Nʹ�����ֳ�ȭ�еģ���ԧ��ȭ�ݣ�һ��������ʽ��$n������\n" NOR;

	message_vision(msg,me,target);
	msg = HIY  "��һȭ��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "ǰһȭ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	if (me->query("yuhuan")>random(10))
		{
		            me->add_temp("apply/damage",damage);
    			msg = HIY  "�����һȭ����" NOR;
  			COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		            me->add_temp("apply/damage",-damage);
		}
	me->start_busy(4);
            me->add_temp("apply/attack",- hit);
            me->add_temp("apply/damage",-damage);
	if(me->query("yuhuan") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("yuhuan_exp",1);
	      tell_object(me, "��ġ���ԧ��ȭ�������һ�㼼�������ȡ�\n"NOR);
		}

	  if(me->query("yuhuan_exp") > (me->query("yuhuan")*me->query("yuhuan")*100)&&(me->query("yuhuan")<10))
		{
		me->add("yuhuan",1);
		me->set("yuhuan_exp",0);
	      tell_object(me, HIW"��ġ���ԧ��ȭ���ȼ������ˡ�\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n���ֳ�ȭ֮��ԧ��ȭ��"NOR"\n");
	write(@HELP

      ����ʹ�ú�һ�����ι����з������м��ʷ������߶ι�����
      ���߶ι������˺��ɷ���Ч����

      ����ʶ�ּ��ܵȼ�ÿ����һ�������Ӵ�������һ�㡣
      �������ܵȼ�ÿ����һ�������Ӵ����˺�һ�㡣
      ��ԧ��ȭ�ȼ�ÿ����һ�������ӵ��߶η�������10%��

HELP
	);
	return 1;
}
