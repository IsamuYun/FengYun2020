// 欢乐英雄
// by lion@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string msg,*limbs;
    int i,size,damage;
    int hisexp,meexp;
    object my_w,target_w;

    if( !target ) target = offensive_target(me);
    if( !target
      ||      !target->is_character()
      ||      !me->is_fighting(target) )
        return notify_fail("「轰天一击」只能对战斗中的对手使用。\n");
    
    if( me->is_busy())
        return notify_fail("你现在没空！\n");
    
    if( (int)me->query_skill("kaishan-chui",1) < 100)
        return notify_fail("你的「开山锤」等级不够。\n");
    
    if( (int)me->query("force") < 400 )
        return notify_fail("你的内力不够。\n");
    
    me->add("force", -400);
    me->start_busy(2);
    
    my_w = me->query_temp("weapon");
    message_vision(HIC"$N突然暴吼一声：“轰天一击！！”，手中"+my_w->name()+"划了一道弧线径直向$n砸去！\n"NOR,me,target);

	hisexp = (int)target->query("combat_exp");
	meexp = (int)me->query("combat_exp");

    // 失败！
    if (random(hisexp+meexp) > 3*meexp)
    {
        message_vision(HIR"结果$N身形一晃躲了过去，$n一个收手不稳，"
          "手中的"+my_w->name()+"飞速砸向自己大腿。\n"NOR,target,me);
        me->receive_damage("kee",50,target);        
        COMBAT_D->do_attack(me,me, me->query_temp("weapon"), TYPE_REGULAR,"");
        return 1;
    }
    
    target_w = target->query_temp("weapon");
    if(!target_w)
        target_w = target->query_temp("secondary_weapon");
    
    if(!target_w || 3*random(hisexp) > random(meexp))
    { 
    	// 对方空手
        damage = me->query_skill("hammer");
        me->add_temp("apply/attack", damage);
        me->add_temp("apply/damage", damage);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,"");
        me->add_temp("apply/attack", -damage);
        me->add_temp("apply/damage", -damage);
        return 1;
    }
    
    // 砸兵器
    msg = HIC"只见$n手中的"+target_w->query("name")+"竟然被砸断作数段，"
    		"并且受到$N的劲气的激荡而向$n迅速射去！\n"NOR;
	message_vision(msg,me,target);

    if(target_w->unequip())
        target_w->move(environment(target));
    target_w->set("name", target_w->query("name") + "的碎片");
    target_w->set("value", 0);
    target_w->set("weapon_prop", 0);
//    target->reset_action();
    limbs=target->query("limbs");
    size = sizeof(limbs);
    damage = (int)me->query_skill("hammer") + me->query_str() + me->query_temp("apply/damage");
    
    for(i=0;i<1+random(size);i++)
    {
	    msg =HIW"\n“嗤”，碎片射入$N的"+limbs[random(size)]+"！\n"NOR;
	    message_vision(msg,target);
	    target->receive_damage("kee",damage,me);
	    target->receive_wound("kee", damage/3,me);
	    COMBAT_D->report_status(target);
    }
    return 1;
}
