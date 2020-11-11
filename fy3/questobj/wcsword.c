#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
    set_name(HIY"ÎÞ³¾½£"NOR, ({ "wcsword" }) );
        set_weight(8000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "±ú");
            set("material", "stone");
            set("long", "Ò»°Ñ±¦½£¡£\n");
          }
        init_sword(90);
    setup();
}
