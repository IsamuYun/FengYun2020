// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("装满的饭盒", ({ "fullhe" }) );
    set_weight(3000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("value", 10000); 
            set("material", "paper");
            set("long", "一个装满的红木饭盒。里面沉甸甸地装着好多食物呀！\n");
          }

    setup();
}

