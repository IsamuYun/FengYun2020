#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,lv,hit;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	lv = me->query("tianwaifeixian");
	if (!lv)  me->set("tianwaifeixian",1);
	lv = me->query("tianwaifeixian");
            if( (int)me->query("force") < 20*lv )     return  notify_fail("�������������\n");
	hit = me->query_skill("literate",1);
	weapon = me->query_temp("weapon");
	extra = me->query_skill("feixianforce",1) ;
	me->add_temp("apply/attack", hit*lv);	
	me->add_temp("apply/damage", extra/10*lv);
	msg = HIR  "$Nʹ�����ɽ����еľ����������ɣݣ����е�"+ weapon->name() +"����һ�����磬�����Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "����һ������ʧ��������\n" NOR;
	message_vision(msg, me, target);
	me->add_temp("apply/attack", -hit*lv);
	me->add_temp("apply/damage", -extra/10*lv);
            me->add("force", -20*lv);
	me->start_busy(2);
	if(me->query("tianwaifeixian") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("tianwaifeixian_exp",1);
	      tell_object(me, "��ġ�������ɡ������һ�㼼�������ȡ�\n"NOR);
		}
	  if((me->query("tianwaifeixian_exp") > (me->query("tianwaifeixian")*me->query("tianwaifeixian")*100))&&(me->query("tianwaifeixian")< MAX_PFMLEVEL))
		{
		me->add("tianwaifeixian",1);
		me->set("tianwaifeixian_exp",0);

	      tell_object(me, HIW"��ġ�������ɡ��ȼ������ˡ�\n"NOR);
		}

	return 1;
}

int help(object me)
{
        write(YEL"\n���ɽ���֮������ɣ�"NOR"\n");
	write(@HELP

       ���ɽ������ǰ��Ƴǳ�������Ҷ�³ǵĶ����书�����Ľ���������ʽ��
       ���ޱȣ�����ÿʽ����͸����ѧ�����С����׽�����Ӻ�ݸ��ţ�ʩչ��
       ����������Ů�·����ظ����裬˿����������ƴ���ĸо�����������ȫ
       �ޣ�ÿ�ж��̲��Ų�ͬ�ı仯���ɹ����أ����ʺ��ϲ���������ѧϰ��
       ����ͻ�������������ǣ������磬�����ɷ�����

     ���ɾ��ȼ�ÿ����ʮ�����������Ӵ��еĹ�����һ�㡣
      ����ʶ�ֵĵȼ�ÿ����һ�������Ӵ��е�����һ�㡣
      ������ɵĵȼ�ÿ����һ�������е����к��˺����ӻ���ֵ��һ����

HELP
	);
	return 1;
}