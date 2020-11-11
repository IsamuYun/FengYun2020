inherit ROOM;
void create()
{
        set("short", "知府书房雅阁");
        set("long", @LONG
这是钦差大人休息的地方,布置的非常雅致,正中挂一幅名人山水。供一个
古铜香炉，炉里香烟飘渺。左边设一张红木锦榻，右边架上堆满若干图书。沿
窗一只几上，摆列文房四宝。俯瞰窗外,庭中种植许多花木。
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"zt",
]));

        set("no_fight",1);
        set("no_beg",1);
        set("no_sheet",1);
        set("no_magic",1);
        set("no_dazuo",1);
        set("NONPC",1);

        set("objects", ([
           "/tongji/npc/zhuge" : 1,
                        ]) );

        set("coor/x",-19);
	set("coor/y",-10);
	set("coor/z",20);
	setup();
}
