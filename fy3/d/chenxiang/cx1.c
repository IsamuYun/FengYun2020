// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "�����򱱽�");
        set("long", @LONG
�ֵ��ɰ���ɫ��ʯש�̳ɡ�������Ĵ󲿷ַ��ݶ���������ʯש����
�ġ��ֵ������պÿ�����һ��������ͨ����������һ��СС����ݡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"chenxiang3",
  "southeast" : __DIR__"cx2",
  "west" : __DIR__"mian",
]));
        set("objects", ([
        __DIR__"npc/moo": 1,
                        ]) );
        set("outdoors", "chenxiang");
        set("coor/x",-510);
	set("coor/y",-460);
	set("coor/z",0);
	set("coor/x",-510);
	set("coor/y",-460);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
