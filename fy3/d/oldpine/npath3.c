// Room: /d/oldpine/npath3.c

inherit ROOM;

void create()
{
        set("short", "�ּ�С·");
        set("long", @LONG
������������һ���ּ��С·�ϣ�С·�����ƺ�ͨ��һ���յأ���
�ӵ��������þ����ĵģ�С·���Ե�����Ҳ�����ߵİ�С����������
��Ӫ�����������ӡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : "/d/oldpine/clearing",
  "northwest" : "/d/oldpine/npath2",
]));
        set("outdoors", "oldpine");

        set("coor/x",-290);
	set("coor/y",-330);
	set("coor/z",100);
	setup();
        replace_program(ROOM);
}
