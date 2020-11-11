// yiru@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, extra2;
        int i, orgforce, orgfact;
        object *obs;
        object weapon;

    /*
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("天剑只能对战斗中的对手使用。\n");
    */
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("天剑只能和御剑术配和！\n");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("天剑只能和御剑术配和！\n");
        if ( (string) me->query_skill_mapped("sword") != "imperialsword")
        return notify_fail("天剑只能和御剑术配和！\n");
        if(me->query_spi()<15)
          return notify_fail("你的灵力太低，无法发出天剑！\n");
        if(me->query_skill("imperialsword",1)<30)
          return notify_fail("你的御剑术不够熟练，无法发出天剑！\n");

        extra = me->query_skill("imperialsword",1) / 5;
        extra2 = me->query_spi()-15;
        orgforce=me->query("force");
        orgfact=me->query("force_factor");

        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra2*2*2);
        me->add("force_factor",me->query("atman_factor")+extra2);

        msg = HIY "\n$N心剑合一，与$n"HIY"一起化作一柄巨大的"HIW"天剑"HIY"直射而出！" NOR;
    obs = me->query_enemy();
    if(!sizeof(obs)) msg += "\n";
    message_vision(msg,me,weapon);
    for(i=0;i<sizeof(obs);i++)
        {       
        if(!obs[i]) continue;
        me->add("force",orgfact+extra2+me->query("atman_factor"));
COMBAT_D->do_attack(me,obs[i], weapon, TYPE_REGULAR,HIC"天剑飞掠,挡者披靡"NOR);
        }
        me->start_busy(sizeof(obs)/2+2);
        
        me->set("force_factor",orgfact);
        me->add_temp("apply/damage", -extra2*2*2);
        me->add_temp("apply/attack", -extra);
        return 1;
}
