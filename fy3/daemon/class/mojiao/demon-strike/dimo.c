// chillgaze.c

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target, int amount)
{
	object *ob;
	int i, skill, damage,lv;
	lv = (int)me->query("dimo");
		if (!lv)   me->set("dimo",1);
		lv = (int)me->query("dimo");	

	if( !me->is_fighting() )
		return notify_fail("［地魔诀］只能在战斗中使用。\n");

	if( (int)me->query("force") < 50*lv)
		return notify_fail("你的内力不够。\n");
	if( (int)me->query("sen") < 40*lv)
		return notify_fail("你的心神太过涣散。\n");

	if (me->query_temp("ondimo"))
		return notify_fail("目前还不能使用地魔诀。\n");

	skill = me->query_skill("demon-strike",1);

	me->add("force", -50*lv);
	me->receive_damage("sen", 40*lv);

		if ( random(100)+lv*5 >= 50) 
	{
	message_vision(
		HIB "\n$N双臂暴长，发动了如意地魔连环八掌中的［地魔诀］，刹那间$N进入了剑心通明的境界。\n" NOR, me);

        me->add_temp("apply/attack", skill*lv+1000);
        me->set_temp("ondimo", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill*lv+1000 :), 10+skill/10);
	  me->start_busy(1);
	}
	else 
	{
	write("由于不够熟练，你施展地魔诀失败了。\n");
	}
	  me->start_busy(2);
        return 1;

}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->delete_temp("ondimo");
        tell_object(me, HIG"你的地魔诀失去效果了。\n"NOR);
		if(me->query("dimo") < (me->query("level")/10) && userp(me))
	{
	  me->add("dimo_exp",1);
	      tell_object(me, "你的【地魔诀】获得了一点技能熟练度。\n"NOR);
	  if(me->query("dimo_exp") > (me->query("dimo")*me->query("dimo")*100)&&(me->query("dimo")<10))
		{
		me->add("dimo",1);
		me->set("dimo_exp",0);
	      tell_object(me, HIW"你的【地魔诀】熟练上升了。\n"NOR);
		}
	}
}
 

int help(object me)
{
        write(YEL"\n如意地魔连环八掌之地魔诀："NOR"\n");
	write(@HELP

      魔教独闯的武功绝学，能集中精神，提高战斗时的物理命中。
	
	  如意地魔连环八掌等级每提升一级，提升物理命中一点，并延长收招时间。
      地魔诀等级每提升一级，增加技能施展成功率，并且提高一倍的物理命中。
     

HELP
	);
	return 1;
}

