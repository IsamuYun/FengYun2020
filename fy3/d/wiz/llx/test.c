inherit ROOM;
void create()
{
        set("short", "测试空间");
        set("long", @LONG
这里是巫师用来测试物品的房间，周围焕发着金属的光泽，屋里没有灯，但是却很亮。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "east" :"/d/fy/yitea",
        "north" : "/d/dali/chazhuang",
        "up" : __DIR__"workroom",
]));
        set("coor/x",10);
set("coor/y",-30);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}
