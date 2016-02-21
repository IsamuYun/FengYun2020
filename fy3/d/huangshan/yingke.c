// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "迎客松");
        set("long", @LONG
从半山寺过来，一过蓬莱三岛，远远便可看见一株古松伸出“双臂”，
宛若主迎远客。松高十余米，树冠茂密，过了迎客松，标志着人们已经踏入
“万山拜其下，孤云卧此中”的文殊院了。
LONG
        );
        set("exits", ([ 
  "eastdown"  : __DIR__"guanyin",
  "southwest" : __DIR__"yuping",
  "northwest" : __DIR__"wenzhu",
]));
        set("objects", ([
        __DIR__"npc/huo" : 1,
	__DIR__"npc/du" : 1,
                        ]) );
        set("outdoors", "huangshan");
	set("coor/x",-570);
	set("coor/y",-510);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
