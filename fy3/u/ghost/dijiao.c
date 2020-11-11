
inherit ROOM;

void create()
{
	set("short", "地窖");
	set("long", @LONG
地窖里寒冷而潮湿，泥土的墙壁上挂着一盏油灯。昏暗的灯光下，
这里更显得阴森可怖。地窖中有一把椅子，椅子上端端正正的坐着一
个人。
LONG
	);
	set("exits", ([
                "down" : __DIR__"dijiao2",
	]));
	set("objects", ([
                __DIR__"npc/biaoge" : 1,
	]));
	set("coor/x",-1120);
	set("coor/y",-120);
	set("coor/z",-20);
	setup();
	replace_program(ROOM);
}
