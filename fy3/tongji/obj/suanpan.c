inherit ITEM;
#include <ansi.h>
void create()
{
    set_name("����"NOR, ({ "suanpan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
                set("no_get",1);
                set("no_drop",1);
           set("material", "gold");
            set("long", "һ�Ѵ���������̡�\n");
                set("value", 1);
        }
        setup();
}
