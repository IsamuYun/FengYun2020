#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(YEL"���нֲ�Ʊ" NOR, ({ "chapiao" }));
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ�Ÿ�����֮��ũ��Ĳ�Ʊ��\n");
          }

    setup();
}
