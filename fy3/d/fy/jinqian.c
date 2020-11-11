inherit ROOM;
void create()
{
        set("short", "金钱帮大院");
        set("long", @LONG
大院里冷冷清清，也静的出奇。院中的老树在地上拖出长长的影子。偶尔几声鸟叫，
打破死沈沈的寂静。微风吹过，树叶舞动，发出“沙沙”的声音。黄沙的地面铺满枯黄
的落叶。几条黄色的人影在阴暗的角落里忽隐忽现。
一块木匾十分若人注目，上面龙飞凤舞的写着:

                  [37;40m┏━━━━━━━━━┓[0m
                  [37;40m┃[33m   金 钱 总 坛 [37;40m   ┃[0m
                  [37;40m┗━━━━━━━━━┛[0m

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"swind2",
  "west" : __DIR__"jting",
]));
        set("outdoors", "fengyun");
        set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
