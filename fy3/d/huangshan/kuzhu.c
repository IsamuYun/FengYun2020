// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "苦竹溪");
        set("long", @LONG
沿途盛产苦竹，所以溪水也有淡淡的涩味，但是良药苦口，苦竹更
是入药的上品，所以来往之人依然爱饮此泉，对于解乏提神极有帮助。
更有人特地来此取竹根入药。于是便有山民在此伐竹贩卖。
LONG
        );
        set("exits", ([ 
  "southup" : __DIR__"jiulong",
]));
        set("objects", ([
                __DIR__"npc/snake" : 2,
       ]) );
        set("item_desc", ([
               "mountain": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n",
      		"山": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n",
      		"up": "山虽陡，但还有落脚之处。你似乎可以试着爬(climb)上去。\n"
]) );
        set("outdoors", "huangshan");
	set("coor/x",-540);
	set("coor/y",-480);
	set("coor/z",10);
	setup();
}
void init()
{
	add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "山" || arg == "hill" || arg == "up")
        {
        me = this_player();
        message_vision("$N慢慢地往山上爬去。\n", me);
        me->move(__DIR__"huangshan.c");
        return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}

