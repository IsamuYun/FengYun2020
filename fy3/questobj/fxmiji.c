#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"飞仙秘籍" NOR, ({ "fxmiji" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "这是一本叶孤城身上的小册字，上面密密麻麻写满了文字和图形。可惜你怎么也看不懂。\n");
          }
    setup();
}
