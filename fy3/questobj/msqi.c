#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIC"������"NOR, ({ "msqi" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", "һ���ƾɵ�������\n");
          }

    setup();
}
