#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("������" +HIY"������"NOR, ({ "suanpans" }) );
    set_weight(30000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("value",40000);
            set("material", "gold");
            set("long", "һ�Ѵ�����������\n");
          }

    setup();
}