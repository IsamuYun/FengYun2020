// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "藏经楼");
        set("long", @LONG
这里是少林的藏经楼的顶楼，传说在这里修行的长老都时常
梦见少林的祖师达摩，也在这里领悟到意想不到的武功，但是
不是每个人都有这种机缘。
LONG
        );
        set("objects", ([
                __DIR__"npc/tongre" : 3,
       ]) );
        set("exits", ([ 
  "down": __DIR__"cj6",
]));
set("no_magic",1);
        set("coor/x",-210);
	set("coor/y",360);
	set("coor/z",120);
	setup();

}
