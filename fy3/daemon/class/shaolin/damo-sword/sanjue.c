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
    
    if ( extra < 100) return notify_fail("��Ĵ�Ħ�������������죡\n");
    
    if ( me->query("force") < 500) return notify_fail("����������������죡\n");      
    
    if( !target ) target = offensive_target(me);
    if( !target ||  !target->is_character() || !me->is_fighting(target) )
    	return notify_fail("[��Ħ������]ֻ�ܶ�ս���еĶ���ʹ�á�\n");           
    
    weapon = me->query_temp("weapon"); 
    if (!weapon) return notify_fail("[��Ħ������]�����н��ſ��Է���������\n");        
    
    if( (string)weapon->query("skill_type") != "sword")       
         return notify_fail("[��Ħ������]�����н��ſ��Է���������\n");     
    
    if ( (string) me->query_skill_mapped("sword") != "damo-sword")         
         return notify_fail("[��Ħ������]������ϴ�Ħ�����ſ��Է���������\n");         
    
    me->add_temp("apply/attack", extra);    
    me->add_temp("apply/damage", extra*3);

        msg = HIY  "\n$Nʹ��[��Ħ������]��һ��,����ͻȻ�ӿ��ʹ�$n��\n" NOR;     
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);   
        for(i=0;i<extra/500;i++)
        {
        	msg = HIM "$N�������ӣ�������ƣ�\n" NOR;
        	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);   
        }
  
       	msg =  HIY"$Nʹ��[��Ħ������]�ڶ����������ֱ��$n��\n"NOR;        
		COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        for(i=0;i<extra/500;i++)
        {       
	       msg = HIB "$N�����޼�����ӿ����\n" NOR;  
	       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);                  
     	}
     	
       	msg =  HIY"$Nʹ��[��Ħ������]������������΢ת�ӽ���$n��ȥ��\n"NOR;  
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        for(i=0;i<extra/500;i++)
        {
	        msg = HIW "$N�ӽ���Ŀ��ͻ����Х��\n" NOR;         
	        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);              
       	}

     me->add_temp("apply/attack", -extra);   
     me->add_temp("apply/damage", -extra*3);
     me->start_busy(4);        
    return 1;
}  


