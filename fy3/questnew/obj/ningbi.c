#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name( HIG "凝碧宝石" NOR, ({ "ningbi" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块碧如秋水的奇特宝石。\n");
                set("value", 40000);
                set("material", "stone");
                set("rigidity", 20000);
        }
//      init_sword(5);
        setup();
}