#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{       
string msg;        
int extra;    
   int orforce;   
   object weapon;      
  if(me->is_busy())                
return notify_fail("你现在没空！！\n");     
   extra = me->query_skill("unarmed");     
   if ( extra < 200) return notify_fail("你的天山六阳掌还不够纯熟！\n");    
    if( !target ) target = offensive_target(me);   
     if( !target || !target->is_character()
                 || !me->is_fighting(target) )      
          return notify_fail("［拨开云雾现青天］只能对战斗中的对手使用。\n");  
      me->add("force_factor",extra/5);       
 orforce = (int) me->query("force"); 
       me->add("force",extra/5*100);me->add_temp("apply/attack",extra*extra);
        weapon = me->query_temp("weapon");       
 msg = HIY  "$N使出天山六阳掌中的［拨开云雾现青天］，一招连环六式向$n攻出！\n" NOR;     
   message_vision(msg,me,target);      
  msg = HIW  "阳春白雪!" NOR;      
  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);       
 msg = HIM  "艳阳高照!" NOR;       
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);      
  msg = HIR  "烈日炎炎!" NOR;        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);  
      msg = HIC  "如日中天!" NOR;     
   COMBAT_D->do_attack(me,target, me->query_temp
("weapon"),TYPE_REGULAR,msg);      
  msg = HIY  "夕阳西斜!" NOR;      
  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);     
   msg = HIB  "日落西山!" NOR;        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);   
     me->start_busy(3);       
 me->set("force_factor",0);     
   me->set("force", orforce);
me->add_temp("apply/attack",-extra*extra);

        return 1;}
