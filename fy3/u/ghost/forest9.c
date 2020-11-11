
#include <ansi.h>
inherit ROOM;

void create()
{
	object		item, con;

	set("short", "ɽ�±�");
	set("long", @LONG
ǰ����һ������׵�������Ԩ������������ƣ�ʲô����������
�������˵����鶼���������ѵ�������ɽׯ������������Ԩ֮�£�
LONG
	);
	set("exits", ([
                "west" : __DIR__"forest7",
                "south" : __DIR__"forest6",
	]));
	set("objects", ([
                __DIR__"obj/rock" : 1,
	]));
	set("outdoors", "ghost");
	set("coor/x",-1190);
	set("coor/y",-100);
	set("coor/z",-20);
	setup();
}

void init()
{
	if(this_object()->query("exits/east"))
		delete("exits/east");
}

void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        con = present("rock", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/pipe");
                item->move(con);
	}
        if(query("exits/east"))
		delete("exits/east");
}

void pipe_notify()
{
        object ob;

        message("vision", HIY "\n����֮���Ȼ������һ���ˣ�ʲô�������վ�ڰ����\n" NOR, this_object() );
        message("vision", HIY "���ߵ��±߲ŷ��֣������������ֵܴĸ�������������Ե�ɽ�¡�\n" NOR, this_object() );
        set("exits/east", __DIR__"bridge" );
}

