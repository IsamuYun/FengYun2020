#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"киеф"NOR, ({ "songpai" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "©И");
            set("material", "stone");
            set("long", "╧бкиохиЗ╣даНеф║ё\n");
          }

    setup();
}
