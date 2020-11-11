// yiru@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{       object *ob2;
        string msg;
        int extra, str;
        int i,j;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("万剑决只能对战斗中的对手使用。\n");

        if(me->query_skill("imperialsword",1) < 160)
        {
                return notify_fail("你的御剑术修为不够，无法使用万剑决。\n");
        }

    weapon = me->query_temp("weapon");
    msg=HIG"\n$N右手捏个剑决，潜运真气，手中"+weapon->name()+HIG"脱手而出，直向半空刺去。\n\n"; 
    message_vision(msg, me, target);
    if( random(me->query_skill("sword"))+random(me->query("kar")) < 100)
    { 
        message_vision("岂料等了半天，还是没有下文。。。\n",me,target);
        write(HIY"可能是你蜀山剑法和御剑术修为还不够高。\n\n"NOR);
        me->start_busy(1);
        return 1;
    }
    msg=HIG"\n却见空中白光闪烁，竟是无数"+ weapon->name() +HIG "如雨般射将下来！\n"NOR;
    message_vision(msg,me);
    msg=HIW "万剑射下 风云变色" NOR;
    ob2 = me->query_enemy();
    extra = me->query_skill("pal-sword",1)/5 + me->query_skill("imperialsword",1)/2;
    str = me->query("atman_factor")/2+extra;
    
    j = sizeof(ob2)*(extra/20);
    if (j>36)
    {
        j=36;
    }

    j=j+random(j);

    me->add_temp("apply/attack", extra*3);
    me->add_temp("apply/damage", extra*3);
//      me->add("str",str);
    
    for(i=0;i<j;i++)
    {       
                COMBAT_D->do_attack(me,ob2[random(sizeof(ob2))], weapon, TYPE_REGULAR,msg);
    }
    
//     me->add("str",-str);
    me->add_temp("apply/damage", -extra*3);
        me->add_temp("apply/attack", -extra*3);
    
        msg=HIG "\n$N手一挥，一股剑气卷过，万剑又合成为原来的" + weapon->name() +HIG"飞回$N手中。\n" NOR;
        message_vision(msg, me, target);
    
    if(j > 30)
    {
        j = 30; 
    }
    if(j < 10)
    {
        j = 10; 
    }
    me->start_busy(j/5);
        return 1;
}

