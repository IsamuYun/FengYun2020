//mac's tongting.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","ͭͤ����");
  set("long",@LONG
��ǰ��������һ�������ɵ�ͭ��ͤ�ӣ�ͤ��Ϊһʵ������������
�����������ƣ�ɽˮ��ʯ��Ԣ��������գ����������ɽ���곤����
˼��
LONG
  );
  set("exits",([
         "north":__DIR__"houzai.c",
         "south":__DIR__"houqing.c",
               ]));
        set("objects", ([
                __DIR__"npc/master" : 1,
       ]) );
  set("coor/x",-490);
	set("coor/y",-350);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
