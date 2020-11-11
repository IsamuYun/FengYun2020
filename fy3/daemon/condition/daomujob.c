#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
    object obj,ob2,place;
	int i;
	string arg;
	me = this_player();	
	arg = me->query("name")+"的盗墓者";
	place = environment(me);

	ob2 = present("daomu ren",place);
	me->apply_condition("daomujob", duration - 1);

	if (duration <1)
		return 0;

	if (ob2)
	{
		if (ob2->query("name") == me->query("name") +"负责擒拿的盗墓者" )
				return 1;
	}
		if (duration %3 == 0)
		{

	 if (place->query("short") == "南天门" && me->query_temp("daomu") == 3)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/d/taishan/nantian");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"负责擒拿的盗墓者");
		message_vision("不知从哪又串出一盗墓者。\n",obj);
		return 1;
	}
	 if (place->query("short") == "镇龙塔" && me->query_temp("daomu") == 1)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/d/xj/zhenlong");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"负责擒拿的盗墓者");
		message_vision("不知从哪又串出一盗墓者。\n",obj);
		return 1;
	}
	 if (place->query("short") == "孤峰绝顶" && me->query_temp("daomu") == 2)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/d/bat/ren3");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"负责擒拿的盗墓者");
		message_vision("不知从哪又串出一盗墓者。\n",obj);
		return 1;
	}
	if (place->query("short") == "迎梅客栈" && me->query_temp("daomu") == 4)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/u/guanwai/inn");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"负责擒拿的盗墓者");
		message_vision("不知从哪又串出一盗墓者。\n",obj);
		return 1;
	}
	 if (place->query("short") == "紫霄宫" && me->query_temp("daomu") == 5)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/u/wudang/zhixiao");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"负责擒拿的盗墓者");
		message_vision("不知从哪又串出一盗墓者。\n",obj);
		return 1;
	}
	 if (place->query("short") == "山庄后院" && me->query_temp("daomu") == 6)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/u/resort/back_yard");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"负责擒拿的盗墓者");
		message_vision("不知从哪又串出一盗墓者。\n",obj);
		return 1;
	}
	 if (place->query("short") == "大厅" && me->query_temp("daomu") == 7)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/u/palace/dating");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"负责擒拿的盗墓者");
		message_vision("不知从哪又串出一盗墓者。\n",obj);
		return 1;
	}
	 if (place->query("short") == "礁石" && me->query_temp("daomu") == 8)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/d/tieflag/rock0");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"负责擒拿的盗墓者");
		message_vision("不知从哪又串出一盗墓者。\n",obj);
		return 1;
	}
	 if (place->query("short") == "软红山庄" && me->query_temp("daomu") == 9)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/d/shenshui/ruanhong");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"负责擒拿的盗墓者");
		message_vision("不知从哪又串出一盗墓者。\n",obj);
		return 1;
	}
	 if (place->query("short") == "后花园" && me->query_temp("daomu") == 10)
	{	
	    obj = new("/d/wiz/fyup/npc/daomu");
		obj->move("/d/qingping/garden");
		obj->set("owner",me->query("id"));
		obj->set("name",me->query("name")+"负责擒拿的盗墓者");
		message_vision("不知从哪又串出一盗墓者。\n",obj);
		return 1;
	}
		
		}
		return 1;
}


