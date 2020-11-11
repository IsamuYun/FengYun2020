inherit ROOM;
void create()
{
        set("short", "伏龙隐阁");
        set("long", @LONG
你惊奇的发现一个设计典雅的小木屋，木屋前面有木桌，木椅。
木桌上放着一古琴，一个鹤发老者正在漫不经心的拨弄着。
木屋上的梁上悬着一块匾额，上面龙飞凤舞的写着:


                  [37;39m┏━━━━━━━━━┓[0m
                  [37;39m┃[31m   伏 龙 隐 阁 [37;39m   ┃[0m
                  [37;39m┗━━━━━━━━━┛[0m


这里四周被藤条罩住，要是不站在树上还真难发现这里。不过要想
出去也只能分开(cut)藤条(tiao)了。
LONG
        );
        set("objects", ([
         __DIR__"npc/rmaster": 1,
          ]) );
        set("coor/x",-10);
        set("coor/y",-610);
	set("coor/z",0);
	setup();
}

void init()
{
        add_action("do_open", "cut");
}
int do_open(string arg)
{
        object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要分开什么？\n");
                return 1;
        }
        if( arg == "tiao" || arg == "藤条")
        {
        me = this_player();
        message_vision("$N向前走了两步，奋力用双手分开藤条，只听
＂刷＂地一声，藤条被分开了一个缺口。\n", me);
        if( !query("exits/east") ) {
        set("exits/east", __DIR__"edge");
        if(!me->query("m_success/伏龙隐阁"))
        {
                me->set("m_success/伏龙隐阁",1);
                me->add("score",500);

        }
        call_out("close_path", 1);
        }
        return 1;
        }
        else
        {
                write("你伸手分开了"+arg+"。\n");
                return 1;
        }
}
void close_path()
{
        if( !query("exits/east") ) return;
        message("vision",
"藤条无声无息的又合上了，挡住了发现的道路。\n",
                this_object() );
                delete("exits/east");
}

