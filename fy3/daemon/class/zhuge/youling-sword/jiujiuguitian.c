// 九九归天 writted by tiandi
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
		return notify_fail("［九九归天］只能对战斗中的对手使用。\n");
	if(!pointerp(obs=me->query_team()) || !me->is_team_leader())
		return notify_fail("只有队伍领袖才可以发动此式！\n");
		
	for(i=0;i<sizeof(obs);i++)
	{
	if(!obs[i]) return notify_fail("你需要从新组合队伍。\n");
	if(environment(obs[i]) != environment(me)) return notify_fail("人还没到齐吧？\n");
	if(!obs[i]->query_skill("youling-sword")) return notify_fail("你队伍中有人不会幽灵剑法。\n");
	if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("你的队伍中有人没有兵器！\n");
	if(ob->query("skill_type") != "sword") return notify_fail("你的队伍中有人没有用剑！\n");
	if(!obs[i]->query_skill("youling-force")) return notify_fail("你队伍中有人不会幽灵心法。\n");
	if(obs[i]->query_skill_mapped("sword") != "youling-sword") return notify_fail("你的队伍中有人没有用幽灵剑法！\n");
	}	
	message_vision(HIC+"\n$N走寅位，剑捏天子决却走中锋，先踏子午马、再转灯笼步，突然上路出剑，以九道剑花直夺$n！\n",me,target);
	for(i=0;i<sizeof(obs);i++)
        {
	ob=obs[i]->query_temp("weapon");
	msg = HIW+obs[i]->name()+YEL"出剑如龙，挥剑如风，剑意如冢，收剑如松！\n" NOR;
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
