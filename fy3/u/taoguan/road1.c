
inherit ROOM;

void create()
{
	set("short", "����ɽ");
	set("long", @LONG
������ǰ��һ����ͨ��ɽ�塣һ������ܿ�Ҳ����ܶ���ɽ��
�ӱ������������š��������ɽʯд�ţ�����ɽ���������֡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : "/u/taoguan/road2",
  "eastdown" : "/u/taoguan/sroad",
]));
	set("outdoors", "taoguan");
	set("coor/x",-20);
	set("coor/y",2000);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}
