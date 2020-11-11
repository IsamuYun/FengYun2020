inherit ROOM;
void create()
{
        set("short", "走廊");
        set("long", @LONG
一条几乎伸手不见五指的走廊，透着森森的寒意和杀机。
仅有几线灯光从两旁的屋内射出来。这里渗透着男人的汗臭
和廉价粉脂的味道。
LONG
        );
        set("exits", ([ 
		  "east" : __DIR__"room1",
		  "west" : __DIR__"zoulang2",
		  "north" : __DIR__"room2",
		  "south" :__DIR__"room3",
		]));         
		set("objects",([
        	__DIR__"npc/xunluo" : 1,
			__DIR__"npc/dizi" : 1,
       	]) );
//3290,30,-30
    set("coor/x",3290);
	set("coor/y",30);
	set("coor/z",-30);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
