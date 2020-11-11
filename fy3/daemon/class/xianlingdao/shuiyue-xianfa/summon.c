// yiru@hero

inherit SSERVER;
#include <ansi.h>
#include <condition.h>
#include <combat.h>

int summon_god(object me, object target, int level)
{
    object soldier;
        message_vision(HIW"\n$N将"HIM"圣灵珠"HIW"高举过头顶，使出武神召唤术。。。\n"NOR, me);
        message_vision(HIY"只见一个身批铠甲，手握大刀的力士突然来到$n的身后。\n"NOR, me, target);

        seteuid(geteuid(this_player()));

        soldier = new("/obj/npc/wu_god");

        soldier->move(environment(me));
        soldier->invocation(me, level);
        soldier->set("possessed", me);
        me->remove_all_killer();
        me->set_temp("guards/wu",1);
        me->start_busy(1);
        target->start_busy(3);

    return 1;
}

int conjure(object me, object target)
{
        int lvl, lvl1;
    object zhu;

    lvl = me->query_skill("shuiyue-xianfa",1);
    lvl1 = (lvl + me->query_skill("five-summon",1))/2;

    if( lvl1 > lvl ) lvl = lvl1;

    if(lvl < 250)
                return notify_fail("你还没学会武神召唤术。。。\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［武神召唤术］只能对战斗中的对手使用。\n");

  if(userp(me)){
        if( (int)me->query("atman") < lvl)
                return notify_fail("你的灵力不够了！\n");
        if( (int)me->query("force") < lvl)
                return notify_fail("你的内力不够了！\n");
        if( (int)me->query("mana") < lvl)
                return notify_fail("你的法力不够了！\n");
        me->add("atman", -lvl);
        me->add("force", -lvl);
        me->add("mana", -lvl);
  }

        me->start_busy(2);

    notify_fail("你运起武神召唤术，但是什么也没有发生。\n");

    if(random(lvl)<90) return 0;
    if(me->query_temp("guards/wu")) return 0;
    if(!objectp(zhu=present("shengling zhu", me)) ) return 0;
    if(!zhu->query("equipped") ) return 0;

    if( userp(me) )
    {
        return summon_god(me, target, 10*lvl);
    }

        return 0;
}
