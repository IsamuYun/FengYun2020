// written by tiandi
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me,object target)
{
   string *liuxing = ({
HIR "���Ǿ�\n$N��б��ָ�ӣ���������ˮ�����ɣ�����ָ��������һƬ��Ҷ��" NOR,
HIY "���Ǿ�\n$N����ָ���£���ǧ������������أ�" NOR,
HIB "���Ǿ�\n$N�Ľ���ѩ������Ϊ����������Ƭѩ�⣬бб������$n��" NOR,
HIG "���Ǿ�\nֻ��$N����˫�������������������������ߣ�Ѹ�����������ж���Ҫ����" NOR
});
  string *tianya= ({
RED "����ƪ����$N�ĵ�����ಡ�����Ȼ�᳤������ɨ����" NOR,
YEL "����ƪ����$N��Ȼ̧ͷ��Ŀ�����ϣ���ȣ�������ϣ�����$n��ǰ��һ�����ȥ����" NOR,
BLU "����ƪ����$N���಻ס��һ��������������ʱ�䲼��������Ŀռ䡣��" NOR,
HIM "����ƪ����$N����֮������Ȼ�����һ֧��ì��\n���ڵ���α��ì���������ʯ���޷��Ƶ������һɲ�ǣ����ѱ�ì��ì�ѷ�����"NOR 
});
 string *tianyaliuxing= ({
HIR "���Ǿ�\n$N��б��ָ�ӣ���������ˮ�����ɣ�����ָ��������һƬ��Ҷ��"NOR,
RED "����ƪ����$N�ĵ�����ಡ�����Ȼ�᳤������ɨ����" NOR,
HIY "���Ǿ�\n$N����ָ���£���ǧ������������أ�" NOR,
YEL "����ƪ����$N��Ȼ̧ͷ��Ŀ�����ϣ���ȣ�������ϣ�����$n��ǰ��һ�����ȥ����" NOR,
HIB "���Ǿ�\n$N�Ľ���ѩ������Ϊ����������Ƭѩ�⣬бб������$n��" NOR,
BLU "����ƪ����$N���಻ס��һ��������������ʱ�䲼��������Ŀռ䡣��" NOR,
HIW "���������ǡ�������\nֻ��$N����˫�������������������������ߣ�Ѹ�����������ж���Ҫ����" NOR,
HIM "���������ǡ�����$N����֮������Ȼ�����һ֧��ì��\n���ڵ���α��ì���������ʯ���޷��Ƶ������һɲ�ǣ����ѱ�ì��ì�ѷ�����"NOR 
});
	string msg;
	int skl_me, skl_you, extra_me, extra_you,i;
	int FLAG=0;
	object you,ob,*obs,weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		  return notify_fail("���������ǣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if((int)me->query_skill("tianya-blade",1) < 50)
                return notify_fail("��ĵ���ʵ��̫���ˣ�\n");
	if( me->query("TASK") < 1500  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("����Ŀǰ��״������û���ʸ�����һ�С�\n");
	weapon = me->query_temp("weapon");
	
	if(pointerp(obs=me->query_team()) )
	{
	FLAG=1;
	for(i=0;i<sizeof(obs);i++)
		{
	if(obs[i] == me) continue;
	if(!obs[i]) {FLAG=0; continue;}
	if(environment(obs[i]) != environment(me)) {FLAG=0; continue;}
	if(!obs[i]->query_skill("fallingstar-sword")) {FLAG=0; continue;}
	if(!objectp(ob=obs[i]->query_temp("weapon"))) {FLAG=0; continue;}
	if(ob->query("skill_type") != "sword"){FLAG=0; continue;}
	if(obs[i]->query_skill_mapped("sword") != "fallingstar-sword") {FLAG=0; continue;}
		}	
	if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("tianya-blade",1);
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/50;
	
	if(FLAG)
	{
		if(obs[0]==me) you=obs[1]; else you=obs[0];
	skl_you=(int)you->query_skill("fallingstar-sword",1);
	extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str()/50;
        me->add_temp("apply/attack",(skl_you+skl_me)/2);
        me->add_temp("apply/damage",(extra_you+extra_me)*6);
        you->add_temp("apply/attack",(skl_you+skl_me)/2);
        you->add_temp("apply/damage",(extra_you+extra_me)*6);
        you->kill_ob(target);
	 msg =HIY"\n�׹�һ����$N�Ѱε���������˫�ĵ�������˼�ǵĵ�����\n���۶�񶾵ı��������۶ิ�ӵĹ�ƣ����������ֵ����������Ǳ�ѩ���������¡�\n"HIW"������������һ�������������졣\n"NOR;
	 message_vision(msg,me,target);
	for(i=0;i<sizeof(tianyaliuxing);i++)
	if(i%2) COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,tianyaliuxing[i]);
	else    COMBAT_D->do_attack(you,target,you->query_temp("weapon"),TYPE_REGULAR,tianyaliuxing[i]);
        me->add_temp("apply/attack",-(skl_you+skl_me)/2);
        me->add_temp("apply/damage",-(extra_you+extra_me)*6);
        you->add_temp("apply/attack",-(skl_you+skl_me)/2);
        you->add_temp("apply/damage",-(extra_you+extra_me)*6);
	msg = RED"\n\n������ʧ�󣬲ſ���Ѫ��Ѫ�Ǵ��������µġ�$n"RED"������\nһ�����ڴ�$n"RED"üë��������������Ǽ⣬��һ��ֻҪ������������$n"RED"��ͷ��Ҫһ��Ϊ���ˡ�\n�������ʡ���Ѫ�ӱǼ����䣬�����촽��$n"RED"ȴû�ие�һ˿ʹ�ࡣ\n"NOR;
	message_vision(msg,me,target);}
	else
	{
        msg =HIY"�׹�һ����$N�Ѱε���������˫�ĵ�������˼�ǵĵ�����\n���۶�񶾵ı��������۶ิ�ӵĹ�ƣ����������ֵ����������Ǳ�ѩ���������¡�\n"HIW"������������һ�������������졣\n"NOR;
	 message_vision(msg,me,target);
	 me->add_temp("apply/attack",skl_me);
        me->add_temp("apply/damage",extra_me);
        for(i=0;i<sizeof(tianya);i++)
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,tianya[i]);
        me->add_temp("apply/attack",-skl_me);
        me->add_temp("apply/damage",-extra_me);
	msg = RED"\n\n������ʧ�󣬲ſ���Ѫ��Ѫ�Ǵ��������µġ�$n"RED"������\nһ�����ڴ�$n"RED"üë��������������Ǽ⣬��һ��ֻҪ������������$n"RED"��ͷ��Ҫһ��Ϊ���ˡ�\n"RED"�������ʡ���Ѫ�ӱǼ����䣬�����촽��$n"RED"ȴû�ие�һ˿ʹ�ࡣ\n"NOR;
	message_vision(msg,me,target);
	}	
	me->start_busy(4);
	return 1;
}