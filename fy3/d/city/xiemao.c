//changan city

inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short","Ьñ��");
        set ("long", @LONG

����Ķ������൱���������̫̫С������������·������������
��˵��˾͸����ˡ����к��һ���߳߶೤�Ĺ�̨����̨��ļ�������
һƥƥ�Ĳ��Ϻͳ��¡�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"zhuque-s3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiaoliu" : 1,
		__DIR__"npc/eryi" : 1,

        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

