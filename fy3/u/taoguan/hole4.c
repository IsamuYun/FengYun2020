
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ����С��ɽ�ȣ����ɽ��������Ψһ�ĳ��ڡ�ɽ��
�����ﻨ�㣬����������Դ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/u/taoguan/grassland1",
  "south" : "/u/taoguan/hole3",
]));
	set("outdoors", "taoguan");
	set("coor/x",-20);
	set("coor/y",2060);
	set("coor/z",80);
	setup();
        replace_program(ROOM);
}
