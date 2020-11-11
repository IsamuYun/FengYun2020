//lion@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
    int extra;
    object weapon;
    if(me->is_busy())
    	return notify_fail("你现在没空！！\n");

    if( !target ) target = offensive_target(me);
    if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［独霸天下］只能对战斗中的对手使用。\n");

    extra = me->query_skill("bawang-qiang",1);
    if ( extra < 100) return notify_fail("你的霸王枪法还不够纯熟！\n");
    
    extra = extra+me->query_skill("spear");

    me->add_temp("apply/attack", extra*3);
    me->add_temp("apply/damage", extra);

    msg = HIW "\n$N仰天长啸，熊熊霸气直冲霄汉，手中$w幻化出千重矛影，正是『霸王枪法』\n百战无敌之式『--独-霸-天-下--』!!" NOR+HIC "\n\n动\n$N手中$w直指长空，陡然直刺$n!" NOR;
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);
    
    msg = HIW  "寒光\n$N怒喝一声，千重矛影惊涛骇浪般直刺$n！" NOR;
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);
    
    msg = HIY  "星黯然\n$N握枪之手移至中间，枪头枪尾有若两道急电点向$n！" NOR;
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);

    msg = HIC  "独霸天下\n$N手中$w如狂风落叶，无处不在，漫天枪影中一点红光直刺$n！" NOR;
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);

    msg = HIB  "马长嘶\n$N手中$w虎虎生风，咝咝作响，仿佛万马奔腾！" NOR;
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);

    msg = HIR  "血溅\n$N手中$w枪头颤震，倏得爆开，变成满天血光！" NOR;
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);

    msg = HIC  "静\n四周一切突复宁静，$N手中$w枪影消失。" NOR;
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);

    me->add_temp("apply/attack", -extra*3);
    me->add_temp("apply/damage", -extra);
	
	me->start_busy(2);
	return 1;
}
