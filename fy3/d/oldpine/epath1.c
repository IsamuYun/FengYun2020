// Room: /d/oldpine/epath1.c

inherit ROOM;

void create()
{
        set("short", "�ּ�С·");
        set("long", @LONG
������������һ���������е�С·����������������϶�����һЩ
��ֵļǺţ����Ǳ����õ��ӻ�����С·��������һ��յأ�������Զ
���Կ���һ��ɽ������������һ��Сʯ�š�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/oldpine/clearing",
  "east" : "/d/oldpine/epath2",
]));
        set("outdoors", "oldpine");

        set("coor/x",-270);
	set("coor/y",-330);
	set("coor/z",100);
	setup();
        replace_program(ROOM);
}
