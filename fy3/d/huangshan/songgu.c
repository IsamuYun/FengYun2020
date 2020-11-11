// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "松谷庵");
        set("long", @LONG
长长的石阶，沿途尽是茂林修竹，树枝上挂着云雾草，越发增加了
清凉幽静的感觉，和前面的险峻截然不同。走完石阶便是松谷庵，这是
一座明代的道观，庵前翠竹如海，诸潭环布，景色清幽至极。后面便是
五龙潭和翡翠池。

                  [42;41m┏━━━━━━━━━┓[0m
                  [42;41m┃[33m   松 谷 幽 静 [42;41m   ┃[0m
                  [42;41m┗━━━━━━━━━┛[0m
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"feicui",
  "northup" : __DIR__"caishi",
  "east" : __DIR__"diezhang",
]));
        set("objects", ([
        __DIR__"npc/master" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-650);
	set("coor/y",-540);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
