
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ��ɽ�꣬���Ͼ��Ƿ��Ƴǣ�һ�����ѵ�С������չ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : "/u/taoguan/road1",
  "eastdown" : "/d/laowu/road1",
]));
	set("outdoors", "taoguan");
	set("coor/x",-10);
	set("coor/y",2000);
	set("coor/z",10);
	setup();
	replace_program(ROOM);
}
