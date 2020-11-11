#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int i,hit,damage;
	string *style = ({
HIY"天时－－$N向右一晃,抡动手中$w，剑光一闪，刺向$n的$l！"NOR,
HIR"地利－－$N上前一步，手中$w化做剑影重重，将$n团团围住！"NOR,
HIB"人和－－$N向左跨出一步，手中$w悠然一画，指向$n的$l！"NOR,
HIM"天地人－－阵中各人如穿花蝴蝶，瞬间交换了位置，剑光密布，分打$n的各处要害！\n"NOR});
	object ob,*obs;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［三才归一］只能对战斗中的对手使用。\n");
	if(!pointerp(obs=me->query_team()) || !me->is_team_leader())
		return notify_fail("只有队伍领袖才可以发动此式！\n");
            if(sizeof(obs) != 3 )
		return notify_fail("队伍必须要三个人！！\n");
	for(i=0;i<sizeof(obs);i++)
	{
	if(!obs[i]) return notify_fail("你需要从新组合队伍。\n");
	if(environment(obs[i]) != environment(me)) return notify_fail("你队伍成员不全在你身边。\n");
	if(obs[i]->query_skill("three-sword")<20) return notify_fail("你队伍中有人三才剑法等级太低。\n");
	if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("你的队伍中有人没有兵器！\n");
	if(ob->query("skill_type") != "sword") return notify_fail("你的队伍中有人没有用剑法！\n");
	if(obs[i]->query_skill_mapped("sword") != "three-sword") return notify_fail("你的队伍中有人没有用三才剑法！\n");
	if(!obs[i]->query("sancai")) obs[i]->set("sancai",1);
	if(obs[i]->query("sancai") *100 > obs[i]->query("force"))  return notify_fail("你的队伍中有人内力不够！\n");
	}	
	message_vision(HIM+"\n\n$N高喝一声：天－－地－－人－－三才归一！！立时发动了三才剑阵！\n"+style[3],me,target);
	for(i=0;i<3;i++)
        {
	ob=obs[i]->query_temp("weapon");
	msg =  style[i];
	hit = obs[i]->query_skill("literate",1);
	damage = obs[i]->query("sancai");
        obs[i]->add_temp("apply/attack", hit);
        obs[i]->add_temp("apply/damage", 200*damage);
	COMBAT_D->do_attack(obs[i],target, ob, TYPE_REGULAR,msg);
	obs[i]->kill_ob(target);	
	obs[i]->add_temp("apply/attack", -hit);
	obs[i]->add_temp("apply/damage", -200*damage);
       obs[i]->add("force", -100*damage);
	obs[i]->start_busy(2);
	}
	if(me->query("sancai") < (target->query("level")/10) && !userp(target))
		{
	 	 me->add("sancai_exp",1);
	      tell_object(me, "你的【三才归一】获得了一点技能熟练度。\n"NOR);
		}
	  if((me->query("sancai_exp") > (me->query("sancai")*me->query("sancai")*100))&&(me->query("sancai")< MAX_PFMLEVEL))
		{
		me->add("sancai",1);
		me->set("sancai_exp",0);

	      tell_object(me, HIW"你的【三才归一】等级上升了。\n"NOR);
		}

	return 1;
}
int help(object me)
{
        write(YEL"\n三才剑法三才归一："NOR"\n");
	write(@HELP

       三才剑法是以太极拳为基础发展而来的加法，和太极拳一样讲究以静制动、
       后发制人，每一招都含着太极式的阴阳变化。三才归一是三才剑法的剑阵，
       此招需要三人同时配合才能发出最大的威力，但此三人都需要有高深的剑
       法。如果一人施展，则威力大减。
	
      读书识字技能等级每上升一级，增加此招命中一点。
      三才归一等级每上升一级，增加此招伤害两百点。
HELP
	);
	return 1;
}
