// haunt.c

#include <ansi.h>

inherit F_CLEAN_UP;
#define MAX_GUARD 4
int scribe(object me, object sheet)
{
   	object newsheet;
  	string err;
	  int lv;
	 lv = (int)me->query("saveme");
	if (!lv)   me->set("saveme",1);
	lv = (int)me->query("saveme");

        if((int)me->query_skill("scratching") < 90 )
                return notify_fail("你的符之术不够高！\n");

        if( sheet->name() != "桃符纸" ) 
                return notify_fail("天师符要画在桃符纸上！\n");

        if( (int)me->query("mana") < 75*lv ) 
                return notify_fail("你的法力不够了！\n");
        if(me->query("lifetili")< 10*lv)
	   return notify_fail("你的活力不够！\n");

   	if ( random(100)+lv*10 >= 70) 
	{
        sheet->add_amount(-1);
        seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "天师符" NOR, 
                ({ "save-me sheet", "sheet"}));      
        newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
        newsheet->move(me);
        me->add("mana", -75*lv);
        me->add("lifetili",-10*lv);
        me->receive_damage("sen", 10);
        me->save();
        message_vision("$N写了一道天师符。\n" NOR, me);
			if(me->query("saveme") < (me->query("level")/10) && userp(me))
		{
		  me->add("saveme_exp",1);
	      tell_object(me, "你的【天师符】获得了一点技能熟练度。\n"NOR);
	  if(me->query("saveme_exp") > (me->query("saveme")*me->query("saveme")*100)&&(me->query("saveme")<10))
			{
		me->add("saveme",1);
		me->set("saveme_exp",0);
	      tell_object(me, HIW"你的【天师符】熟练上升了。\n"NOR);
			}
		}
	}
	else
		 tell_object(me, "由于不够熟练，你画符失败了。\n"NOR);
         me->start_busy(1);
        return 1;
}

int do_burn(object sheet)
{ 
        object obj, soldier, me;
	int	spells;

	me = this_player();
        if( !me->is_fighting() )
                return notify_fail("没有人要杀你！\n");
        if( me->query_temp("max_guard") > me->query("saveme")/2+1 )
                return notify_fail("你已经召唤太多天兵鬼卒了！\n");
        message_vision("$N集中精神，祭起三味真火，唿的一声" + sheet->name() +
     		"着了起来！\n", this_player());
        me->receive_damage("sen", 20);
        if( random(me->query("mana")) < 200 ) {
                message("vision", "但是什麽也没有发生。\n", environment(me));
                return 1;
        }
	spells = me->query_skill("scratching");
        seteuid(getuid());  
	  if( random(10) < 5 )
                soldier = new("/obj/npc/heaven_soldier");
       else            
	 soldier = new("/obj/npc/hell_guard");
        soldier->move(environment(me));
        soldier->invocation(me, spells);
	soldier->set("possessed", me);
	me->add_temp("max_guard",1);
	me->remove_all_killer();
        message_vision(HIB "\n$N躲在$n的背后喊道：给我杀！\n" NOR, me, soldier );
        message_vision(HIB "\n$n替$N挡住了所有敌人的攻击！\n" NOR, me, soldier );
        return 1;
}
 int help(object me)
{
        write(YEL"\n三清符咒之天师符："NOR"\n");
	write(@HELP

      点燃它可以召唤神兵替你抵挡敌人攻击。

     天师符每上升一级，增加画符的成功率10%，增加天兵的三围。
     天师符每上升两级，增加可召唤的天兵一名。

HELP
	);
	return 1;
}


