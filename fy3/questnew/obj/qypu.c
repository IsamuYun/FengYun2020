#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"风云群英谱"NOR, ({ "qypu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "风云群英谱:
引言部分写到：

风云集天下，

     何处无英雄。\n");
          }

    setup();
}