#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"基督启事" NOR, ({ "jdqs" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "基督徒们的宝 \n");
        }
    setup();
}
