// by Tiandi 
inherit ITEM;
#include <ansi.h>
void create()
{
         set_name(HIY  "戒指类制作书之六" NOR, ({ "fingerbook","duan book" }) );
         set_weight(10000);
         if( clonep() )
         set_default_object(__FILE__);
         else{
         set("unit", "本");
         set("long", "一本记载着戒指类的锻造方法的册子。\n");
         set("value", 50000);
         set("rigidity",2000);
         set("material", "silk");
         set("mtype", "finger");
         set("for_create_armor",6);
         }
         setup();
}
