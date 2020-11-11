
inherit ROOM;
#include <room.h>
void create()
{
        set("short", "紫禁城后门");
        set("long", @LONG
月圆之夜,紫禁之颠！这里的里面就是西门吹雪和叶孤城决战的地方！
可是只有被邀请的人才能进入观看！
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
                        return notify_fail(ob->name()+"喝到:没有得到邀请的是闲杂人等,不得进城！\n");
	}
        return 1;
}

