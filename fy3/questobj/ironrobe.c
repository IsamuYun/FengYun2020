#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(HIC "Ìú¼×ÅÛ"NOR, ({ "ironrobe" }) );
        set_weight(309000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "iron");
                set("armor_prop/armor", 2);
                set("armor_prop/spells", 3);
	       }
        setup();
}
