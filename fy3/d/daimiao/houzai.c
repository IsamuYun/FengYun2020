//mac's houzai.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <room.h>
inherit ROOM;
void create()
{
  set("short","厚载门");
  set("long",@LONG
这是岱庙的后门，两边是高两丈的青砖围墙，此门向北便是泰山
了，东岳大帝回銮必从此门，因此称为厚载门，为满载而归的意思。
LONG
  );
  set("exits",([
         "north":"/d/taishan/daizong.c",
         "south":__DIR__"tongting.c",
         "west" :__DIR__"jiaolou3.c",
         "east" :__DIR__"jiaolou4.c",
               ]));
        set("objects", ([
                __DIR__"npc/tie" : 1,
       ]) );
	set("coor/x",-490);
	set("coor/y",-340);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
