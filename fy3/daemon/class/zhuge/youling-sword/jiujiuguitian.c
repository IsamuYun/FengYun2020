// �žŹ��� writted by tiandi
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i;
	object ob,*obs;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۾žŹ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(!pointerp(obs=me->query_team()) || !me->is_team_leader())
		return notify_fail("ֻ�ж�������ſ��Է�����ʽ��\n");
		
	for(i=0;i<sizeof(obs);i++)
	{
	if(!obs[i]) return notify_fail("����Ҫ������϶��顣\n");
	if(environment(obs[i]) != environment(me)) return notify_fail("�˻�û����ɣ�\n");
	if(!obs[i]->query_skill("youling-sword")) return notify_fail("����������˲������齣����\n");
	if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("��Ķ���������û�б�����\n");
	if(ob->query("skill_type") != "sword") return notify_fail("��Ķ���������û���ý���\n");
	if(!obs[i]->query_skill("youling-force")) return notify_fail("����������˲��������ķ���\n");
	if(obs[i]->query_skill_mapped("sword") != "youling-sword") return notify_fail("��Ķ���������û�������齣����\n");
	}	
	message_vision(HIC+"\n$N����λ���������Ӿ�ȴ���з棬��̤��������ת��������ͻȻ��·�������Ծŵ�����ֱ��$n��\n",me,target);
	for(i=0;i<sizeof(obs);i++)
        {
	ob=obs[i]->query_temp("weapon");
	msg = HIW+obs[i]->name()+YEL"�����������ӽ���磬������ڣ���ս����ɣ�\n" NOR;
	extra = obs[i]->query_skill("sword");
	extra *= (i+1);	
        obs[i]->add_temp("apply/attack", extra);
        obs[i]->add_temp("apply/damage", extra);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
	obs[i]->kill_ob(target);	
	obs[i]->add_temp("apply/attack", -extra);
	obs[i]->add_temp("apply/damage", -extra);
	obs[i]->start_busy(2);
	}
	return 1;
}
