inherit ROOM;
void create()
{
        set("short", "黑暗走廊");
        set("long", @LONG
这的走廊似乎更加黑暗和阴冷，还透着浓厚的血腥气味。
周围的空气似乎都已经凝结了起来，沉重地让人透不过气来。
LONG
        );
        set("exits", ([ 
		  "east" : __DIR__"zoulang1",
		  "west" : __DIR__"dating",
		]));         
//3280,30,-30
    set("coor/x",3280);
	set("coor/y",30);
	set("coor/z",-30);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
