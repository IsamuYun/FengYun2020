// Room: /d/oldpine/npath1.c

inherit ROOM;

void create()
{
        set("short", "�ּ�С·");
        set("long", @LONG
������������һ���ּ��С·��������Զ���߳��������Ӿ�������
�裬С·���Գ����������ʵ���������Χ�ľ��񶼰��������������
�֡�����˵����������������ǧ�����������������顣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/oldpine/npath2",
  "west" : "/d/taishan/mengxian",
]));
        set("outdoors", "oldpine");

        set("coor/x",-300);
	set("coor/y",-310);
	set("coor/z",100);
	setup();
        replace_program(ROOM);
}
