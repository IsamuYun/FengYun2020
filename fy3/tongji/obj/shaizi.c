#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("÷½×Ó", ({ "guzi" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",     "Ò»¿Å¾§äÞÌÞÍ¸µÄÏóÑÀ÷»×Ó\n");
                set("unit", "¶Ñ");
                set("no_get",1);
                set("no_drop",1);
                set("value", 100);
                set("base_unit", "Á£");
                set("base_weight", 1);
                set("base_value", 1);
        }
        set_amount(888);
        init_throwing(50);
        setup();
}

