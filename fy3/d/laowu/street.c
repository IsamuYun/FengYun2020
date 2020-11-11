// Room: /d/laowu/street.c

inherit ROOM;

void create()
{
	set("short", "闹市街");
	set("long", @LONG
街道并不宽，两边有各式各样的店铺，车马行人熙熙攘攘，茶楼酒店里笑语喧哗，
看看这些人，再看看这一片水晶玻璃世界，你几乎分不出这究竟是人间，还是天上？
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
