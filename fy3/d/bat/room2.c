inherit ROOM;
void create()
{
        set("short", "丹房");
        set("long", @LONG
这是一间炼丹的丹房，你刚进来就闻到一股刺鼻的药草的味道，
屋里很凌乱，似乎刚刚被人翻过，各种各样的瓶罐堆的到处都是。
靠墙放着个大药柜。
LONG
        );
        set("exits", ([ 
		  "south" : __DIR__"zoulang1",		  
		]));         

//(3290,40,-30)
    set("coor/x",3290);
	set("coor/y",40);
	set("coor/z",-30);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
