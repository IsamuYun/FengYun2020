
inherit ROOM;

void create()
{
        set("short", "后巷");
        set("long", @LONG
这里黑黑的，什么都看不见。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"baozipu",
  
]));
        set("objects", ([
 "/d/yingou/obj/shiti": 1,
        ]) );
        set("coor/x",-20);
	set("coor/y",50);
	set("coor/z",0);
	set("coor/x",-20);
	set("coor/y",50);
	set("coor/z",0);

        setup();
}
void init()
{
        add_action("do_open", "open");
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要打开什么？\n");
                return 1;
        }
        if( arg == "picture" || arg == "条幅" || arg == "tiao")
        {
        me = this_player();
        message_vision("$N拉起墙上的条幅，发现了一个暗门。\n", me);
        if( !query("exits/westup") ) {
        set("exits/westup", __DIR__"backwest");
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("你不可以打开"+arg+"\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/westup") ) return;
        message("vision",
"条幅荡了回来，又遮住了暗门。\n",
                this_object() );
                delete("exits/westup");
}

