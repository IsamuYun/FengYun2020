#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIG"风云城的天空"NOR);
        set("long", @LONG
这里是风云城中央的天空，往下望去，风云城的景象一览无遗，而这里却是凡人
的禁地。除非有贵人相助或者遇上奇遇之人，否则将永远到不了这里。
此处白云缥缈，有如仙境，实在令人不意离去。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
          "west" : __DIR__"eroad3",

        "east" : __DIR__"eroad5",
]));
			
        set("outdoors", "fyup");
        set("objects", ([
               __DIR__"npc/star4" : 1,
       ]) );
        set("no_fight",1);
        set("no_magic",1);
        set("no_beg",1);
        set("no_du",1);
        set("no_sheet",1);
        set("no_dazuo",1);
        set("coor/x",0);
	set("coor/y",0);
        set("coor/z",10);
        setup();
}
