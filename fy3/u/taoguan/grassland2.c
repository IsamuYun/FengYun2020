
inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
���ϳ��Ÿ�ʽ�����Ļ��ݣ������������ﶼ���Ѽ�������
��ҩ�ݣ����������û��Ҫһ�������������Ƕ��͵�ɽ�£���
����һ�������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "east" : "/u/taoguan/lake2",
  "north" : "/u/taoguan/taoguan",
  "south" : "/u/taoguan/grassland1",
]));
	set("outdoors", "taoguan");
	set("coor/x",-20);
	set("coor/y",2080);
	set("coor/z",80);
	setup();
        replace_program(ROOM);
}
