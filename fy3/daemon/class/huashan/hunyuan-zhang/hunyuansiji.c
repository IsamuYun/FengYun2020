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
	if ( extra < 100) return notify_fail("你的[混元掌法]还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［混元四击］只能对战斗中的对手使用。\n");
	me->add("force_factor",extra/5);
	orforce = (int) me->query("force");
	me->add("force",extra/5*100);
	me->add_temp("apply/attack",extra/10);
	weapon = me->query_temp("weapon");
	msg = HIY  "$N使出混元掌法中的［混元四击］，卷起一股狂风向$n攻出！\n" NOR;
	message_vision(msg,me,target);
	msg = HIY  "九天闪闪！" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "入魔丛生！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "万面杨柳！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIY  "缠甲卸剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      	me->start_busy(5);
	me->set("force_factor",0);
	me->set("force", orforce);
        me->add_temp("apply/attack",-extra/10);
	return 1;
}
