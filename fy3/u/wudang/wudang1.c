
inherit ROOM;

void create()
{
	set("short", "�䵱ǰԺ");
	set("long", @LONG
��Ժ����������������������Ե��䵱�ɵ���ʷ�ƾá���ʯ����
�ɵĵ��棬����������ĺۼ�����Ժ�ľ�ͷ�Ǽ�������ʯ̨�ף�����
̨�׾����䵱���������������һ����ʯС·��ͨ�����档
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"zhixiao",
		"northeast" : __DIR__"wuroad1",
		"out" : __DIR__"wudang",
	]));
	set("outdoors", "wudang");
	set("coor/x",100);
	set("coor/y",-120);
	set("coor/z",50);
	set("coor/x",100);
	set("coor/y",-120);
	set("coor/z",50);
	set("coor/x",100);
	set("coor/y",-120);
	set("coor/z",50);
	set("coor/x",100);
	set("coor/y",-120);
	set("coor/z",50);
	set("coor/x",100);
	set("coor/y",-120);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}
