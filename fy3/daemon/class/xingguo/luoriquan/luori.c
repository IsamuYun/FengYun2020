// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,lv,tmp1,tmp2,hit;
	object weapon;
	lv = me->query("luori");
	if (!me->query("luori"))
		me->set("luori",1);
	lv = me->query("luori");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("luoriquan",1);
	if ( extra < 200) return notify_fail("���������ȭ���������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����գ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (me->query("force")< lv*50)
		return notify_fail("�������������\n");
	hit = me->query_skill("literate",1);
	tmp1 = me->query_temp("apply/attack")/2;
	tmp2 = me->query_temp("apply/damage")/2;
	me->add_temp("apply/attack",-tmp1+hit);
	me->add_temp("apply/damage",-tmp2+extra);

	weapon = me->query_temp("weapon");
	msg = HIR  "$N���췢��һ����Ц��ʹ��������ȭ�еģ����գݣ�\n" NOR;
	msg += HIR   "���Ʋ����ޱȵ�Ϧ������ʱ�������Ϊ֮��ɫ��\n" NOR;
	          message_vision(msg,me,target);
        msg =  HIC  "\n   �� \n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	if (lv > 2)
	{
		msg = HIY  "\n         ��\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
    if (lv > 4)
    {
		msg = HIW  "\n                  ��\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

    }  
	if (lv > 6)
	{
		msg = HIR  "\n                           ��\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	if (lv > 8)
	{
        msg = HIB "\n                                    Բ\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
		{
	 	 me->add("luori_exp",1);
	      tell_object(me, "��ġ����ա������һ�㼼�������ȡ�\n"NOR);
		}
	  if((me->query("luori_exp") > (me->query("luori")*me->query("luori")*100))&&(me->query("luori")< 10))
		{
		me->add("luori",1);
		me->set("luori_exp",0);

	      tell_object(me, HIW"��ġ����ա��ȼ������ˡ�\n"NOR);
		}				
	me->start_busy(4);
        me->add_temp("apply/attack",-hit+tmp1);
		me->add_temp("apply/damage",-extra+tmp2);

	return 1;
}
int help(object me)
{
        write(YEL"\n������ȭ֮���գ�"NOR"\n");
	write(@HELP

      ��Ϊ������Ķ�����ѧ��������˧����ʦ̸��������ҹ�����˼���
	  ��������ǿ����˺�����Ҳ��������һʱ��
	
	  ������ȭ�ȼ�ÿ����һ����������������һ�㡣
      ����ʶ�ֵȼ�ÿ����һ����������������һ�㡣
      ���յȼ�ÿ�������������Ӵ��е���ʽ��
     

HELP
	);
	return 1;
}
