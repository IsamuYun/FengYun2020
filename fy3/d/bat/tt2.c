inherit ROOM;
void create()
{
        set("short", "���� ");
        set("long", @LONG
����һ����խ����,�����������ݡ�
LONG
        );
        set("exits", ([ 
		  "down" : __DIR__"tt1",
		  "up" : __DIR__"tt3",
		]));         
		set("objects",([
			__DIR__"npc/bianfu2" : 1,
       	]) );

//(3300,30,-20)

    set("coor/x",3300);
	set("coor/y",20);
	set("coor/z",0);
	set("no_magic",1);set("no_dazuo",1);

	setup();
    replace_program(ROOM);

}
