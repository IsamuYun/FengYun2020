#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("装订后的"+ HIW"无剑心法"NOR, ({ "wujianxinfas" }) );
    set_weight(500);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("value",5000);
            set("long", "一本破旧，字迹模糊的书，虽然经过你的装订，但还是···\n");
          }

    setup();
}
