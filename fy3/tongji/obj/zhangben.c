#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("�ʱ�"NOR, ({ "zhangben" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
                set("no_get",1);
                set("no_drop",1);
            set("long", "һ���ʲ�\n");
          }

    setup();
}
