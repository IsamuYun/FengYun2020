#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"幸运星" NOR, ({ "xyx" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "paper");
            set("long", "一个小小的幸运星\n");
          }

    setup();
}
