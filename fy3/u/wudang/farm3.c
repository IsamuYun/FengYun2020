
inherit ROOM;

void create()
{
	set("short", "ׯ�ڵ�");
	set("long", @LONG
һ�������͵�������а��˸ߵ���˶������������罭����
���㣬��������֮����ӿ�Ĳ��Σ��Ĵ�Ʈҡ�����뵽�����е�����,
������Ȼ���¡� 
LONG
	);
	set("exits", ([
  		"north" : __DIR__"farm3",
  		"south" : __DIR__"farm1",
  		"east" : __DIR__"farm3",
  		"west" : __DIR__"farm7",
	]));
	set("outdoors", "wudang");
	set("coor/x",75);
	set("coor/y",-70);
	set("coor/z",0);
	set("coor/x",75);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}
