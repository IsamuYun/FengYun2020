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
        if ( extra < 221) return notify_fail("你的清风十三式还不够纯熟！\n"); 
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("［十三式连击］只能对战斗中的对手使用。\n"); 

        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);

        weapon=me->query_temp("weapon");
        msg = HIG "$N心神进入止水不波的清明天地，手中"+weapon->name()+"沿着一道奇古而又自然轨迹缓缓摆动，空气中忽然有一种清冽的感觉。\n\n"NOR ;
        message_vision(msg,me);
        msg = HIW "蓦然，$N双眼倏地睁亮，腾空爆喝一声，清风十三式终于一气呵成，连环击出，有若脱弦之箭游龙破浪般直奔$n而去。\n\n" ;
        message_vision(msg,me,target);
        
        me->set_temp("qingfeng-act",0);
        msg = HIW  "清风第一式    清-风-徐-来" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        me->set_temp("qingfeng-act",1);
        msg = HIW  "清风第二式    流-空-萤-火" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 
        
        me->set_temp("qingfeng-act",2);
        msg = HIW  "清风第三式    竹-外-山-岚" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 
        
        me->set_temp("qingfeng-act",3);
        msg = HIW  "清风第四式    云-淡-风-轻" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 
        
        me->set_temp("qingfeng-act",4);
        msg = HIW  "清风第五式    空-穴-来-风"NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 

        me->set_temp("qingfeng-act",5);
        msg = HIW  "清风第六式    落-絮-轻-扬" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
        
        me->set_temp("qingfeng-act",6);
        msg = HIW  "清风第七式    霜-笛-清-晓" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 
        
        me->set_temp("qingfeng-act",7);
        msg = HIW  "清风第八式    风-动-千-铃" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 
        
        me->set_temp("qingfeng-act",8);
        msg = HIW  "清风第九式    绿-涨-春-风" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 
        
        me->set_temp("qingfeng-act",9);
        msg = HIW  "清风第十式    寒-梅-落-雪"NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 

        me->set_temp("qingfeng-act",10);
        msg = HIW  "清风第十一式  雁-阵-偏-吹" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->set_temp("qingfeng-act",11);        
        msg = HIW  "清风第十二式  风-送-浮-萍" NOR; 
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg); 

        me->set_temp("qingfeng-act",12);        
        msg = HIW  "清风第十三式  落-霞-流-散" NOR; 
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
