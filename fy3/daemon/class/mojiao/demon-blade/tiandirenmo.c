// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg,forceskill;
	int extra,lv,hit,extra2;
	object weapon;
	lv = me->query("tiandirenmo");
	if (!lv)
		me->set("tiandirenmo",1);
	lv = me->query("tiandirenmo");
	hit = me->query_skill("literate",1);
	extra = me->query_skill("demon-blade",1);
	if ( extra < 150) return notify_fail("��ģ������ħ������ʽ�ݻ��������죡\n");
	dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "demon-steps")
			return notify_fail("�������ħ����Ҫ������ħ�����˲�����ͣ�\n");
	forceskill = (string) me->query_skill_mapped("force");
	if ( forceskill != "demon-force")
			return notify_fail("�������ħ����Ҫ�����ħ�ķ�����ͣ�\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if( (int)me->query("force") < 100*lv )    
		return  notify_fail("�������������\n");
	weapon = me->query_temp("weapon");
	extra2 = hit*lv/3;
	extra = (extra + lv* 100)/3;
	msg = HIY  "$N������ͨ���������ħ������ʽһ���ǳɣ�\n��ħ���ѣ�" NOR;
	me->add_temp("apply/attack",extra2*3);
	me->add_temp("apply/damage",extra*3);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "ħ�����ɣ�" NOR;
		me->add_temp("apply/attack",-extra2);
		me->add_temp("apply/damage",-extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "ħ��է�֣�" NOR;
		me->add_temp("apply/attack",-extra2);
		me->add_temp("apply/damage",-extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "��ħ����" NOR;
		me->add_temp("apply/attack",-extra2);
		me->add_temp("apply/damage",-extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "������ħ��" NOR;
		me->add_temp("apply/attack",-extra2);
		me->add_temp("apply/damage",-extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "��ħ���죡" NOR;
		me->add_temp("apply/attack",-extra2);
		me->add_temp("apply/damage",-extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "��ħ���֣�" NOR;
		me->add_temp("apply/attack",-extra2);
		me->add_temp("apply/damage",-extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "��ħ���ڣ�" NOR;
		me->add_temp("apply/attack",-extra2);
		me->add_temp("apply/damage",-extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		me->add_temp("apply/attack",extra2*4);
		me->add_temp("apply/damage",extra*4);
		me->add("force",-100*lv);
	me->start_busy(5);
	if(me->query("tiandirenmo") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("tiandirenmo_exp",1);
	      tell_object(me, "��ġ������ħ�������һ�㼼�������ȡ�\n"NOR);
		}
	  if((me->query("tiandirenmo_exp") > (me->query("tiandirenmo")*me->query("tiandirenmo")*100))&&(me->query("tiandirenmo")< MAX_PFMLEVEL))
		{
		me->add("tiandirenmo",1);
		me->set("tiandirenmo_exp",0);

	      tell_object(me, HIW"��ġ������ħ���ȼ������ˡ�\n"NOR);
		}
	return 1;
}
int help(object me)
{
        write(YEL"\n�����ħ�����˵�֮�����ħ��"NOR"\n");
	write(@HELP

      ħ�̶������书��ѧ��һ�а�ʽ��һ���ǳɣ�������ʽ���ͣ�������΢������
	
	  �����ħ�����˵��ȼ�ÿ��������������������һ�㡣
      ����ʶ�ֵȼ�ÿ����������������������һ�㡣
      �����ħ�ȼ�ÿ����һ�������Ӵ��е��������к��˺���
     

HELP
	);
	return 1;
}

