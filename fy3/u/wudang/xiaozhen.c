
inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
�������䵱ɽ��Ψһ��һ��С��С���Ǻܴ󣬵�ȴ�ܷ�����
�������䵱ɽ�ţ����м�ʹ����Сͯ��Ҳ�Ἰ��̫��ȭ���������С
�򣬾����䵱�ɵ���Դ�ء��䵱ɽ��
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"xzroad1",
		"north" : __DIR__"bwuroad2",
		"east" : "/d/taoyuan/taolin",
	]));
	set("outdoors", "wudang");
	set("coor/x",100);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",-30);
	set("coor/z",0);
	set("coor/x",100);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
