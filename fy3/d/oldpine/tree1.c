// Room: /d/oldpine/tree1.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
���������ʸ���һ��������������ϣ���������Ժ������������
�µ�һ�ж������������˷������ƺ��Ǹ���͵�����������ĺõط���
LONG
        );
        set("objects", ([
                "/d/oldpine/npc/spy":1 ]) );

        set("exits", ([ /* sizeof() == 2 */
  "up" : "/d/oldpine/tree2",
  "down" : "/d/oldpine/clearing",
]));

        set("coor/x",-280);
	set("coor/y",-330);
	set("coor/z",110);
	setup();
        replace_program(ROOM);
}
