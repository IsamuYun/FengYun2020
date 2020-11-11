// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "百丈泉");
        set("long", @LONG
黄山三大名瀑之一，因飞流直下而名，由观瀑亭远看极为壮观，
到此近观，但见飞珠溅玉，水声轰鸣，一股清凉之气扑面而来，别有
一番妩媚风情。北面的九龙瀑更是绝佳。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"qingluan",
  "northup" : __DIR__"jiulong",
]));
        set("objects", ([
                __DIR__"npc/shui" : 1,
       ]) );
	set("resources/water",1);
        set("outdoors", "huangshan");
	set("coor/x",-540);
	set("coor/y",-500);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
