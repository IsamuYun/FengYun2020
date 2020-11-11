//dan.c

#include <ansi.h>
inherit ITEM;

void create()
{
 set_name(HIY "还原丹" NOR,({"hydan"}));
 set_weight(80);
 if( clonep() ) set_default_object(__FILE__);
  else 
   {
    set("long", HIC "一颗能够让你重新参与朝廷通缉任务的灵丹。\n"NOR);
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
                if (this_player()->query("m_success")>4 ) return notify_fail("你已经吃过五棵还原丹，不可以再吃了!\n");
          if (this_player()->query("m_success")<1 ) return notify_fail("你没有必要吃还原丹!\n");
 if ( arg == "hydan")
  {
   message_vision(HIC"$N小心翼翼的服下一颗还原丹，一股清香直冲面门，你又可以替朝廷出力了。\n"NOR,this_player());
   this_player()->add("combat_exp",-200000);
   this_player()->set("m_success",0);
   destruct(this_object());
   return 1;
  }
 return 0; 
}
