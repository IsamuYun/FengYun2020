
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ڰ���ʪ���ڱ�����һ˿�����ս�������������һ��
ϣ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : "/u/taoguan/hole4",
  "south" : "/u/taoguan/hole",
]));
	set("coor/x",-20);
	set("coor/y",2050);
	set("coor/z",80);
	setup();
        replace_program(ROOM);
}
