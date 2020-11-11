// earth.c by tiandi 200805

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet, string arg)
{
        object newsheet;
        string err;
	  int lv;
	 lv = (int)me->query("earth");
	if (!lv)   me->set("earth",1);
	lv = (int)me->query("earth");

	 

        if((int)me->query_skill("scratching") < 20 )
                return notify_fail("你的符之术不够高！\n");

        if( sheet->name() != "桃符纸" )
                return notify_fail("阴界传送符要画在桃符纸上！\n");

        if( (int)me->query("mana") < 50 ) 
                return notify_fail("你的法力不够了！\n");
        if(me->query("lifetili")< 11 - lv)
	   return notify_fail("你的活力不够！\n");
   	if ( random(100)+lv*10 >= 50) 
	{
        sheet->add_amount(-1);
        seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "阴界传送符" NOR, 
                ({ "earth sheet", "sheet"}) );    
        newsheet->set("burn_func", (: call_other, __FILE__, "do_warp":));
        newsheet->move(me);
        me->add("mana", -50);
        me->add("lifetili",-11 + lv);
        me->receive_damage("sen", 10);
        me->save();
        message_vision("$N写了一道阴界传送符。\n" NOR, me);
		if(me->query("earth") < (me->query("level")/10) && userp(me))
		{
		  me->add("earth_exp",1);
	      tell_object(me, "你的【阴界传送符】获得了一点技能熟练度。\n"NOR);
	  if(me->query("earth_exp") > (me->query("earth")*me->query("earth")*100)&&(me->query("earth")<10))
			{
		me->add("earth",1);
		me->set("earth_exp",0);
	      tell_object(me, HIW"你的【阴界传送符】熟练上升了。\n"NOR);
			}
		}
	}
	else
		 tell_object(me, "由于不够熟练，你画符失败了。\n"NOR);
         me->start_busy(1);
        return 1;
}

int do_warp(string target, object who)
{
        object env;

        if( this_player()->query_temp("nofly") || this_player()->query_temp("noburn") )
                return notify_fail("有重要的任务在身，不能使用法术！\n");
        if( who && who!=this_player() )
                return notify_fail("阴界传送符只能对自己使用。\n");
	this_player()->start_busy(random(3)+1);
        env = environment(this_player());
        message("vision",
                HIB + this_player()->name() + "祭起一张阴界传送符。\n"
"忽然四周吹起了一阵凉飕飕的阴风，阴风之中彷佛有许多人影在晃动...\n"
                "然後一阵火光突然爆起！\n" NOR, env);
        message("vision", "可是...." + this_player()->name() + 
"已经不见了。\n", environment(this_player()), ({this_player()}));
 this_player()->start_busy(4);
call_out("move_him",1+random(4),this_player());
 return 1;
}
 
int move_him(object me)
{
  message("vision",
 CYN 
"你只觉得身子不断下坠，一直下坠，一直下坠，一直下坠，一直下坠 .....\n"
  NOR     
"不知道什麽时候，你发现你其实一直都站在坚硬的地面上，可是四周的景物\n"
                "却不一样了....\n", me);
  me->move(DEATH_ROOM);
 return 1;
}
 int help(object me)
{
        write(YEL"\n三清符咒之阴间传送符："NOR"\n");
	write(@HELP

      点燃它能让人返回阴间。

      阴间传送符每上升一级，增加画符的成功率10%，并降低活力消耗一点。

HELP
	);
	return 1;
}




