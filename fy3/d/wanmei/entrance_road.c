inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "÷��С·");
        set("long", @LONG
һ��̤����С·�������ۡ�·�ߵ�÷����һ�������С��������񺡣
���������ϣ���Щ���н�����ĺۼ������ܵ�÷֦��͸�µ���չ⣬
֦��ҡ�ڣ�����������
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/manglin/edge3",
  "east" : __DIR__"road2",
 // "south" : "/u/baimiao/taolin",
]));
        set("outdoors", "wanmei");
        set("item_desc", ([
                "����С��": "
                        ·�ߵ�Ұ������ѽ�������ɣ�����룩һ��ɣ�\n",
                "С��": "
                        ·�ߵ�Ұ������ѽ�������ɣ�����룩һ��ɣ�\n"

        ]) );
        set("coor/x",110);
	set("coor/y",-400);
	set("coor/z",30);
	setup();
}
void init()
{
add_action("do_pick","pick");
}

int do_pick()
{
	object flower;
message_vision("$N������������һ��·�ߵ�Ұ����\n",this_player());
	flower = new(__DIR__"obj/flower");
	flower->move(this_player());
return 1;
}
