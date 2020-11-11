//mac's houqing.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>
void create()
{
  set("short","���޹�");
  set("long",@LONG
�����ڷ����ۺ͵ۺ����񣬸�һ�ɣ�����Ů�������ң�����
����������̫������ƽ̨�������κ����α���һ�飬��ʾ����ͬ��
֮�⡣�ܶ��ϵ���ͽ�������Ĥ�ݣ������飩��
LONG
  );
  set("exits",([
         "north":__DIR__"tongting.c",
         "south":__DIR__"tiankuang.c",
         "east" :__DIR__"peiqing1.c",
         "west" :__DIR__"peiqing2.c",
               ]));
        set("item_desc", ([
                "�������": "
������۸����ߣ���ò������֣���������һ�㡣\n",
        ]) );
	set("no_magic",1);
	set("NONPC",1);

  set("coor/x",-490);
	set("coor/y",-360);
	set("coor/z",0);
	setup();
}

void init()
{
add_action("do_mobai", "mobai");
}

int do_mobai()
{
       object who;
       who = this_player();
        if((int) who->query("sen") <=50)
        return notify_fail("����񲻹���\n");
       message_vision("$N�ϵع��ڶ����������ǰ���˸�ͷ��\n" ,who);
       who->receive_damage("sen",50);
       if( (int)who->query("bellicosity") > 0)
           who->add("bellicosity", - (random((int)who->query("kar")) + 7 ) );
       message_vision("$N���ϵ�ɱ��֮���ƺ����ˡ� \n" , who);
	add("number",1);
        if((int) query("number") == random(20) + 20 )
	{
	message_vision( HIR "\n\n$N������ǰһ������������ƺ�����һ�£�������\n\n" NOR,who);
	if ( !objectp(who = present("master dadi", this_object())) )
		{
		who = new(__DIR__"npc/dadi");
		who->move(this_object());
		}
	}	
	return 1;
}

void reset()
{
object obj;
:: reset();
delete("number");
if(objectp(obj = present("master dadi", this_object())) )
destruct(obj);
}
