//changan city

inherit ROOM;

void create ()
{
        set ("short", "聚赌楼");

        set ("long", @LONG

聚赌楼楼上显得格外热闹，走廊里人来人往，几间屋子里人声嘈杂，牌
签骨骰钱币落盘的声音不绝。看样子，客人们赌得正欢呢。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"duchang1",
                "east" : __DIR__"duchang2",
                "south" : __DIR__"duchang4",
                "down" : "/d/yingou/dating",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
//                "/d/obj/misc/tables" : 3,
        ]));


        set("coor/x",-20);
        set("coor/y",-30);
        set("coor/z",10);
//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

