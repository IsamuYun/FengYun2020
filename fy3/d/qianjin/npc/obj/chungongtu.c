#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( "春宫图" , ({ "xxx-tu" }) );
        set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "这是一本绘制非常精美的彩色春宫图，画的好象是金瓶梅。\n");
                set("value", 1);
                set("material", "paper");
             }
        setup();
}

