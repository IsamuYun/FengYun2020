//jiaozi.c
#include <ansi.h>
void rling( object ob ) ;

inherit ITEM;

void init()
{
        add_action("do_enter", "enter");
}

void create()
{
        set_name(BLU "大花轿" NOR, ({"jiao zi", "jiao"}));
    set_weight(200000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
           set("no_get",1);
                set("long", "一顶奇怪的大花轿，你可以坐(enter)上去试试。\n");
}
        setup();
}

int do_enter(string arg)
{
        object ob ;
        string dir;
        if( !arg || arg != "jiao" ) 
       {
                tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
                return 1 ;
     }
         ob = this_player();
      message_vision( WHT "\n\n$N试着坐了上去........ \n\n" NOR,this_player());
    message_vision( BLU "突然一阵颠簸，起轿了～～～～。\n" NOR,this_player());
        call_out("rling", 20 , ob );
        return 1;
     }

void rling( object ob )
{
        message_vision("突然轿子停了下来。\n", ob);
        ob->move(__DIR__"door");
}
