#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"ÑªÊé" NOR, ({ "xuebook" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ÕÅ");
            set("material", "paper");
          }
    setup();
}
