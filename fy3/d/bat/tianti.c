#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "天梯尽头");
        set("long", @LONG
这里有两扇门，一扇（door1）通向外面，是活路；还有一扇（door2）门是死
路—门外就是看不见底的万丈探蹦，只要一脚踏下，就万劫不复了！没有人知道哪
扇门外是活路。你可以自己选择去开门，但只要一开了门，就非走出去不可。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"tianti3",
]));
        set("outdoors", "bat");
        set("coor/x",3310);
	set("coor/y",20);
	set("coor/z",20);
	set("no_magic",1);
        set("no_clean_up", 0);
        set("item_desc", ([
		"door1" : "两扇门几乎是完全一模一样的，没有人能看出其间的差别。生与死的差别。\n",
		"door2" : "两扇门几乎是完全一模一样的，没有人能看出其间的差别。生与死的差别。\n",
        ]) );
	setup();
        
}

void init()
{
        add_action("do_say", "say");
        add_action("do_open", "open");
}


int do_say(string arg)
{
        if( !arg || (arg!= "我来过，活过，爱过！" && arg!="我绝不后悔！" && arg!="I won't regret!" && arg!="我总算已想通了。" && arg!="活过爱过已足够。") )
        
                return 0;
        else
        {
        	message_vision(HIY"$N推开了门，眼前现出灿烂无比的夕阳...\n"NOR,
                        this_player() );
                this_player()->move(__DIR__"anbian1");
                return 0;
	}
}

int do_open(string arg)
{
        if( !arg || (arg!= "door1" && arg!="door2") )
                return notify_fail("你要打开什麽？\n");
        else
        {
        	message_vision(HIB"$N推开了门，失足掉入了万丈深渊，在离开这个世界的
一刹那间，你的眼前又浮现出最心爱的人的笑容...\n"NOR,
                        this_player() );
                this_player()->die();
                return 1;
	}
}