
inherit ROOM;

void create()
{
	set("short", "����ɽׯ");
	set("long", @LONG
����һ�����˵����硣����������һƬ���ɣ�ʲô������������
����һ��Ұ�ɫ��Сľ�ݣ����������İ����һ��Ҫ��ע��ſ�
�õ���
LONG
	);
	set("exits", ([
                "north" : __DIR__"house",
                "west" : __DIR__"bridge",
                "east" : __DIR__"groad1",
	]));
	set("coor/x",-1170);
	set("coor/y",-100);
	set("coor/z",-20);
	setup();
        replace_program(ROOM);
}
