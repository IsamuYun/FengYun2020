inherit ROOM;
void create()
{
        set("short", "练武场");
        set("long", @LONG
这是一间宽大的练武场，十八般兵器样样齐全，还有几个练功用的木桩。
LONG
        );
        set("exits", ([ 
		  "east" : __DIR__"room7",		  
		]));         

//(3250,30,-30)
    set("coor/x",3250);
	set("coor/y",30);
	set("coor/z",-30);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
