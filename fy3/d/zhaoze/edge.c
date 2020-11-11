// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit ROOM;
void create()
{
        set("short", "�����Ե");
        set("long", @LONG
���������ܲ�����ɫ����������ǰ�߾�������������������
�������������ﲻ�������ܲ������޳�û������������������
��һ˲����ʱ����Ķ���Ȫ��
LONG
        );
        set("exits", ([ 
  "north" : "/d/manglin/edge4",
// "east" : "/d/zhaoze/wenquan",
//  "west" : "/d/zhaoze/garden",
 
]));

        set("item_desc", ([
                "bush": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n",
                "����": "���ﾣ��(bush)�ܲ��������ƺ����Կ���(chop)���ǡ�\n"

        ]) );

        set("outdoors", "zhaoze");
        set("coor/x",10);
	set("coor/y",-610);
	set("coor/z",-20);
	setup();
}
void init()
{
        add_action("do_cut", "chop");
        add_action("do_kan", "kan");
	load_object(__DIR__"center");
}
int do_cut(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ����ʲô��\n");
                return 1;
        }
        if( arg == "bush" || arg == "����" )
	{
	me = this_player();
	obj = me->query_temp("weapon");
	if( !obj ) 
	{
	write("������֣���ô����\n");
	return 1;
	}
	if( obj->query("jungle"))
	{
	if( !query("exits/south") ) {
        set("exits/south", __DIR__"zhaoze1");
	message_vision(sprintf("$N�����е�%s����һ�����ϵ�·��\n",obj->name()),
		me);
	}
	else
        message_vision(sprintf("$N�����е�%s����·�ߵľ�����\n",obj->name()),
                me);
        }
        else
        message_vision(sprintf("$N�����е�%s������ľ���һ���ҿ���\n",obj->name()),
		me);
	}
	else
	 write("��Ҫ����ʲô��\n");
                return 1;
}
int do_kan(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("��Ҫ����ʲô��\n");
                return 1;
        }
        if( arg == "bush" || arg == "����" )
	{
	me = this_player();
	obj = me->query_temp("weapon");
	if( !obj ) 
	{
	write("������֣���ô����\n");
	return 1;
	}
	if( obj->query("xuantie"))
	{
	if( !query("exits/east") ) {
        set("exits/east", __DIR__"garden");
	message_vision(sprintf("$N�����е�%s����һ���򶫵�·��\n",obj->name()),
		me);
	}
	else
        message_vision(sprintf("$N�����е�%s����·�ߵľ�����\n",obj->name()),
                me);
        }
        else
        message_vision(sprintf("$N�����е�%s������ľ���һ���ҿ���\n",obj->name()),
		me);
	}
	else
	 write("��Ҫ����ʲô��\n");
                return 1;
}

void reset()
{
	::reset();
	delete("exits/south");
	delete("exits/east");
}
