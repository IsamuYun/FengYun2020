#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB"������"NOR, ({ "bingqipu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "���ظ��ֱ�����һ�����顣\n");
          }

    setup();
}