#include <armor.h>

inherit ITEM;
#include <ansi.h>
void create()
{
        string *order=({HIY"极品茶花" NOR, YEL"一品茶花" NOR,
HIW"二品茶花" NOR,HIG"三品茶花" NOR,GRN"一般茶花" NOR});
        set_name((order[random(5)]), ({ "tea flower","flower"}) );
        set_weight(500000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "盆");
        }
        setup();
}
