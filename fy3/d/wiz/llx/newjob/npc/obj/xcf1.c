inherit ITEM;
#include <ansi.h>
void create()
{
        string *order=({HIY"信阳毛尖" NOR, YEL"三炮台" NOR,
HIW"乌龙茶" NOR,HIG"西湖龙井" NOR,GRN"铁观音" NOR,GRN"碧螺春" NOR});
        set_name((order[random(6)]), ({"xincha"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "包");set("unit", "包");
                set("material", "wood");
                set("long", "一大包给大理品茶居士的新茶。\n");
        }
        setup();
}
