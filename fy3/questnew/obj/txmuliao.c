#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("檀香木料" , ({ "txmuliao" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一大块上好的檀香木料。\n");
                set("value", 50000);
                set("material", "stone");
                set("rigidity", 20000);
        }
        setup();
}