// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <room.h>
void create()
{
  set("short","ؤ��˽��");
  set("long",@LONG
������ؤ���˽��������ǽ�Ϲҵ���һ������Ļ��һ���Ϻ��
��������һ������ͼ���ݳƶ�����Ʒ�����˾��Ѿ���ֵ���ǡ�����
��˵�ⷿ��İ����ˡ�
LONG
  );
  set("exits",([
         "south":__DIR__"shungeng",
               ]));
        set("objects", ([
                __DIR__"npc/master5" : 1,
       ]) );
  	set("coor/x",20);
	set("coor/y",2200);
	set("coor/z",0);
	setup();
        create_door("south", "�ϵ���", "north", DOOR_CLOSED);

}
