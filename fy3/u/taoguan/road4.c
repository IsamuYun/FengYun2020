
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ����ʯ���̳ɵ�ɽ����������ï�ܵ���ľ����ǰ�����
������·�Ѿ��������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : "/u/taoguan/road5",
  "southdown" : "/u/taoguan/road3",
]));
	set("outdoors", "taoguan");
	set("coor/x",-20);
	set("coor/y",2030);
	set("coor/z",50);
	setup();
	replace_program(ROOM);
}
