	// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill,lv;
		lv = (int)me->query("daoqiangburu");
		if (!lv)
			me->set("daoqiangburu",1);
		lv = (int)me->query("daoqiangburu");

        if( target != me ) return 
	notify_fail("你只能将［刀枪不入］用在自己的身上。\n");
        if( (int)me->query("force") < 50*lv )     return
        notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("daoqian") ) return 
	notify_fail("你已经在施展［刀枪不入］了。\n");
	skill = me->query_skill_eff_lvl("jin-gang");
	if(skill < 100) return notify_fail("你的金刚不坏功太差了！\n");
	skill = random(skill/2)+skill/2;
	me->add("force", -100*lv);
        message_vision( HIR
"$N拍了拍胸脯，高叫着：＂刀枪不入！刀枪不入！刀枪不入！．．．＂\n" NOR, me);
		write ("你临时增加了"+skill/10*(lv+1)+"点铁布衫等级。\n");
        me->add_temp("apply/iron-cloth", skill/10*(lv+1));
        me->set_temp("daoqian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/10*(lv+1) :), lv*20);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/iron-cloth", - amount);
        me->delete_temp("daoqian");
        tell_object(me, "你的［刀枪不入］的功效散光了。\n");
		me->add("daoqiangburu_exp",1);
	    tell_object(me, "你的【刀枪不入】获得了一点技能熟练度。\n"NOR);
	    if(me->query("daoqiangburu_exp") > (me->query("daoqiangburu")*me->query("daoqiangburu")*100)&&(me->query("daoqiangburu")<10))
		{
		me->add("daoqiangburu",1);
		me->set("daoqiangburu_exp",0);
	      tell_object(me, HIW"你的【刀枪不入】熟练上升了。\n"NOR);
		}
}
 int help(object me)
{
        write(YEL"\n金刚不坏功之刀枪不入："NOR"\n");
	write(@HELP

      此招使用后，在不破防的情况下可以造成反弹伤害。

      刀枪不入等级每上升一级，增加此招硬功加成一成，延长收招时间二十秒。

HELP
	);
	return 1;
}

