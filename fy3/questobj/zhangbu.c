#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLK"�ʲ�"NOR, ({ "zhangbu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "ӥ���̺ŵ��ʲ�\n");
          }

    setup();
}
