inherit ROOM;
void create()
{
        set("short", "天梯");
        set("long", @LONG
这是一条狭窄的甬道,宛如登天的天梯。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"tianti2",
  "up" : __DIR__"tianti",
]));
        set("outdoors", "bat");
        set("coor/x",3310);
	set("coor/y",20);
	set("coor/z",-10);
	set("no_magic",1);
        set("no_clean_up", 0);
        set("objects", ([
                __DIR__"npc/bianfu2" :1,
                        ]) );
	setup();
}

