#include <armor.h>
inherit CLOTH;
#include <ansi.h>
void create()
{
        set_name(HIY"大理玉玺锦布"NOR, ({ "yuxi-cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "一张包裹大理皇帝的玉玺的金色锦布。\n");
                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/intelligence",2);
        }
        setup();
}
