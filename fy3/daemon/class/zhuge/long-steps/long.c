// long-steps.c
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,force;
	object weapon;
	extra = me->query_skill("long-steps",1);
	force=me->query("force");	
	if( me->query("TASK") < 1900  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("以你目前的状况，还没有资格用这一招。\n");

	if ( extra < 100) return notify_fail("你的［"+HIC"卧"+HIY"龙"+HIR"太"+HIW"玄"+HIB"醉"+NOR"］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if(( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )&&extra>150&&me->query_temp("five")>1)
		return notify_fail("［"+HIC+"秘"+NOR+"·"+HIB+"双龙"+NOR"］只能对战斗中的对手使用。\n");
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［"+HIC+"绝"+NOR+"·"+HIW+"白龙"+NOR"］只能对战斗中的对手使用。\n");
	
	if (force<500) return notify_fail("你的内力不足。\n");
	if(target->is_busy())
		return notify_fail(target->name()+"眼冒金星，如深陷泥潭，动作已经迟缓了！\n");
	message_vision( HIM "$N"HIM"双手合成十字状，嘴上叽里咕噜不知道在念些什么，骤然之间$N"HIM"的周围拘起一团白色瘴气，\n透过天地间的一丝朦胧，$n"HIM"发觉似有雾状物体向自己袭来！！！\n\n"+HIW+"$N"HIW"遥指长空，海天一线，一条银角白龙参天而出，突一张口，打出一道白光直射向$n"HIW"双目。。。。。。\n" NOR ,me,target);
	if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp")*2)
		{
	message_vision("结果$N慢上一步，被白光照伤了双目，动作开始迟缓了！\n",target);
	target->start_busy(2);
		}
	else {
	message_vision("只见$n连忙闭上双眼，神奇般地躲过了$N的招式,并试着向$N发起反击！\n",me,target);
       		if (extra<131||me->query_temp("five")<2)
	    			 {
	     			COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);
	    			}
	    		else {
		    message_vision(HIR"\n不过$N"HIR"早有防备，双手合成人字，只见刹那间一条红飞龙自行跃出，吐出阵阵瘴气，逼得$n"HIR"只能化攻为守！\n"NOR,me,target);
				if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp")*2)
					{
					message_vision("结果$N逃过了第一招，却没能避开这招，被瘴气侵入肺腑，动作开始有点僵硬了！\n",target);
					target->start_busy(3);
					me->add("force",-200);
					}
				else {
				message_vision("$n用尽全身力气纵身往后一跃，再度避开了$N的奇异的攻击！\n"NOR,me,target);
                           		me->start_busy(2);
					me->add("force",-200);
		  	            }
		 	 
			     }
	    }
	return 1;
}
