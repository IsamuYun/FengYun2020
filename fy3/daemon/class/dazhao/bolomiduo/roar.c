// roar.c

#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
	object *ob;
	int i, skill, damage,lv,fekee;
	      
	skill = me->query_skill("bolomiduo",1) ;

	if( !me->is_fighting() )
		return notify_fail("［无南金刚］只能在战斗中使用。\n");
	if( target != me ) return notify_fail("你只能提升自己的防御。\n");

	lv = (int)me->query("roar");
	if (!lv)   
		me->set("roar",1);
	lv = (int)me->query("roar");
	if( (int)me->query("force") < 150 *lv)
		return notify_fail("你的内力不够。\n");
	fekee = (int)me->query("max_kee")/10;
	if( (int)me->query("kee") < fekee*lv)
		return notify_fail("你的气血不够。\n");

	skill = me->query_skill("bolomiduo",1);
       if( (int)me->query_temp("wunan") )
		 return notify_fail("你已经在运功中了。\n");
      me->add("force", -150*lv);
	  
	  me->receive_damage("kee", fekee*lv);

	if ( random(100)+lv*5 >= 50) 
	{
       	message_vision(HIR "$N气起丹田，突然咏出低沉有力的无南金刚佛法，顿时感到肌肤变得坚硬无比！\n" NOR, me);
        me->add_temp("apply/defense", lv*skill/2);
        me->set_temp("wunan", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
lv*skill/2 :), lv*30);
	  me->start_busy(1);
	}
	else 
	{
	write("由于不够熟练，你施放无南金刚失败了。\n");
	}
	  me->start_busy(2);
        return 1;

}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/defense", - amount);
        me->delete_temp("wunan");
        tell_object(me, HIG"你的无南金刚失去效果了。\n"NOR);
	if(me->query("roar") < (me->query("level")/10) && userp(me))
	{
	      me->add("roar_exp",1);
	      tell_object(me, "你的【无南金刚】获得了一点技能熟练度。\n"NOR);
	  if(me->query("roar_exp") > (me->query("roar")*me->query("roar")*100)&&(me->query("roar")<10))
		{
		me->add("roar",1);
		me->set("roar_exp",0);
	      tell_object(me, HIW"你的【无南金刚】熟练上升了。\n"NOR);
		}
	}
}
 int help(object me)
{
        write(YEL"\n婆萝蜜多心经之无南金刚："NOR"\n");
	write(@HELP

      大昭寺院秘法，舍弃自身的气血来换取临时防御
	  婆萝蜜多心经等级每上升两级，增加防御一点。
	  无南金刚等级每上升一级，增加防御一倍，延长收招时间三十秒。

HELP
	);
	return 1;
}


