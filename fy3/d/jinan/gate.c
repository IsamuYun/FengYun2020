// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","���ϳǿ�");
  set("long",@LONG
������Ǽ��ϳǵ���ڣ�Ҳ����ؤ�����ɰ��ĵ����ˡ�
һ�����ϳǱ�����ɰ��Ķĳ������á�
LONG
  );
  set("exits",([
         "north"  :"/d/qianfo/tanghuai.c",
	 "south" : __DIR__"casino1",
               ]));
        set("outdoors", "jinan");
  	set("coor/x",30);
	set("coor/y",1990);
	set("coor/z",1);
	setup();
        replace_program(ROOM);

}

