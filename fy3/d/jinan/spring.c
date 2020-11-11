// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","���������");
  set("long",@LONG

      ;,  ,
   ''';;''''
   '';;''''',
 ''';;''';''''
  ,;;,,,,,;;,,
,'' ;;,,,;; ';'
    ;;   ;;
    ;'''';'

LONG
  );
  set("exits",([
	 "northeast" : __DIR__"casino1",
	 "south" : __DIR__"fall",
               ]));
        set("objects", ([
                __DIR__"npc/chunhua" : 1,
       ]) );
  	set("coor/x",20);
	set("coor/y",1970);
	set("coor/z",1);
        set("no_fight",1);
        set("no_magic",1);
        set("no_cast",1);
        set("NONPC",1);
        set("no_spells",1);
        setup();

}
int valid_leave(object me, string dir)
{
        object dealer, pl;
        string *locs = ({"north","south","east","west"});
        int m;
        dealer = present("chun hua",this_object());
        for(m=0;m<sizeof(locs);m++)
        if(objectp(pl=dealer->query(locs[m]+"/player")) && pl == me)
        return notify_fail("�ľ����ڽ����У���������߶���\n");
        return 1;
}

