//�������  writted by tiandi,jjf�ṩ

#include <ansi.h> 
inherit SSERVER; 

string *action = ({
"$n��Ҫ�ٳ���ʱ����Ȼ����$N����һ�Ż�\nһ�����ۼ���һ���˺�Ȼ����һ�����ܵ����棬�Ǹо������صģ���������������ֱ���Լ�����֮ʱ��\n",
"$Nߺ��һ���������������������Ż��棬��������һ����һ����㣬��$nûͷû�Եش򵽣�\n",
"$N�ۼ����֣��ָ�$n��ȥ����Ȼ��ŭ������������$nֻҪһ�������񣬾�Ҫɥ��$N�Ļ�֮��,�����ǡ����ݴ��͡���\n",
"$N���������һ������˸ɲ񣬻���žž���������������˸о����������ڷɽ���\n",
"$Nɱ�Դ���һ��ŭ������ȫ������գ��������գ���������գ�\n",
"$N����һ�ɻ���Ҳ���������������һ�һ������������$n�����һ����\n",
"$N���е�������б��������һ𣬱�մ��֮�����̾ͳ��˻��ţ��Һ�֮�������ڶ���\n",
"$n���ϵĻ�Խ��Խ�����������$nȴæ�ڶ��$N��ʱ�����Ļ���,�޷�����ȥ����Щ��\n"
});

void finish(object me);

int cast(object me, object target)
{ 
       object weapon, env; 
       string msg; 
       int extra, damage; 
       if(!me->is_fighting())
		 return notify_fail(HIR"��������ġ�"NOR"ֻ����ս����ʹ�á�\n"); 

      if( !target ) target = offensive_target(me); 

  if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("��Ҫ��˭ʩչ���������\n");
    
       if( me->query("TASK") < 2300  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("����Ŀǰ��״������û���ʸ�����һ�С�\n");
	if( me->query_temp("yuhuo") ) 
               return notify_fail("������ʹ��"HIR"��������ġ�"NOR"��\n"); 
       if (time()<(me->query_temp("perform/yuhuo")+20)) 
               return notify_fail(HIG"���ʹ����"HIR"��������ġ�"HIG"�����û�����ģ�\n"NOR); 
                
       if( (int)me->query("mana") < 250 ) 
               return notify_fail("��ķ���������\n"); 

       extra = me->query_skill("yaoshen",1); 

       if( extra < 150 ) 
               return notify_fail("�������ȼ�����.\n"); 
	if( (int)target->query("kee") < 1000 ) 
               return notify_fail("ɱ������ţ����\n"); 

       weapon = me->query_temp("weapon"); 

       me->set_temp("yuhuo", 1); 
	me->set_temp("perform/yuhuo",time()); 

       msg = HIY"$N���������������뿪ԭ���ĵط������棬��һɲ�Ǽ䣬���˳�ȥ��\n\n" NOR; 
       message_vision(msg,me); 
        
       damage = extra*5; 
       damage = damage/2 + random(damage); 
	if ( damage > 800 ) damage = 800;
        
       if( random(extra) > target->query_skill("dodge")/5 ) { 
               msg = RED"$n���·����������Ĵ��ط����˻�\n"NOR; 
               target->receive_damage("kee", damage); 
               target->receive_wound("kee", damage/2); 
               message_vision(msg,me,target); 
               COMBAT_D->report_status(target); 
       } 

       msg = HIC"\n$N��ͫ�׿�ʼ������$N����$nԽ��Խ������������ô�öԸ���\n" NOR; 
       message_vision(msg,me,target);  
       env = environment(me); 
            if ( weapon&&weapon->query("id")== "yaoshen-blade")
       call_out("auto_perform", 5, me, target , env, weapon, extra/15); 

            if ( !weapon||weapon->query("id")!= "yaoshen-blade")      me->delete_temp("yuhuo");
       me->start_busy(2); 
       return 1; 
} 

void auto_perform(object me, object target, object env, object weapon, int i) 
{ 
       int damage, extra; 
       string msg; 
	if (i>7) i=7;
    	
	if(!target 
        || weapon->query("id")!= "yaoshen-blade"
        || me->query_temp("weapon")!=weapon 
        || me->query_skill_mapped("spells")!="yaoshen" 
        || environment(target)!=env 
        || environment(me)!=env 
        || i<0 
        || !me->is_fighting(target) 
        || (int)me->query("force")<200 
        || !me->query_temp("yuhuo") ){ 
           finish(me);
               return; 
       } 
       msg = HIR"\n"+action[i]+NOR; 
       message_vision(msg,me,target);
	i--; 
       extra = (int)me->query_skill("yaoshen",1); 
       if( random(extra) >  target->query_skill("dodge")/4 ) { 
       msg = CYN"$n"NOR+CYN"���޿��ˣ���$N��"NOR+weapon->name()+NOR+CYN"���У���ʱ�����ֶ���˼������ˡ�\n"NOR; 
       message_vision(msg,me,target);   
       damage = extra*3; 
       damage = damage/2 + random(damage); 
	if ( damage > 800 ) damage = 800;

       target->receive_damage("kee", damage); 
       COMBAT_D->report_status(target); 
       } 
       call_out("auto_perform", 5, me, target , env, weapon, i); 
} 
void finish(object me) 
{ 
       string msg; 
       
       if( !me ) return; 
       msg = "$N����ʩ����������������˿���.....\n"NOR; 
       message_vision(msg,me); 
       me->delete_temp("yuhuo"); 
} 

