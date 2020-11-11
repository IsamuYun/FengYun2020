// animate.c
#include <ansi.h>
inherit F_CLEAN_UP;

int cast(object me, object target)
{
	  int lv;
	 lv = (int)me->query("animate");
	if (!lv)   me->set("animate",1);
	lv = (int)me->query("animate");

        if( me->is_fighting() ) 
		return notify_fail("你正在战斗中！\n");
        
        if( (int)me->query_skill("spells") < 100)
		return notify_fail("你的法术不够高！\n");

        if( !target || !target->is_corpse() ) 
        	return notify_fail("你要驱动哪一具尸体？\n");
        
        if( (int)me->query("mana") < 100*lv)
		return notify_fail("你的法力不够了！\n");

        message_vision(
	"$N对著地上的$n喃喃地念了几句咒语，$n抽搐了几下竟站了起来！\n", me, target);

        target->animate(me, (int)me->query_skill("spells")+(int)me->query_skill("spells")/10*lv);
        me->add("mana", -100*lv);
        me->receive_damage("sen", 10);
				if(me->query("animate") < (me->query("level")/10) && userp(me))
	{
        me->add("animate_exp",1);
	      tell_object(me,"你的【驱尸咒】获得了一点技能熟练度。\n"NOR);
	  if(me->query("animate_exp") > (me->query("animate")*me->query("animate")*100)&&(me->query("animate")<10))
		{
		me->add("animate",1);
		me->set("animate_exp",0);
	      tell_object(me, HIW"你的【驱尸咒】熟练上升了。\n"NOR);
		}
	}
        return 1;
}
 int help(object me)
{
        write(YEL"\n三清道术之驱尸咒"NOR"\n");
	write(@HELP

     驱动的尸体变为僵尸，僵尸以驱动者的灵力为食。

     驱尸咒每上升一级，增加僵尸的各项能力1/10。

HELP
	);
	return 1;
}
 
