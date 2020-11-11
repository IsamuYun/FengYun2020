inherit ROOM;
void create()
{
        set("short", "无名的空地 ");
        set("long", @LONG
空地，乱石，杂草，阴风。海腥味更重了，令人觉得嘴里似乎塞满了盐，
又苦又涩。四周异常昏暗，你连自己的影子都看不清在哪里。杂草在阴风的
鼓动下沙沙地扭个不停。
LONG
        );
        set("exits", ([ 
		  "west" : __DIR__"lin1",
		  "east" : __DIR__"fchuan",
		]));         
		set("objects",([
        	__DIR__"npc/wei" : 1,
       	]) );
    set("outdoors", "bat");
    set("coor/x",1110);
	set("coor/y",-290);
	set("coor/z",-10);
	set("no_magic",1);set("no_dazuo",1);


	setup();
    replace_program(ROOM);

}
