#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"降魔道法"NOR, ({ "xmdaofa" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "stone");
            set("long", "一本三清宫的降魔道法\n");
          }

    setup();
}
