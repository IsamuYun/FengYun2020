#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIC"指环儿"NOR, ({ "xzhihuan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "stone");
            set("long", "一个完好的指环儿，精美绝伦。\n");
          }

    setup();
}