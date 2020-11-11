inherit ROOM;
void create()
{
        set("short", "山林");
        set("long", @LONG
山林茂密，你脚下的柔软细草恰可没足，耳边有啾啾鸟语，鼻中又嗅着花草
幽香，透过林间，隐约可见北方农家的炊烟，远远的好象有上十余只猴儿在林间
跳跃相戏，真是一片人间仙境。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "north" : __DIR__"road2",
]));

   	set("outdoors","taoyuan");
        set("coor/x",200);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
	replace_program(ROOM);

}


