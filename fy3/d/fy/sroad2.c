// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;
void create()
{
        set("short", "Сɽ�¶�");
        set("long", @LONG
ɽ���䲻�ߣ���Ҳ���԰�����������ͱ���ķ��ƳǾ����۵ס�ռ
�ؼ�����ķ��Ƴ�һ���������߼ʣ������Ƕ���Զ����չ�����ڴ�صĽ�
�紦���������������֮�����Եû�Į�Ŀ�����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
//"eastup" : "/u/pal/upway",
  "westdown" : __DIR__"sroad1",
]));
        set("objects", ([
        __DIR__"npc/shiren": 1,
                        ]) );
        set("outdoors", "fengyun");
        set("coor/x",20);
	set("coor/y",-430);
	set("coor/z",20);
	set("coor/x",20);
	set("coor/y",-430);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}