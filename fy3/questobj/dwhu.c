#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB"������" NOR, ({ "dwhu" }) );
    set_weight(10);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "iron");
            set("long", "һ�鴿��ı��\n");
          }
    setup();
}
