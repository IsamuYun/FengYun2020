#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("ëˢ", ({ "shuazi" }) );
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("long", "����һ��ëˢ��\n");
        }
        setup();
}