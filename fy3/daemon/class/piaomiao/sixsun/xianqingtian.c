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
return notify_fail("������û�գ���\n");     
   extra = me->query_skill("unarmed");     
   if ( extra < 200) return notify_fail("�����ɽ�����ƻ��������죡\n");    
    if( !target ) target = offensive_target(me);   
     if( !target || !target->is_character()
                 || !me->is_fighting(target) )      
          return notify_fail("�۲��������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");  
      me->add("force_factor",extra/5);       
 orforce = (int) me->query("force"); 
       me->add("force",extra/5*100);me->add_temp("apply/attack",extra*extra);
        weapon = me->query_temp("weapon");       
 msg = HIY  "$Nʹ����ɽ�������еģ۲�������������ݣ�һ��������ʽ��$n������\n" NOR;     
   message_vision(msg,me,target);      
  msg = HIW  "������ѩ!" NOR;      
  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);       
 msg = HIM  "��������!" NOR;       
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);      
  msg = HIR  "��������!" NOR;        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);  
      msg = HIC  "��������!" NOR;     
   COMBAT_D->do_attack(me,target, me->query_temp
("weapon"),TYPE_REGULAR,msg);      
  msg = HIY  "Ϧ����б!" NOR;      
  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);     
   msg = HIB  "������ɽ!" NOR;        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);   
     me->start_busy(3);       
 me->set("force_factor",0);     
   me->set("force", orforce);
me->add_temp("apply/attack",-extra*extra);

        return 1;}
