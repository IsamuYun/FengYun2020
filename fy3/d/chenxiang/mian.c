// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "С���");
        set("long", @LONG
��ݵ����赱Ȼ�ܼ�ª�������������������֮��Ҳ��һЩ�ܼ򵥵�
���㡣��һ�ֺ�����ľ²˺��ӣ����ǳ�θ�ر�õ��ˣ������������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cx1",
]));
        set("objects", ([
        __DIR__"npc/oldman": 1,
                        ]) );
        set("coor/x",-520);
	set("coor/y",-460);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
