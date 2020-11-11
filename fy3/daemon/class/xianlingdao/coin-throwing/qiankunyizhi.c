// qiankunyizhi.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
    int amount,lev;
    object coin;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target
      ||        !target->is_character()
      ||        !me->is_fighting(target) )
        return notify_fail("["HIY"乾坤一掷"NOR"]只能对战斗中的对手使用。\n");
    if((int) me->query_skill("coin-throwing",1) < 30)
        return notify_fail("你的铜钱镖还不够精纯，不能发出"HIY"乾坤一掷"NOR"。\n");
    coin=present("coin",me);
    if(!coin)
        return notify_fail("你身上没有钱,不能用乾坤一掷。\n");
    amount=10*(lev=me->query_skill("throwing"));
    if(coin->query_amount()<amount)
        return notify_fail("你身上的钱不够"+chinese_number(amount)+"文,不能发乾坤一掷。\n");
    message_vision(HIY"$N突然从怀里掏出一大把铜钱，漫天飞雨般向$n掷去，几乎把$n的所有退路\n"
      "都封死了。\n"NOR,me,target);
    message_vision("结果造成非常可怕的严重伤害。\n",target);
    coin->add_amount(-amount);
    target->receive_damage("kee",5*lev,me);
    COMBAT_D->report_status(target);

    me->start_busy(2);
    return 1;
}
