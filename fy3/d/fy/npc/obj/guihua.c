#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
void create()
{
        set_name("¹ð»¨¾Æ", ({ "guihua" }) );        set_weight(10);
        if( clonep() )
             set_default_object(__FILE__);
        else {
        set("long", "·¼ÏãËÄÒçµÄ¹ð»¨¾Æ¡£\n");                set("unit", "Æ¿");
                set("value", 0);
                set("max_liquid", 20);
        }
        set("liquid", ([
                "type": "alcohol",
                "name": "¹ð»¨¾Æ",                "remaining": 20,
                "drunk_apply": 5,
        ]) );
}

