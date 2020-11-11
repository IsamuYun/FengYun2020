// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("¹Å½£ÇÊ", ({ "jianqiao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "¸ö");
            set("material", "paper");
            set("long", "Ò»°Ñ¹Å½£µÄ½£ÇÊ¡£\n");
          }

    setup();
}

