
inherit ROOM;

void create()
{
	set("short", "��ɽ·");
	set("long", @LONG
��������������·��ȴ��ƽ̹���������߶���ïʢ�����֣����
����ʱ�������������������ķҷ�����һ����ʹ�����ؿ��ʣ�����
һ�з��ա���Զ��ǰ������һ���ʯ��һ��Сͤ�ӡ�
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"road1",
		"southup" : __DIR__"rock",
		"west" : __DIR__"pine1",
		"east" : __DIR__"pine3",
	]));
	set("outdoors", "wudang");
	set("coor/x",100);
	set("coor/y",-80);
	set("coor/z",10);
	set("coor/x",100);
	set("coor/y",-80);
	set("coor/z",10);
	set("coor/x",100);
	set("coor/y",-80);
	set("coor/z",10);
	set("coor/x",100);
	set("coor/y",-80);
	set("coor/z",10);
	set("coor/x",100);
	set("coor/y",-80);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
