// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//mac's jiaolou4.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","���¥");
  set("long",@LONG
�������Χǽ����Ľ�¥���ֱ�������Ϊ�����������������¥��
��һ��󱮣�������һ���֣�
[33m
				��
[37m
LONG
  );
  set("exits",([
         "south":__DIR__"jiaolou2.c",
         "west" :__DIR__"houzai.c",
               ]));
          set("objects", ([
                __DIR__"npc/gang4" : 1,
       ]) );
  set("coor/x",-480);
	set("coor/y",-340);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
