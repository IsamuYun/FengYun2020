inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "С��");
        set("long", @LONG
һ��С����ª��ľ�ݣ�������©�ꡣǽ������ض���һ����
�ɲ�ǽ�϶���һ��ľ�ܣ����Ϲ���һЩ�����õĹ��ߡ�һ����
�ʷ����������롣
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"frontyard",
]));
        set("objects", ([
        __DIR__"obj/chair": 1,
	__DIR__"obj/rope" : 1,
	__DIR__"obj/drywoods" : 1,
                        ]) );

        set("coor/x",150);
	set("coor/y",-390);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
