//dan.c

#include <ansi.h>
inherit ITEM;

void create()
{
 set_name(HIC "叛师丹" NOR,({"panshidan"}));
 set_weight(80);
 if( clonep() ) set_default_object(__FILE__);
  else 
   {
    set("long", HIC "一颗能够忘记现在师门所有事情的灵丹。\n"NOR);
    set("unit","颗");
        set("value", 50000000);
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
          if (this_player()->query("eatdans")>4 ) return notify_fail("你已经吃过五棵叛师丹，不可以再吃了!\n");
          if (this_player()->query("combat_exp")<3500000 ) return notify_fail("你经验不到3500000，不能吃叛师丹!\n");
          if (this_player()->query("betrayer")<1 ) return notify_fail("你已经没有叛师记录了，不要浪费!\n");
 if ( arg == "panshidan")
  {
   message_vision(HIC"$N小心翼翼的服下一颗叛师丹，一股清香直冲面门，现在师门所有事情仿佛都成了过去。\n"NOR,this_player());
   this_player()->add("betrayer",-1);
   this_player()->add("combat_exp",-2000000);
   this_player()->add("eatdans",1);
   destruct(this_object());
   return 1;
  }
 return 0; 
}
