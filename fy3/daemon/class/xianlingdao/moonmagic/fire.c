// firebolt.c
#include <ansi.h>
inherit SSERVER;
int conjure(object me, object target)
{
string *title=({HIR"火球术"NOR,HIR"大火球"NOR,HIR"炼狱真火"NOR,HIR"火 神"});
string * mssg=({HIR"空气中「呼」地烧起来一个火球，向$n飞速射过去。\n"NOR,
   HIR"空气中「呼」地烧起来一个大火球，带着烈炎与浓烟向$n扑去。\n"NOR,
   HIR"空气一下子变的异常酷热，「呼」地都自燃起来，浓浓烈火将$n包围。$n只觉得自己宛如置身炼狱之中。烈火中爆出无数火球，向$n噼里啪啦打去。\n"NOR,
   HIR"空中出现了一个赤红头发的大精灵----火神。\n火神双手在腰间抱成球状，顿时形成一个火球，越来越大，越来越大。。。。。。\n火神双手一推，大火球铺天盖地地向$n砸将过去。\n"NOR});
        string msg;
        int damage, ap, dp;
        int extradam;
        if( !target ) target = offensive_target(me);
      if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me
        ||      !target->is_fighting(me))
                return notify_fail("你要对谁施展这个魔法？\n");
        ap =(int)me->query_skill("magic")/50;
if (ap>3) ap=3;
        if((int)me->query("atman") < 20*(ap+1) )
        return notify_fail("你的灵力不够！\n");
        if((int)me->query("sen") < 100 )
        return notify_fail("你的精神没有办法有效集中！\n");
        me->add("atman", -20*(ap+1));
        me->receive_damage("sen", 20);
        msg = HIW "$N将精力集中于双手，一团白光在指尖一闪。。。。。。\n$N右手轻挥，向$n一指，使出"+title[ap]+"。\n"NOR;msg+=mssg[ap];
        ap = me->query_skill("magic");
        ap = ap + (int)me->query("sen")/100 ;
        dp = target->query_skill("magic");
        dp = ap + (int)target->query("sen")/100 ;
        damage=ap*2-dp;
        
        if( damage > 0 ) {
                        msg +="结果「呼」地一声，准确地命中$n，烧得$n焦头烂额。\n";
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/3, me);
                        me->improve_skill("magic", 1, 1);
                } else
                        msg += "结果「呼」地一声，擦过$n身边。\n";
        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else                            target->kill_ob(me);
                }
                me->kill_ob(target);
        }
        me->start_busy(2);
        return 1;
}
