// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","半山一石洞");
  set("long",@LONG
一个半人高,五尺深的洞穴。
LONG
  );
	set("coor/x",-470);
	set("coor/y",-320);
	set("coor/z",5);
	setup();
  	replace_program(ROOM);
}
