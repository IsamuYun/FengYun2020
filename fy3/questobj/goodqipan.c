#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"完整的棋盘"NOR, ({ "goodqipan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "stone");
            set("long", "一个石制的完整的棋盘\n");
          }

    setup();
}
