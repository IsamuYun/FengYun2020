// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,lev;
        object weapon;

        extra = me->query_skill("qingfeng-sword",1); 
        if ( extra < 221) return notify_fail("������ʮ��ʽ���������죡\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("��ʮ��ʽ������ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);

        weapon=me->query_temp("weapon");
        msg = HIG "$N�������ֹˮ������������أ�����"+weapon->name()+"����һ����Ŷ�����Ȼ�켣�����ڶ��������к�Ȼ��һ�������ĸо���\n\n"NOR ;
        message_vision(msg,me);
        msg = HIW "��Ȼ��$N˫��ٿ���������ڿձ���һ�������ʮ��ʽ����һ���ǳɣ�������������������֮���������˰�ֱ��$n��ȥ��\n\n" ;
        message_vision(msg,me,target);
        
        me->set_temp("qingfeng-act",0);
        msg = HIW  "����һʽ    ��-��-��-��" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        me->set_temp("qingfeng-act",1);
        msg = HIW  "���ڶ�ʽ    ��-��-ө-��" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 
        
        me->set_temp("qingfeng-act",2);
        msg = HIW  "������ʽ    ��-��-ɽ-�" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 
        
        me->set_temp("qingfeng-act",3);
        msg = HIW  "������ʽ    ��-��-��-��" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 
        
        me->set_temp("qingfeng-act",4);
        msg = HIW  "������ʽ    ��-Ѩ-��-��"NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 

        me->set_temp("qingfeng-act",5);
        msg = HIW  "������ʽ    ��-��-��-��" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        me->set_temp("qingfeng-act",6);
        msg = HIW  "������ʽ    ˪-��-��-��" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 
        
        me->set_temp("qingfeng-act",7);
        msg = HIW  "���ڰ�ʽ    ��-��-ǧ-��" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 
        
        me->set_temp("qingfeng-act",8);
        msg = HIW  "���ھ�ʽ    ��-��-��-��" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 
        
        me->set_temp("qingfeng-act",9);
        msg = HIW  "����ʮʽ    ��-÷-��-ѩ"NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 

        me->set_temp("qingfeng-act",10);
        msg = HIW  "����ʮһʽ  ��-��-ƫ-��" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->set_temp("qingfeng-act",11);        
        msg = HIW  "����ʮ��ʽ  ��-��-��-Ƽ" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 

        me->set_temp("qingfeng-act",12);        
        msg = HIW  "����ʮ��ʽ  ��-ϼ-��-ɢ" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 
                
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra);

		lev = 6 - (int)me->query_skill("wuzheng-force",1)/100;
        if(lev<2)
        {
        	lev = 2;
        }
        
        me->start_busy(lev);

        return 1; 
}
