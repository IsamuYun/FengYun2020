// tie@fengyun
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［破残式］只能对战斗中的对手使用。\n");
	extra = me->query_skill("dugu-sword",1) ;
        if(extra < 201 ) return notify_fail("你的［独孤九剑］不够熟练！\n");
             if(me->query("family/master_id") != "master kumei")
                return notify_fail("你不是枯梅大师的弟子不能使用［破残式］！\n");
             if((int)me->query_temp("pocan-id")>2)
                return notify_fail("你的精神换散，暂时不能使用［破残式］！\n");
             if(me->query("family/family_name") != "华山派")
                return notify_fail("你不是华山弟子不能使用［破残式］！\n");
       message_vision(HIW"$N神功妙悟，独孤九剑「破残式」以惊天之势向$n攻出。 \n"NOR,me,target);      
       msg = HIW "$n大惊失色，心惊胆寒，但已经太迟了！\n" NOR;
            	message_vision(msg, me, target);
        me->add_temp("pocan-id",1);
        me->start_busy(8);
target->skill_death_penalty();

	return 1;
}
