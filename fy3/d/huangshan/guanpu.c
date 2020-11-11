// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "观瀑亭");
        set("long", @LONG
一座六方翘角，顶覆琉璃的小亭，坐在这里，可以远观黄山三大
名瀑之一的“百丈泉”，由此看百丈泉，只见清潭，紫云二峰有飞泉
倾泄，势如银河天降，雨少时，如轻纱薄雾，雨足时则如千匹白练，
高悬天际，实在美不胜收。
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"wenquan",
]));
        set("objects", ([
                __DIR__"npc/katai" : 1,
       ]) );
        set("outdoors", "huangshan");
	set("coor/x",-520);
	set("coor/y",-500);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
