// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "������ʯ��");
        set("long", @LONG
�����ֵ���ʾ�Ž���С�����ֶ��ؽ��еķ��԰���ε�С�ź��
һ�������С���������µ���ˮ����ƼȾ�ɰ��˵Ĵ��̡�ż��һ��ֻ����
�����������źӱߵ���ź��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"cx1",
  "southwest" : __DIR__"cx3",
]));
        set("objects", ([
        __DIR__"npc/boy": 2,
                        ]) );
        set("outdoors", "chenxiang");
        set("resource/water",1);
        set("coor/x",-500);
	set("coor/y",-470);
	set("coor/z",0);
	set("coor/x",-500);
	set("coor/y",-470);
	set("coor/z",0);
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
                                "name": "��ˮ",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("��������С������װ������ˮ! \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("��û��װˮ�Ķ�����....\n");
                        return 1;
                }
        }
        else {
                write("��Ҫ��ʲô�������ˮ��");
        }
        return 1;
}

