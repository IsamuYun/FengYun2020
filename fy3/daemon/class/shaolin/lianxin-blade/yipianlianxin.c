// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i;
	string *style = ({
HIR "$N����$wͻ����⣬����$n��$l��" NOR,
HIY "$N����$wͻ���ƹ⣬ֱȡ$n��$l��" NOR,
HIW "$N����$wͻ���׹⣬����$n��$l��" NOR,
HIG "$N����$wͻ���̹⣬ƽ��$n��$l��" NOR,
HIB "$A����$W��$B���е�$V��֯��ϣ�����������������$n��" NOR,
});
	object ob,*obs;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��һƬ���ģ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(!pointerp(obs=me->query_team()) )
		return notify_fail("ֻ�ж���ſ��Է�����ʽ��\n");
// this loop just checking, make sure everyone use ����Ӱ�ֵ���
	for(i=0;i<sizeof(obs);i++)
	{
	if(!obs[i]) return notify_fail("����Ҫ������϶��顣\n");
	if(environment(obs[i]) != environment(me)) return notify_fail("������Ա��ȫ������ߡ�\n");
	if(!obs[i]->query_skill("lianxin-blade")) return notify_fail("����������˲�������Ӱ�ֵ�����\n");
	if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("��Ķ���������û�б�����\n");
	if(ob->query("skill_type") != "blade") return notify_fail("��Ķ���������û���õ�����\n");
	if(obs[i]->query_skill_mapped("blade") != "lianxin-blade") return notify_fail("��Ķ���������û��������Ӱ�ֵ�����\n");
	}	
	if(sizeof(obs) !=2) return notify_fail("ֻ�������˵Ķ���ſ���ʩչ��һƬ���ģݣ�\n");
	message_vision( HIR "\n\n\n$N��$n������ͻȻ��֯��һ��ԽתԽ�죡\n" NOR,obs[0],obs[1]);
	obs[0]->kill_ob(target);
	obs[1]->kill_ob(target);
	for(i=0;i<sizeof(style)-1;i++)
        {
	ob=obs[(i%2)]->query_temp("weapon");
	msg = style[i];
	extra = obs[(i%2)]->query_skill("lianxin-blade");
        obs[(i%2)]->add_temp("apply/attack", extra);
        obs[(i%2)]->add_temp("apply/damage", extra);
	COMBAT_D->do_attack(obs[(i%2)],target, ob, TYPE_REGULAR,msg);
	obs[(i%2)]->add_temp("apply/attack", -extra);
	obs[(i%2)]->add_temp("apply/damage", -extra);
	}
	style[i] = replace_string(style[i],"$A", obs[0]->name());
        style[i] = replace_string(style[i],"$B", obs[1]->name());
        style[i] = replace_string(style[i],"$W", (obs[0]->query_temp("weapon"))->name());
        style[i] = replace_string(style[i],"$V", (obs[1]->query_temp("weapon"))->name());
	extra = obs[0]->query_skill("blade");
	extra += obs[1]->query_skill("blade");
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,style[i]);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
	me->start_busy(5);
	return 1;
}
