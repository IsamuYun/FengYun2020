inherit ROOM;
void create()
{
        set("short", "风云邮局");
        set("long", @LONG
这里是风云驿站后堂，所有的信笺都放在这里，一个邮差正忙着，
分发书信，最近丝路风云的书信数量增多，这里人手明显不够。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"mailst",
]));
        set("objects", ([
        __DIR__"npc/youchai" : 1,
                        ]) );

        set("coor/x",-20);
        set("coor/y",20);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}

