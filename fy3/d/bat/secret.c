//3300,0,10
inherit ROOM;
void create()
{
        set("short", "密室 ");
        set("long", @LONG
这是一间非常隐秘的房间，没有窗户，只点着一根蜡烛，
烛光黯淡，有如一点暗夜里的鬼火。
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"feng",
		  "up" : __DIR__"tt1",
		]));         
		set("objects",([
			__DIR__"npc/kumei" : 1,
       	]) );

   set("coor/x",3300);
	set("coor/y",20);
	set("coor/z",-20);
	set("no_magic",1);
      set("no_dazuo",1);

	setup();
    replace_program(ROOM);

}
