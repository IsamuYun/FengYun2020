#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB"盗王虎" NOR, ({ "dwhu" }) );
    set_weight(10);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "iron");
            set("long", "一块纯金的宝物。\n");
          }
    setup();
}
