// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"天山雪莲" NOR, ({ "xuelian" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "朵");
            set("material", "paper");
            set("long", "一朵天山雪莲,据传可以起死回生，是习武之人的恩物。\n");
          }

    setup();
}

