#include <weapon.h>
#include <ansi.h>
inherit HAMMER;
void create()
{
        set_name(HIB"毁天锤"NOR, ({ "ht-hammer" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("material", "iron");
                set("long", "这是一把蓝天锤惯用的武器，有一百五十斤重。\n");
                set("wield_msg", "$N用尽吃奶的劲把$n扛在肩上。\n");
                set("unwield_msg", "$N放下了$n累的气喘吁吁。\n");
        }
                init_hammer(100);
        setup();
}
