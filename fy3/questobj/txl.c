#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLK"天下交友令"NOR, ({ "txjy" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "块");
            set("material", "stone");
            set("long", "广结天下好友，唐门唐朋的随身之物。\n");
          }

    setup();
}
