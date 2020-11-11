inherit ROOM;
void create()
{
        set("short", "红屋二楼");
        set("long", @LONG
楼内让人感觉阴森恐怖，无窗无灯，几乎不可见物，令人毛骨悚然。
这里仿佛通往另外一个世界，幽冥鬼界。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	"down" : __DIR__"futhur",
]));
        set("objects", ([
        __DIR__"npc/laowushi" : 1,
                        ]) );

        set("coor/x",-30);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
