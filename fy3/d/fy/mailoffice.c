//added by atu for LSFY 2000/01/18

inherit ROOM;
void create()
{
	set("short", "���������ʾ�");
	set("long", @LONG
������һ���½����ʾ֡���˵�ǰ�����Ϊ�˲��Ըոո�������.
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
