
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "�Ͻ��Ǻ���");
        set("long", @LONG
��Բ֮ҹ,�Ͻ�֮�ߣ����������������Ŵ�ѩ��Ҷ�³Ǿ�ս�ĵط���
����ֻ�б�������˲��ܽ���ۿ���
LONG
        );
        set("exits", ([
                  "enter" : __DIR__"zijin",
                "out" : "/d/fy/shufang",
        ]));
        set("objects", ([
                __DIR__"zijinguard": 4,
        ]) );
        set("accept_in", 5);
        set("accept_intwo", 3);
        set("NONPC",1);
	set("no_fight",1);
	set("no_magic",1);
        set("coor/x",-30);
	set("coor/y",40);
	set("coor/z",0);
	set("coor/x",-30);
	set("coor/y",40);
	set("coor/z",0);
	setup();
}
int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
	int withtowel=0;
        if( dir == "enter" && ob=present("soldier", this_object()))
        {
                        return notify_fail(ob->name()+"�ȵ�:û�еõ�������������˵�,���ý��ǣ�\n");
	}
        return 1;
}

