//changan city

inherit ROOM;

void create ()
{
        set ("short", "�۶�¥");

        set ("long", @LONG

�۶�¥¥���Եø������֣����������������������������������ӣ���
ǩ����Ǯ�����̵����������������ӣ������Ƕĵ������ء�
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

