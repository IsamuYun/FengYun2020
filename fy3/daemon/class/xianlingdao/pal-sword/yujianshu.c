// yiru@hero

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int do_one_attack(object me, object target, int lvl, int extra, int busy);
int do_another_attack(object me, object target, int lvl, int extra, int busy);

int perform(object me, object target)
{
    int extra, lvl, busy;
    object weapon;

    if ( !target )
        target = offensive_target(me);
    if ( !target
      || !target->is_character()
      || !me->is_fighting(target) )
        return notify_fail("『御剑术』只能对战斗中的对手使用。\n");
    weapon = me->query_temp("weapon");
    lvl = me->query_skill("pal-sword",1);
    extra = lvl / 18 + ((lvl % 18) > 0);
    message_vision(HIC "\n$N"HIC"左手捏个剑决，潜运真气，手中$n" HIC
      "脱手而出！\n" NOR, me, weapon);
    if ( userp(me) && ( random(lvl-18) + me->query_agi()<36 ) )
    {
        message_vision(HIW  "$N以气御剑，指挥"+ weapon->name() + HIW
          "向$n" HIW "攻去。\n"
          HIY "岂料胡点了半天，"+ weapon->name() + HIY
          "反而“啪”的一声掉到地下！" NOR, me, target);

        write(HIY "\n可能是你蜀山剑法还不够纯熟。\n" NOR);
        if( weapon->query("owner") )
            message_vision(HIW "但是$N随手一抄，稳稳的把$n"HIW
              "握在手中。\n"NOR, me, weapon);
        else
            weapon->move(environment(me));
        return 1;
    }

    busy = lvl/40+1;

    me->do_attack_perform(target, extra, busy, lvl/9, lvl/3,
        HIW  "$N" HIW "以气御剑，"
        + weapon->name() + HIW "就像长了眼睛般直刺$n"HIW"！" NOR,
        "\n" HIG + weapon->name() + HIG "飞回$N" HIG "手中，"
        "$N" HIG "伸手一抄，稳稳接住。\n" NOR);

    return 1;
}
