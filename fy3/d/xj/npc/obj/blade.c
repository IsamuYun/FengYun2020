#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( BLK"漆黑的刀"NOR, ({ "black blade", "blade"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value",10000);
                set("unit", "把");
                set("long", "这是一把漆黑的刀，据说从来没有别的人见过它的形状！");
		set("rigidity", 2000);
                set("material", "steel");
        }
        init_blade(100);
        setup();
}
