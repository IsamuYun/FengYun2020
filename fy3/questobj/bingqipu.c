#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB"兵器谱"NOR, ({ "bingqipu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "记载各种兵器的一本奇书。\n");
          }

    setup();
}
