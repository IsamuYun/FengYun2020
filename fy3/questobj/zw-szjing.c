#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIM"三字内经"NOR, ({ "zw-szjing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "cloth");
            set("long", "一本字迹清楚的经书\n");
          }

    setup();
}
