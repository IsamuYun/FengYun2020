
inherit ROOM;

void create()
{
	set("short", "СԺ");
	set("long", @LONG
Ժ���������������ݣ�������Ļ�ľ������ҩ�ݣ���ʽ������
�����ۻ����ҡ���ʯС·���ɻ����д�����Ժ��������һ���˽�ͤ��
��ɫ��ͤ������ɫ��ͤ����ͤ������һ��ʯ������ֻʯ�ʡ�
LONG
	);
	set("exits", ([ 
  		"east" : __DIR__"wuroad4",
  		"west" : __DIR__"wuroad2",
	]));
	set("outdoors", "wudang");
	set("coor/x",130);
	set("coor/y",-110);
	set("coor/z",50);
	set("coor/x",130);
	set("coor/y",-110);
	set("coor/z",50);
	set("coor/x",130);
	set("coor/y",-110);
	set("coor/z",50);
	set("coor/x",130);
	set("coor/y",-110);
	set("coor/z",50);
	set("coor/x",130);
	set("coor/y",-110);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}
