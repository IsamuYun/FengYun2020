inherit ROOM;
void create()
{
        set("short", "黑暗山洞");
        set("long", @LONG
这是一个阴森可怖而且黯淡无光的山洞，一走进来，你倒吸了一口凉气，脑中
一阵晕眩，就什么也想不起来了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"d6",
  "north" : __DIR__"d6",
  "east" : __DIR__"d7",
  "west" : __DIR__"d6",
]));
        set("outdoors", "bat");
        set("coor/x",3260);
	set("coor/y",40);
	set("coor/z",-30);
	set("no_magic",1);
        set("no_clean_up", 0);
	setup();
}

