// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
��������ɽȪ�㼯���ɡ�Ȫˮ�峺���ף�������ɰ���ͷ������
���������������������ˮ���������ڵ��Σ����˶������⣬������
���������ɼ������˻�ȷ�м��ֵ���
LONG
  );
  set("exits",([
         "east" :__DIR__"jinggang.c",
         "north":__DIR__"changlang.c",
               ]));
        set("outdoors", "qianfo");
        set("resource/water",1);
	set("liquid/name","ɽȪˮ");
	set("liquid/type", "water");
	set("liquid/drunk_apply",0);
        set("objects", ([
                __DIR__"npc/lady" : 1,
		__DIR__"npc/badguy":1,
       ]) );

        set("coor/x",40);
	set("coor/y",2020);
	set("coor/z",30);
	setup();
}

void init()
{
        add_action("do_fillwater", "fillwater");
}

int do_fillwater(string arg)
{
        object *list, ob;
        int i, can_fillwater;
        string dir;

        if( !arg || arg=="" ) return 0;

        if( arg=="skin" || arg=="wineskin" ) {
                list = all_inventory(this_player());
                i = sizeof(list);
                can_fillwater = 0;
                while (i--) {
                  if (((string)list[i]->query("liquid/type") == "alcohol")
 || ((string)list[i]->query("liquid/type") == "water")         ) {
                        ob = list[i];
                        can_fillwater = 1;
                        ob->set("liquid", ([
                                "type": "water",
                                "name": "ɽȪˮ",
                                "remaining": 15,
                                "drunk_apply": 0,
                        ]) );
                        write("��ӷ�������װ����ɽȪˮ�� \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("��û��װˮ�Ķ�����....\n");
                        return 1;
                }
        }
        else {
                write("��Ҫ��ʲô�������ˮ��\n");
        }
        return 1;
}

