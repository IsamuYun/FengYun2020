#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIG"新手铠甲"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "新手套装之一，欢乐甲是新手必备的东西，可以有效地帮助新手成长。\n");
                set("material", "steel");
               set("no_get",1);
				set("limited_lv",1);
				set("abradability",500);
                set("armor_prop/armor", 50);
        }
        setup();
}

int query_autoload() { return 1; }

