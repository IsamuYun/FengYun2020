inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY "算盘珠" NOR, ({ "sppearl"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "一只金黄色的算盘珠。\n");
                set("value", 1);
        }
}