
inherit ROOM;

void create()
{
        set("short", "天地阁");
        set("long", @LONG
这里跟外面相比，简直是天壤之别。阁内摆设装潢都有其独特之处，
一看就知出之名家之手。对面，可以清楚的看见“三清宫”的几位
小仙姑。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "eastdown" : __DIR__"baoback",
  
]));
        set("objects", ([
        __DIR__"npc/tiandi" : 1,
                        ]) );
        set("coor/x",-30);
	set("coor/y",50);
	set("coor/z",10);
	set("coor/x",-30);
	set("coor/y",50);
	set("coor/z",10);

setup();
}

