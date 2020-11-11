// tuwu.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
    int skill;
    string msg;
    object weapon;

    if( !target ) target = offensive_target(me);
    if (me->query_temp("jinshe/tuwu"))
        return notify_fail("你才用的毒龙吐雾，没法接着就出招。\n");

    if( !target
      || !target->is_character()
      || !me->is_fighting(target) )
        return notify_fail("毒龙吐雾只能在战斗中使用。\n");

    if ( !objectp(weapon = me->query_temp("weapon"))
      || (string)weapon->query("skill_type") != "throwing" )
           return notify_fail("你没用暗器，不能使用绝招！\n");

    if( (int)me->query_skill("dulong-zhui", 1) < 100 )
        return notify_fail("你的毒龙锥不够娴熟，不会使用毒龙吐雾。\n");

    if( (int)me->query("force") < 300 )
        return notify_fail("你内力不够了。\n");

    skill = me->query_skill("throwing");

    me->add("force", -100);
    target->receive_damage("kee", (int)skill, me);

    message_vision(
        HIY "只听一阵狂风扫叶般的声响中，$N手中的"YEL"毒锥"
        HIY"闪出夺目的光芒，闪耀得\n"
        "$n眼冒金花，“毒龙吐雾”！"
        "除了眼前一重重的雾气外，$n啥也看不见了！\n" NOR,
            me, target);
    me->set_temp("jinshe/tuwu", 1);
    target->set_temp("block_msg/all",1);

    if ( random(2) )
        target->set_temp("no_move",1);
    else
        me->add_temp("spi_protect", 1);

    target->apply_condition("unknown", random(skill/12) + 1 +
            target->query_condition("unknown"));
    call_out("tuwu_end", (int) skill/20, me, target);

    return 1;
}

void tuwu_end(object me, object target)
{
    if( objectp(target) )
    {
        target->enable_player();
        message_vision("$N抹了抹满脸的"HIR"鲜血"NOR"，终于睁开了眼。\n", target);
        target->set_temp("block_msg/all", 0);
        target->set_temp("no_move",0);
    }
    // write(HIR"你终于抹掉了满脸的鲜血，看到了周围的情景。\n"NOR);
    me->add_temp("spi_protect", -1);
    me->delete_temp("jinshe/tuwu");

    return;
}
