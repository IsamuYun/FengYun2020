#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIM"Ã·ÅÆ"NOR, ({ "meipai" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "¿é");
            set("material", "stone");
            set("long", "º®Ã·ÏÈÉúµÄÁîÅÆ¡£\n");
          }

    setup();
}
