inherit ROOM;
void create()
{
        set("short", "画室");
        set("long", @LONG
屋子不大，不知何处点了支檀香，颇有一股脱尘出俗的意味，
靠东面的墙放着一张桌子，桌上文房四宝齐全，似是主人作画的
地方。奇怪的是都好象很久没有人用过。
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"shushi",
		  "east" : __DIR__"feng",
		]));         
		set("objects",([
			__DIR__"npc/tong4" : 1,
       	]) );

//(3300,30,-20)

    set("coor/x",3300);
	set("coor/y",30);
	set("coor/z",-20);
	set("no_magic",1);

	setup();
    replace_program(ROOM);

}
