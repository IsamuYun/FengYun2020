#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"石棋"NOR, ({ "shiqi" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "stone");
            set("long", "一个石制的棋。\n");
          }

    setup();
}
