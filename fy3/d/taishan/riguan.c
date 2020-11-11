// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","日观峰");
  set("long",@LONG
此处是观览日出东海最佳地方，北依悬崖，南临深谷，凉风习习，
白云飘浮，俯览群山若丘，仰观苍穹如幕，每日清晨，一轮红日自东海
扶桑树上横空出世，人高云低，日在脚下，大有一举手可以扪天之势，
历代英雄到此，无不为之豪情涌动。
LONG
  );
  set("exits",([
	"south" : __DIR__"zhanlu",
               ]));
        set("outdoors", "fengyun");
	set("coor/x",-460);
	set("coor/y",-300);
	set("coor/z",120);
	setup();
  	replace_program(ROOM);
}
