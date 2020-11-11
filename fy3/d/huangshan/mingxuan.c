// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "鸣弦泉");
        set("long", @LONG
泉水自高山石壁骤然落下，冲击一块横卧山麓，左厚右薄中空，
状如古琴的岩石，发出悦耳而有节奏的音响而得名。所以古诗赞道
“却按工商仔细听，二十五弦俱不在”。
LONG
        );
        set("exits", ([ 
  "east"	: __DIR__"sandie",
]));
        set("objects", ([
        __DIR__"obj/stone3" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-570);
	set("coor/y",-520);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
