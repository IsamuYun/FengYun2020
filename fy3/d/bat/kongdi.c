//3290,0,10
inherit ROOM;
void create()
{
        set("short", "空地 ");
        set("long", @LONG
    这是一片空地,四周都是乱石,杂草丛生。北边是一条山道。
    太阳正高挂在西方的天空中。
LONG
        );
        set("exits", ([ 
		  "northup" : __DIR__"ren",
		  "east" : __DIR__"anbian",
		]));         
		set("objects",([
        	__DIR__"npc/dizi" : 1,
       	]) );
    set("outdoors", "bat");
    set("coor/x",3290);
	set("coor/y",0);
	set("coor/z",10);
	set("no_magic",1);set("no_dazuo",1);

	setup();
    replace_program(ROOM);

}
