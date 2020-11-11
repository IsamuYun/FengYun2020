inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "�����");
        set("long", @LONG
һյ�谵���͵��ڳ¾ɵ���̨�Ϸ��������Ĺ⡣���»��м����뽹��
�ɲ񣬻�����ȼ���š����Ϲ��ڵ�ɽ��Ұ�����������˵���ζ��˿˿����
�ӹ��ڵķ���Ʈ�������˴������Ρ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"backyard",
]));
        set("resource/water",1);
        set("coor/x",190);
	set("coor/y",-390);
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
                                "name": "ɽ��Ұ����",
                                "remaining": 15,
                                "drunk_apply": 6,
                        ]) );
                        write("������Ϲ�����װ����ɽ��Ұ������ \n");
                        return 1;
                   }
                }
                if (can_fillwater ==0) {
                        write("��û��װ���Ķ�����....\n");
                        return 1;
                }
        }
        else {
                write("��Ҫ��ʲô�����������");
        }
        return 1;
}
