#include <globals.h>
inherit ROOM;
void create()
{
        set("short", "喀拉乌成山");
        set("long", @LONG
天山支脉喀拉乌成山常年冰雪封山，除了当地人之外没有几个
人愿意冒险从这里入天山，去寻找传说中的天山雪莲。相传百年来
只有一个人活着从天山中走了出来，找到了武林奇宝－－天山雪莲。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"bingchuan",
  "northeast" : __DIR__"tianshan",
  "southwest" : __DIR__"tianshan",
]));
	set("no_pk",1);
	set("no_spells",1);
	set("no_magic",1);
        set("outdoors", "xinjiang");
        set("coor/x",-1130);
	set("coor/y",1000);
	set("coor/z",0);
	setup();
}
