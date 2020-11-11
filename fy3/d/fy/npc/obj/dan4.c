//dan.c

#include <ansi.h>
inherit ITEM;

void create()
{
set_name(HIC "消判丹" NOR,({"xiaopandan"}));
 set_weight(80);
 if( clonep() ) set_default_object(__FILE__);
  else 
   {
    set("long", HIC "一颗能够忘记现在师门所有事情的灵丹,是给吃过5次判师丹的人用的,
  使用后会减掉你的4m的经验,一人一生只能吃2次,慎用。\n"NOR);
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
          if (this_player()->query("eatxpd")>2 ) return notify_fail("你已经吃过2颗
消叛丹，不可以再吃了!\n");
  if (this_player()->query("eatwqd")>1 ) return notify_fail("你已经吃过忘情丹，再吃这个可能有生命危险!\n");
  if (this_player()->query("combat_exp")<8000000 ) return notify_fail("你经验不到8000000，不能吃消叛丹!\n");
          if (this_player()->query("betrayer")<1 ) return notify_fail("你已经没有叛师记录了，不要浪费!\n");
  if ( arg == "xiaopandan")
  {
   message_vision(HIC"$N小心翼翼的服下一颗叛师丹，一股清香直冲面门，现在师门所有事情仿佛都成了过去。\n"NOR,this_player());
   this_player()->add("betrayer",-1);
     this_player()->add("combat_exp",-4000000);
     this_player()->add("eatxpd",1);
   destruct(this_object());
   return 1;
  }
 return 0; 
}
