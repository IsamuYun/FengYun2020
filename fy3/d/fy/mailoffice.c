//added by atu for LSFY 2000/01/18

inherit ROOM;
void create()
{
	set("short", "乱世风云邮局");
	set("long", @LONG
这里是一个新建的邮局。据说是阿土仔为了测试刚刚改起来的.
LONG);
       set("exits", ([ 
		"south" : __DIR__"mailst",
	]));
	set("objects", ([
       	"/questnew/postman" : 1,
	]) );

	set("coor/x",50);
	set("coor/y",10);
	set("coor/z",0);
	setup();
       replace_program(ROOM);
}
