//mac's jiaolou3.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","����¥");
  set("long",@LONG
�������Χǽ����Ľ�¥���ֱ�������Ϊ�����������������¥��
��һ��󱮣�������һ���֣�
[31m
				��
[37m
LONG
  );
  set("exits",([
         "south":__DIR__"jiaolou1.c",
         "east" :__DIR__"houzai.c",
               ]));
        set("objects", ([
                __DIR__"npc/gang3" : 1,
       ]) );
  set("coor/x",-500);
	set("coor/y",-340);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
