#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW "�����ܺ�" NOR, ({ "mihan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ���������ӡ���嶾���������ܺ���
�Ʒ���������


				������\n");
          }

    setup();
}
