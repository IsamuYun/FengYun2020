// 神魔灭  written by tiandi
#include <ansi.h>
inherit F_CLEAN_UP;
object offensive_target(object me)
{
	int sz;
	object *enemy;

	enemy = me->query_enemy();
	if( !enemy || !arrayp(enemy) ) return 0;

	sz = sizeof(enemy);
	if( sz > 4 ) sz = 4;

	if( sz > 0 ) return enemy[random(sz)];
	else return 0;
}

int exert(object me, object target,int amount)
{
       int skill,myexp,urexp,force,getforce;
	string msg;
	if( !me->is_fighting() )
		return notify_fail("［神魔灭］只能在战斗中使用。\n");
	skill = (int)me->query_skill("moshen-force",1);
	if( skill < 50 )
		return notify_fail("你的神魔诀不够。\n");

	if( !target || target==me ) {
		target = offensive_target(me);
		if( !target) return notify_fail("你要对谁施展［神魔灭］？\n");
	}
	myexp = (int)me->query("combat_exp");
	urexp = (int)target->query("combat_exp");
	force = (int)target->query("force");
	if( me->query("TASK") < 1300  || !me->query("marks/kuaihuo") ) 
    		   return notify_fail("以你目前的状况，还没有资格用这一招。\n");
	if ( force < 50) force = 50;
	msg = BLU"使出神魔决中的［神魔灭］一式，双口扣向$n的经脉，试图将$n的真气化为己用。\n"NOR;
	message_vision(msg,me,target);
	if ( random(myexp)*skill/50 < urexp ) 
		{
		msg = "$n见识渊博，见$N出招如此，便先一步闪了过去。\n";
		me->start_busy(2);
		}
	else 	{
		getforce = force / 5;
		if ( getforce > 500 ) getforce =500;
		target->add("force",-getforce);
		me->add("force",getforce);
		if ( me->query("force") > me->query("max_force")*3)
			me->set("force",me->query("max_force"));
		msg = "$N抓着$n的脉门不放，$n只觉得一股真气在往外泄，并且难以控制！\n";
		me->start_busy(2);
		}
	message_vision(msg,me,target);
	return 1;
}
