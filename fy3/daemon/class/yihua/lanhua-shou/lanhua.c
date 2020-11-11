// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
        int orforce;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
        extra = me->query_skill("unarmed");
        if ( extra < 300) return notify_fail("你的兰花手还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
             return notify_fail("［兰花绽放］只能对战斗中的对手使用。\n");
     me->add("force_factor",extra/3);
        orforce = (int) me->query("force");
        me->add("force",extra/3*100);
        me->add_temp("apply/attack",extra/2);me->add_temp("apply/damage",extra*2);

	weapon = me->query_temp("weapon");
        msg = HIR  "$N五指分开，微微一拨，再并拢向外一拂，一式［兰花绽放］，\n" NOR;
        msg += HIR   "缓缓拂向$n全身要穴，一丈开外也能感觉到无形的罡气。\n" NOR;
	          message_vision(msg,me,target);
        msg =  HIC  "\n   ☆花疏云淡☆ \n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "\n         ☆轻云蔽月☆\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "\n                  ☆云破月来☆\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "\n                           ☆幽兰弄影☆\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "\n                                    ☆花好月圆☆\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
  
me->start_busy(2);
        me->set("force_factor",0);
        me->set("force", orforce);
        me->add_temp("apply/attack",-extra/2);me->add_temp("apply/damage",-extra*2);

	return 1;
}
