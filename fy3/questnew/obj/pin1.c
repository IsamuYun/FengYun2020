#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name("完整的" + HIR "觇" +  HIG"玉" + HIC"发簪" NOR, ({ "goodpin"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个翠绿欲滴的玉发簪,两颗光彩夺目的宝石镶嵌在上面。\n");
                set("unit", "个");
                set("value", 200000);
                set("armor_prop/armor", 0);
                set("armor_prop/personality", 3);
                set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
                set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");


        }
        setup();
}