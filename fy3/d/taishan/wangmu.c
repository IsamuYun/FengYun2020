// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","王母池");
  set("long",@LONG
泰山多深潭，浅溪，王母池是深潭之佼佼者，潭水清冽，可见人影，
相传当年王母从昆仑去东海，路经此处，忍不住驻足浣洗，从此此无名
潭便留下美名。后世者更刻意经营，植树引水，王母潭之美渐为泰山群
潭之最。
LONG
  );
  set("exits",([
	"westup" : __DIR__"hongmen",
	"eastup" : __DIR__"pingfeng",
	"east" : __DIR__"hushan",
               ]));
        set("objects", ([
        __DIR__"npc/liu1" : 1,
	__DIR__"npc/liu2" : 1,
	__DIR__"obj/lake" : 1,
                        ]) );
        set("outdoors", "fengyun");
	set("coor/x",-480);
	set("coor/y",-320);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
