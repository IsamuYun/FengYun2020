// written by tiandi
    
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
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
RED "����ƪ����$N�ĵ�����ಡ�����Ȼ�᳤������ɨ����" NOR,
HIR "���Ǿ�\n$N��б��ָ�ӣ���������ˮ�����ɣ�����ָ��������һƬ��Ҷ��" NOR,
YEL "����ƪ����$N��Ȼ̧ͷ��Ŀ�����ϣ���ȣ�������ϣ�����$n��ǰ��һ�����ȥ����" NOR,
HIY "���Ǿ�\n$N����ָ���£���ǧ������������أ�" NOR,
BLU "����ƪ����$N���಻ס��һ��������������ʱ�䲼��������Ŀռ䡣��" NOR,
HIB "���Ǿ�\n$N�Ľ���ѩ������Ϊ����������Ƭѩ�⣬бб������$n��" NOR,
HIM "���������ǡ�����$N����֮������Ȼ�����һ֧��ì��\n���ڵ���α��ì���������ʯ���޷��Ƶ������һɲ�ǣ����ѱ�ì��ì�ѷ�����"NOR 
HIW "���������ǡ�������\nֻ��$N����˫�������������������������ߣ�Ѹ�����������ж���Ҫ����" NOR,
});


	int skl_me, skl_you, extra_me, extra_you,i;
	int FLAG=0;
	object you,ob,*obs,weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���������ǣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if( me->query("TASK") < 1000  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("����Ŀǰ��״������û���ʸ�����һ�С�\n");
	if((int)me->query_skill("fallingstar-sword",1) < 50)
                return notify_fail("��Ľ���ʵ��̫���ˣ�\n");
	weapon = me->query_temp("weapon");
	
	if(pointerp(obs=me->query_team()) )
	{
	FLAG=1;
	for(i=0;i<sizeof(obs);i++)
	{
	if(obs[i] == me) continue;
	if(!obs[i]) {FLAG=0; continue;}
	if(environment(obs[i]) != environment(me)) {FLAG=0; continue;}
	if(!obs[i]->query_skill("tianya-blade")) {FLAG=0; continue;}
	if(!objectp(ob=obs[i]->query_temp("weapon"))) {FLAG=0; continue;}
	if(ob->query("skill_type") != "blade"){FLAG=0; continue;}
	if(obs[i]->query_skill_mapped("blade") != "tianya-blade") {FLAG=0; continue;}
	}	
	if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("fallingstar-sword",1);
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/50;
	
	if(FLAG)
	{
		if(obs[0]==me) you=obs[1]; else you=obs[0];
	skl_you=(int)you->query_skill("fallingstar-sword",1);
	extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str()/50;
        me->add_temp("apply/attack",(skl_you+skl_me));
        me->add_temp("apply/damage",(extra_you+extra_me)*4);
        you->add_temp("apply/attack",(skl_you+skl_me));
        you->add_temp("apply/damage",(extra_you+extra_me)*4);
        you->kill_ob(target);
	msg =HIY"\n$n�ۼ�$N�����⣬��Ҫ���֣�$N��Ȼ��ס�������Ľ������ͷ����˹�����\n��һ�����ް����Ϣ����ʤ������������$n������ʯ���ɲ�Ǽ䣬����ĽŲ��������ڣ���ԥ�䷴���˰벽��\n������ʱ��$N���֣�һ��������ն���ϵ紩�ƣ�������ƥ��\n"NOR;
	 message_vision(msg,me,target);
	for(i=0;i<sizeof(tianyaliuxing);i++)
	if(i%2) COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,tianyaliuxing[i]);
	else    COMBAT_D->do_attack(you,target,you->query_temp("weapon"),TYPE_REGULAR,tianyaliuxing[i]);
        me->add_temp("apply/attack",-(skl_you+skl_me));
        me->add_temp("apply/damage",-(extra_you+extra_me)*4);
        you->add_temp("apply/attack",-(skl_you+skl_me));
        you->add_temp("apply/damage",-(extra_you+extra_me)*4);
	}
	else
	{
        msg =HIY"$n�ۼ�$N�����⣬��Ҫ���֣�$N��Ȼ��ס�������Ľ������ͷ����˹�����\n��һ�����ް����Ϣ����ʤ������������$n������ʯ���ɲ�Ǽ䣬����ĽŲ��������ڣ���ԥ�䷴���˰벽��\n������ʱ��$N���֣�һ��������ն���ϵ紩�ƣ�������ƥ��\n"NOR;
	 message_vision(msg,me,target);
	 me->add_temp("apply/attack",skl_me/5);
        me->add_temp("apply/damage",extra_me/5);
        for(i=0;i<sizeof(liuxing);i++)
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,liuxing[i]);
        me->add_temp("apply/attack",-skl_me/5);
        me->add_temp("apply/damage",-extra_me/5);
	}	
	me->start_busy(4);
	return 1;
}
