// by Tiandi 
inherit ITEM;
#include <ansi.h>
void create()
{
         set_name(HIY  "拳套类制作书之七" NOR, ({ "ringbook","duan book" }) );
         set_weight(10000);
         if( clonep() )
         set_default_object(__FILE__);
         else{
         set("unit", "本");
         set("long", "一本记载着拳套类的锻造方法的册子。\n");
         set("value", 50000);
         set("rigidity",2000);
         set("material", "silk");
         set("mtype", "ring");
         set("for_create_weapon",7);
         }
         setup();
}
