
#include <ansi.h>
inherit ITEM;

void create()
{
		set_name("令牌", ({"ling pai","ling" }));
       set_max_encumbrance(10);
       set("unit", "块");
       set("long", "这是一块朱红的令牌,精钢打造，用来证明官府人士的身份。\n带着它你就可以搜寻罪犯(souxun)。\n");
       set("value", 0);
       set("no_drop", "这样东西不能离开你。\n");
       set("no_burn",1);
       set("no_get", "这是朝廷的东西，平常人拿了会惹麻烦的。\n");
       set_weight(200);
       set("place","on");
       setup();
}

void init()
{
      add_action("do_watch","souxun");
}

int do_watch(string arg)
{
	object me = this_player();

	if(me->query_temp("kf_name") && me->query("kf_working") && !me->query_temp("kf_finish"))
	{
		tell_object(me,HIC"你仔细搜寻着"+me->query_temp("kf_name")+"......\n"NOR);
	}
	else
	{
		tell_object(me,"什么？\n");
	}
	
   return 1;
}

