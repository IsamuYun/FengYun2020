#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"练神丹"NOR, ({ "lsdan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "丸");
            set("material", "stone");
            set("long", "功效不明的丹药\n");
          }

    setup();
}
