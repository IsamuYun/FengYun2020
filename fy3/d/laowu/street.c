// Room: /d/laowu/street.c

inherit ROOM;

void create()
{
	set("short", "���н�");
	set("long", @LONG
�ֵ������������и�ʽ�����ĵ��̣���������������������¥�Ƶ���Ц��������
������Щ�ˣ��ٿ�����һƬˮ���������磬�㼸���ֲ����⾿�����˼䣬�������ϣ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "laowu");
	set("exits", ([ /* sizeof() == 3 */
  //"north" : "/d/quanli/road",
  "west" : __DIR__"downtown",
  "east" : __DIR__"street1",
]));
        set("objects", ([
        "/d/wiz/llx/newjob/npc/farmer2" : 1,
                        ]) );
	set("coor", ([ /* sizeof() == 3 */
  "z" : 0,
  "y" : 12050,
  "x" : 0,
]));

	setup();
	replace_program(ROOM);
}
