#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"������"NOR, ({ "yingoupai" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "����ɵ�������\n");
          }

    setup();
}
