// Room: /d/oldpine/keep1.c

inherit ROOM;

void create()
{
        set("short", "����կ��Χ");
        set("long", @LONG
����̩ɽ�м���֮��������ɽ�����ƣ���ϼ��������ʯ�����֣���
�͵��֣�ʵ���������ѹ�֮��,ǧ���������������ֺú�ռɽΪ��������
�����϶��ҸͶ��𣬵�����Ҫ�ɼ�һ�ߣ������Կɼ�����ɽկģ����
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : "/d/oldpine/keep1",
  "east" : "/d/oldpine/keep2",
]));
        set("objects", ([ /* sizeof() == 1 */
  "/d/oldpine/npc/bandit_guard" : 4,
]));
        set("no_clean_up", 0);

        set("coor/x",-220);
	set("coor/y",-350);
	set("coor/z",90);
	setup();
        replace_program(ROOM);
}
