
inherit ROOM;

void create()
{
	set("short", "客栈");
	set("long", @LONG
客栈门前，一根三丈高的旗杆，上面挂著四个斗大的灯笼，上面
写著“清平客栈”此客栈乃武当俗家弟子，人称“清平剑客”董剑清
所开。客栈不是很大，但装饰得很文雅。既使是来武当山挑衅的人，
在这里也可以受到很好的招待。
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"xzroad1",
	]));
        set("objects", ([
                __DIR__"npc/waiter" : 1,
        ]) );
	set("coor/x",90);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",90);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
replace_program(ROOM);

}
