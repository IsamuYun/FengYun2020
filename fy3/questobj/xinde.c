// TIE@FY3
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"主持心得"NOR,({ "xinde" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("material", "paper");
                set("long", "这是一本记载葛伦多年来做主持的心得。\n");
        }
}
