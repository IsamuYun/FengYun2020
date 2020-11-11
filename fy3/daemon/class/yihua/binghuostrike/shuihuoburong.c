// xgchen@zzfy
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
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［水火不容］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        lvl = (int)me->query_skill("binghuostrike",1) / 20;
        if(lvl<1) {             return notify_fail("你的寒冰烈火掌还不到火候!。\n");
                }      
        extra = me->query_skill("binghuostrike",1) ;
        extra=extra*lvl;
        if( (int)me->query("force") < 10*lvl )     return 
        notify_fail("你的内力不够。\n"); 
        me->add_temp("apply/attack", extra/10);    
        me->add_temp("apply/damage", extra);
        msg1 = HIY  "$N双掌运气,合击天地之精华,暴喝一声:使出寒冰烈火掌的绝学\n\n" NOR;       
msg2 = HIR"      !!!水*火*不*容!!!\n\n" NOR;
msg3 = HIM"      !!!!!!第    "+chinese_number(lvl)+"    重!!!!!!\n" NOR;
        msg=msg1+msg2+msg3;
        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
        me->add_temp("apply/attack", -extra/10);   
        me->add_temp("apply/damage", -extra);
        me->start_busy(3);
        return 1;
}
int help(object me)
{
        write(RED"\n寒冰烈火掌："NOR"\n");
        write(@HELP

        寒冰烈火掌,小鱼儿集天地间水火之灵气，自创而成的掌法，使用出来，
        会使人仿佛身处于水深火热之中，痛苦不堪，杀伤力甚是巨大！而且此武功
        分为好多阶段，每提升一重，会使攻击力提高很多，不过学习的难度也会也
        会越来越大。

        要求：  寒冰烈火掌等级 20 以上
                内力消耗 10*寒冰烈火掌等级/20

HELP
        );
        return 1;
}

