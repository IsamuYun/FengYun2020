// golden_armor.c

#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("ʥ��", ({ "god armor", "armor" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "gold");
                set("value", 10000);
        set("no_get",1);
        set("no_drop",1);
                set("armor_prop/spirituality",5);
                set("armor_prop/armor", 75);
        }
        setup();
}
