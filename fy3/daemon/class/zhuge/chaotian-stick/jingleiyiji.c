//惊雷一击 writted by tiandi

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me,object target)
{
        string msg;
        object weapon, weapon2;
        int skill, ap, dp, str,force,str1,force1,damage;
        skill  = me->query_skill("chaotian-stick",1);
 	 str = me->query("str");
	 force = me->query("force");
	
	 if( !target ) target = offensive_target(me);
	 if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                   return notify_fail("「"+HIY"惊雷一击"NOR+"」只能对战斗中的对手使用。\n");
		
	str1 = target->query("str");
	force1 = target->query("force");
         if( me->query("TASK") < 1800  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("以你目前的状况，看来是不能使用这一招了。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
            return notify_fail("你使用的武器不对。\n");
	
	 if (!objectp(weapon2 = target->query_temp("weapon")))
	        return notify_fail("你使用的时机不对。\n");

        if( skill < 100)
            return notify_fail("你的朝天棍等级不够, 不能使用「"+HIY"惊雷一击"NOR+"」！\n");

        if( me->query("force") < 400 )
            return notify_fail("你的内力不够，无法运用「"+HIY"惊雷一击"NOR+"」！\n");

        msg = HIR
    "\n\n$N"HIR"纵身跃起,使出"+HIY"「惊雷一击」"NOR+""+HIR"，双手握紧"NOR""+weapon->name()+""NOR+HIR"从半空中朝$n"HIR"直砸下来，\n只见$N"HIR"人在半空离地尚有数尺，地下已是尘沙飞扬，草木皆非，$N"HIR"已将$n"HIR"退避的空隙封的严严实实。\n"NOR;
        
	 
        ap = random(me->query_skill("staff") + skill)*str*force;
        dp = random(target->query_skill("dodge"))*str1*force1;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            me->add("force",-400);
     	     msg += HIC"\n$n"HIC"只觉一股排山倒海之力朝自己涌来，不由自主地极力后退，手中"NOR""+weapon2->name()+""HIC"顺势往上一格，\n但$N"HIC"毫不停息，一棍砸在"NOR""+weapon2->name()+""HIC"上。\n结果只听“铛”的一声，$n"HIC"手中的"NOR""+weapon2->name()+""HIC"一断为二。\n"NOR;
            damage= skill+(int)me->query_str()*10;
            target->receive_damage("kee", damage, me);
	     target->receive_wound("kee", damage/3, me);
            weapon2->unwield();
	         weapon2->move(target);
	     weapon2->reset_action();
	     weapon2->set("name", "一断为二的"+ weapon2->query("name") );
	     weapon2->set("value", 0);
	     weapon2->set("weapon_prop", 0);
	         weapon2->set("no_drop",0);
	     weapon2->set("long", "一把破烂武器，从中断为两节，破口整齐，看来是被"HIW+me->name()+NOR"劈断的。\n");
	         me->start_busy(3);
		}
        else
        {
            msg += NOR"可是$n轻轻往旁边一闪,避过了$N这势大力沉的一击。\n"NOR;
            me->start_busy(2);
        }
	 message_vision(msg, me, target);
        return 1;
}


