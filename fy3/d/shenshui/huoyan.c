// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "火岩洞口");
        set("long", @LONG
原来整个神水宫是建筑在山腹之中，整个工程的巨大可想而知。你走到这里
眼前又是一番不同的景色，不远处一个洞口向外散发着热气，北面是一间美伦美
焕的大殿，南边的石梯上远远的也有几间房屋，只是异常的昏暗，看不太清楚。
LONG
        );
        set("outdoors","shenshui");
        set("exits", ([ 
   "down" : __DIR__"migong2",
  "northup" : __DIR__"gong",
  "southup" : __DIR__"ruanhong",
]));

   set("objects", ([ 
      __DIR__"npc/jian": 1,
   ]) );
	set("outdoors","shenshui");
	set("coor/x",200);
	set("coor/y",12330);
	set("coor/z",-20);
	setup();
        replace_program(ROOM);
}
