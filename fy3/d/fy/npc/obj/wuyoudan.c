//wuyoudan.c

#include <ansi.h>
inherit ITEM;

void create()
{
 set_name(HIC "无忧丹" NOR,({"wuyoudan"}));
 set_weight(80);
 if( clonep() ) set_default_object(__FILE__);
  else 
   {
    set("long", HIC "一颗能够忘记所有江湖恩怨的灵丹。\n"NOR);
    set("unit","颗");
    set("value", 5000000);
   }
}

void init()
{
 add_action("eat_guo","eat");
}

int eat_guo(string arg)
{
 if ( arg == "wuyoudan")
  {
   message_vision(HIC"$N小心翼翼的服下一颗无忧丹，一股清香直冲面门，所有江湖恩怨都烟消云散了。\n"NOR,this_player());
   this_player()->delete("vendetta");
   destruct(this_object());
   return 1;
  }
 return 0; 
}

