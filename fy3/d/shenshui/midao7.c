// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "山洞秘道");
        set("long", @LONG
转了几个弯，入洞以深，面前是伸手不见五指，周围不时传来小动物
掠过的沙沙声，令人生畏，你想回头却以不知来时的道路。在这里你也分
不清东西南北，只好揣策着方向，壮着胆子摸索着往前走。
LONG
        );
   set("exits", ([ 
      "south" : __DIR__"midao3",
      "north" : __DIR__"midao9",
      "east" : __DIR__"midao8",
      "west" : __DIR__"midao5",
   ]));
	set("coor/x",100);
	set("coor/y",12080);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
