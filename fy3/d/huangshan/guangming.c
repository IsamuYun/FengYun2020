// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "光明顶");
        set("long", @LONG
光明顶是第二高峰，因为多次出现佛光，所以被称为光明顶，光
明顶上起伏平缓，面积广大，古人曾形容它“形若覆巢，旁无依附，
秋水银河，长空一色”。这里是看日出，观云海的最佳场所，如果机
缘巧合，还可以看见难得一遇的佛光。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"feilai",
  "eastup" : __DIR__"lianhua",
]));
        set("objects", ([
        __DIR__"npc/monk" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-600);
	set("coor/y",-520);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
