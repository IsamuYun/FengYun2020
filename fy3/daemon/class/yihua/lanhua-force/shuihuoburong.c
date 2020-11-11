// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	int lvl;
	string msg,msg1,msg2,msg3;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［水火不容］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	lvl = (int)me->query_skill("binghuostrike",1) / 20;
	if(lvl<1) {		return notify_fail("你的寒冰烈火掌还不到火候!。\n");
		}	
	extra = me->query_skill("binghuostrike",1) / 5;
	extra=extra*lvl*lvl;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg1 = HIY  "$N双手运气,全身运功,合击天地之精华,左手呈白,右手呈红,暴喝一声:使出寒冰烈火掌的绝学\n\n" NOR;	
	msg2 = BLINK HIR  "						    !!!水*火*不*容!!!\n\n" NOR;
	msg3 = BLINK MAG  "					      !!!!!!第    "+chinese_number(lvl)+"    重!!!!!!\n" NOR;
	msg=msg1+msg2+msg3;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra);
	me->start_busy(1);
	return 1;
}
