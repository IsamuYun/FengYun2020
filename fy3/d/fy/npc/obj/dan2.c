//dan.c

#include <ansi.h>
inherit ITEM;

void create()
{
 set_name(HIG "忘情丹" NOR,({"wangqingdan"}));
 set_weight(80);
 if( clonep() ) set_default_object(__FILE__);
  else 
   {
    set("long", HIC "一颗能够忘记现在师门所有事情的灵丹。\n"NOR);
    set("unit","颗");
        set("value", 100000000);
   }
}

void init()
{
 add_action("eat_guo","eat");
}

int eat_guo(string arg)
{
         object me;
        me = this_player();
                if (this_player()->query("eatdans")>0 ) return notify_fail("你已经吃过叛师丹，再吃这个可能有生命危险!\n");
 if (this_player()->query("eatwqd")>1 ) return notify_fail("你已经吃过消判丹，再吃这个可能有生命危险!\n");

          if (this_player()->query("betrayer")<1 ) return notify_fail("你已经没有叛师记录了，不要浪费!\n");
 if ( arg == "wangqingdan")
  {
   message_vision(HIC"$N服下一颗忘情丹,现在师门所有事情仿佛都成了过去。\n"NOR,this_player());
   this_player()->delete("betrayer");
   this_player()->add("eatdans",5);
   this_player()->add("eatwqd",1);
   destruct(this_object());
   return 1;
  }
 return 0; 
}
