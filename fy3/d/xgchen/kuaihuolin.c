#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","快活林酒家");
	set("long",@LONG
这里就是风云城里著名的快活林酒家了，由于酒店的余老板善于经营很多
知名人士都在这里开办酒席以庆祝一些事情。酒店人来人往，据说连神仙
也都经常光顾这里呢。
LONG  
	);
	set("exits",([
		"westdown":"/d/fy/fysquare",
		"enter":"/d/fy/khl_hall",
		]));
	set("objects",([
		"/d/fy/npc/yuyoucai" : 1,
		]));
	set("no_fight",1);
	set("no_huanlong",1);
	set("no_burn",1);
	set("no_magic",1);
	set("no_spells",1);
	set("coor/x",5);
	set("coor/y",0);
	set("coor/z",5);
    setup();
}
int valid_leave(object me,string dir)
{
	if (userp(me))
	if ( dir=="westdown" && me->query_temp("gold_given"))
		return notify_fail("请定义酒席和喜金的数？\n");
	if ( dir=="enter" && me->query_temp("gold_given"))
	{
		return notify_fail("请先定义酒席的名称和喜金的数量。\n");
	}
	else{
		if ( dir=="enter" && !(me->query_temp("host")) && !(me->query_temp("guest")))
			return notify_fail("你还不能进去。\n");
		else {
			return 1;
		}
	}
}
