//by tiandi 200806

#include <ansi.h>

inherit F_CLEAN_UP;

int scribe(object me, object sheet)
{
   	object newsheet;
  	string err;
	  int lv;
	 lv = (int)me->query("far");
	if (!lv)   me->set("far",1);
	lv = (int)me->query("far");

        if((int)me->query_skill("scratching") < 50 )
                return notify_fail("你的符之术不够高！\n");

        if( sheet->name() != "桃符纸" ) 
                return notify_fail("天通眼符要画在桃符纸上！\n");

        if( (int)me->query("mana") < 50 ) 
                return notify_fail("你的法力不够了！\n");
        if(me->query("lifetili")< 11 - lv)
	   return notify_fail("你的活力不够！\n");

   	if ( random(100)+lv*10 >= 50) 
	{
        sheet->add_amount(-1);
        seteuid( geteuid(me));
        newsheet = new("/obj/magic_seal");
        newsheet->set_name(YEL "天通眼符" NOR, 
                ({ "far-vision sheet", "sheet"}));      
        newsheet->set("burn_func", (: call_other, __FILE__, "do_burn" :));
        newsheet->move(me);
        me->add("mana", -50);
		me->add("lifetili",-11 + lv);
        me->receive_damage("sen", 5);
        me->save();
        message_vision("$N写了一道天通眼符。\n" NOR, me);
			if(me->query("far") < (me->query("level")/10) && userp(me))
		{
		  me->add("far_exp",1);
	      tell_object(me, "你的【天通眼符】获得了一点技能熟练度。\n"NOR);
	  if(me->query("far_exp") > (me->query("far")*me->query("far")*100)&&(me->query("far")<10))
			{
		me->add("far",1);
		me->set("far_exp",0);
	      tell_object(me, HIW"你的【天通眼符】熟练上升了。\n"NOR);
			}
		}
	}
	else
		 tell_object(me, "由于不够熟练，你画符失败了。\n"NOR);
 
        return 1;
}


int do_burn(object sheet)
{ 
        string target;
        object obj;

        if( !(sheet->query("targetname")) )
                return notify_fail("你想用这道符" NOR 
"看哪里？\n");
        message_vision("$N集中精神，祭起三味真火，唿的一声" + sheet->name() +
     		"着了起来！\n", this_player());
	this_player()->receive_damage("sen", 5);
        target = sheet->query("targetname");
        obj = find_player(target);
        if(!obj) obj = find_living(target);
     if(!obj || wizardp(obj)){
        	message("vision", "你感到眼睛酸酸的，却什么也没看到！\n", this_player());
        } else
        {
        	message("vision", "在闪烁的火光中，你看到：\n", this_player());
		"/cmds/std/look"->look_room(this_player(), environment(obj));
        	message("vision", "你感到脖子发凉，黑暗处好像有双眼睛盯着你！\n", obj);
        	message("vision", "你仔细地看了一下四周，却什么也没有！\n", obj);
        }
        return 1;
}
 int help(object me)
{
        write(YEL"\n三清符咒之天眼通："NOR"\n");
	write(@HELP

      把对方的名字写在此符咒上，再点燃它就能看见对方的周围情况。

      天眼通每上升一级，增加画符的成功率5%。

HELP
	);
	return 1;
}



