#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIB"断掉的寒萸刀鞘"NOR, ({ "duanqiao" }) );
        set_weight(8000);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "一个用天山上千年寒萸做成的刀鞘。可惜已经被圆月弯刀砍断了.\n");
        }
}

