#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL"�䵱��Ʊ" NOR, ({ "chapiao" }));
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ�Ÿ��䵱ɽ����ũ��Ĳ�Ʊ��\n");
          }

    setup();
}
