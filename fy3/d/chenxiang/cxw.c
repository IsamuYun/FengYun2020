// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
set("short","����������");
        set("long", @LONG
�����ǳ���������֣���������˳�����������ߵ��봨ɽ·�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
"east":__DIR__"cxcenter",
"west":"/d/sichuan/shanlu1.c",
]));
        set("outdoors", "chenxiang");
set("coor/x",-510);
	set("coor/y",-500);
	set("coor/z",0);
	set("coor/x",-510);
	set("coor/y",-500);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
