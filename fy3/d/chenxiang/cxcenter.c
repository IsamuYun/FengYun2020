// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "����������");
        set("long", @LONG
��������ǳ���������Ĺ㳡�ˣ��㳡�ı�����һ��С������������
�Ա���һ�����ʯ���͵���������ϰ���С��ͷ�����ϲ�������Ϊ����֮
�磬����һ��С�������Ҳ�Գ���ͬһ������֡�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cx4",
  "south" : __DIR__"cxs1",
  "east" : __DIR__"cxe1",
	  "west":__DIR__"nanbank",
]));
        set("objects", ([
        __DIR__"npc/fishseller": 1,
	__DIR__"npc/fishbuyer": 1,
	__DIR__"npc/ditou" : 2,
		__DIR__"npc/pettrainer2" : 1,
                        ]) );
        set("outdoors", "chenxiang");
        set("coor/x",-500);
	set("coor/y",-500);
	set("coor/z",0);
	set("coor/x",-500);
	set("coor/y",-500);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
