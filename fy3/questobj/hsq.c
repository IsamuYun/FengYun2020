#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLK"һ�к�ʯ��"NOR, ({ "qizi" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "һ��ʯ�Ƶ��塣\n");
          }

    setup();
}