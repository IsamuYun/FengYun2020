// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i,hit,damage,lv;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	lv = me->query("tianwaifeixian");
	if (!lv)  me->set("tianwaifeixian",1);
	lv = me->query("tianwaifeixian");
	weapon = me->query_temp("weapon");
            if( (int)me->query("force") < 50*lv )     return  notify_fail("�������������\n");
	if (!weapon) return notify_fail("�������ֻ�ܺͷ��ɽ�����ͣ�\n");
	if( (string)weapon->query("skill_type") != "sword" )
	return notify_fail("�������ֻ�ܺͷ��ɽ�����ͣ�\n");
	if ( (string) me->query_skill_mapped("sword") != "feixian-sword")
	return notify_fail("�������ֻ�ܺͷ��ɽ�����ͣ�\n");
	hit = me->query_skill("literate",1) ;
	damage = me->query_skill("feixian-steps",1) /10;
	damage += me->query_skill("feixian-sword",1) /10;
	damage += me->query_skill("feixianforce",1) /10;
	me->add_temp("apply/attack", hit);	
	me->add_temp("apply/damage", damage);
	msg = HIR  "$N��̤�۷��ɲ����ݣ�ͬʱʹ���۷��ɽ����Уݵľ��裭��������ɣ����е�"+ weapon->name() +"����һ�����磬�����Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "����һ������ʧ��������\n" NOR;
            message_vision(msg, me, target);
	for(i=0;i<lv;i++)
	{
	msg = HIY "$N����ͻת�������طɣ�\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -hit);
	me->add_temp("apply/damage", -damage);
            me->add("force", -50*lv);
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
        write(YEL"\n���ɲ���֮������ɣ�"NOR"\n");
	write(@HELP

       ���ɲ������ǰ��Ƴǳ�������Ҷ�³ǵĶ����书����Ҫ��Ϊ����Ϸ���
       �����������ģ��˲���Ӻ�ݸ��ţ�ʩչ������������Ů�·����ظ����裬
       ˿����������ƴ���ĸо����ͷ��ɽ�����ϲ�������ȫ�ޣ�����������
       ǿ������

      ���ɲ��������ɽ��������ɾ��ȼ�ÿ����ʮ�����������Ӵ��еĹ�����һ�㡣
      ����ʶ�ֵĵȼ�ÿ����һ�������Ӵ��е�����һ�㡣
      ������ɵĵȼ�ÿ����һ��������һ�������طɡ�

HELP
	);
	return 1;
}
