inherit ROOM;
void create()
{
        set("short", "储藏室");
        set("long", @LONG
这是一间储藏室，乱七八糟的东西堆成了山。各种箱子柜子里堆满了杂物。
LONG
        );
        set("exits", ([ 
		  "east" : __DIR__"dating",
		  "west" : __DIR__"room6",
		]));         

//(3260,30,-30)
    set("coor/x",3260);
	set("coor/y",30);
	set("coor/z",-30);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
