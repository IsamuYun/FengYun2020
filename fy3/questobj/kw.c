#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"���˺ڰ���"NOR, ({ "krhb" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "���˰�����죬�������������\n");
          }

    setup();
}
