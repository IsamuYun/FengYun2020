// Room: /d/oldpine/passage.c

inherit ROOM;

void create()
{
        set("short", "����ͨ�����");
        set("long", @LONG
��������վ��һ����ʯ��ͨ��֮�У������ϱ���һƬ����������Ļ��
����Ļ���洫�������¡¡��ˮ����ͨ�����ߵ�ʯ���ϰ��������ͭ��
����̨�������������Ѩ�������ƺ������⡣
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "��Ļ" : "��Ƭ��Ļ�ƺ�����һ�ּ�����˿��֯�ɵģ����滹��������ˮ����\n",
]));
        set("exits", ([ /* sizeof() == 2 */
  "north" : "/d/oldpine/secrectpath1",
  "south" : "/d/oldpine/waterfall",
]));
        set("objects", ([ /* sizeof() == 1 */
  "/d/oldpine/npc/maniac" : 1,
]));
        set("no_clean_up", 0);

        set("coor/x",-260);
	set("coor/y",-330);
	set("coor/z",70);
	setup();
        replace_program(ROOM);
}
