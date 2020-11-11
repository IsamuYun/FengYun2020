// xgchen edit
#include <ansi.h>
#include <combat.h> 
inherit SSERVER; 

int perform(object me, object target) 
{  
	string msg;
	int extra;
	int i;
	object weapon;
	extra = me->query_skill("damo-sword",1);
    
    if ( extra < 100) return notify_fail("你的达摩剑法还不够纯熟！\n");
    
    if ( me->query("force") < 500) return notify_fail("你的内力还不够纯熟！\n");      
    
    if( !target ) target = offensive_target(me);
    if( !target ||  !target->is_character() || !me->is_fighting(target) )
    	return notify_fail("[达摩三绝剑]只能对战斗中的对手使用。\n");           
    
    weapon = me->query_temp("weapon"); 
    if (!weapon) return notify_fail("[达摩三绝剑]必须有剑才可以发出绝技！\n");        
    
    if( (string)weapon->query("skill_type") != "sword")       
         return notify_fail("[达摩三绝剑]必须有剑才可以发出绝技！\n");     
    
    if ( (string) me->query_skill_mapped("sword") != "damo-sword")         
         return notify_fail("[达摩三绝剑]必须配合达摩剑法才可以发出绝技！\n");         
    
    me->add_temp("apply/attack", extra);    
    me->add_temp("apply/damage", extra*3);

        msg = HIY  "\n$N使出[达摩三绝剑]第一绝,身体突然加快猛刺$n！\n" NOR;     
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);   
        for(i=0;i<extra/500;i++)
        {
        	msg = HIM "$N身如燕子，剑如风云！\n" NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);   
        }
  
       	msg =  HIY"$N使出[达摩三绝剑]第二绝，闪电般直刺$n！\n"NOR;        
		COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        for(i=0;i<extra/500;i++)
        {       
	       msg = HIB "$N剑游无极，气涌剑身！\n" NOR;  
	       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);                  
     	}
     	
       	msg =  HIY"$N使出[达摩三绝剑]第三绝，身体微转挥剑向$n削去！\n"NOR;  
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        for(i=0;i<extra/500;i++)
        {
	        msg = HIW "$N挥剑闭目，突发长啸！\n" NOR;         
	        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);              
       	}

     me->add_temp("apply/attack", -extra);   
     me->add_temp("apply/damage", -extra*3);
     me->start_busy(4);        
    return 1;
}  


