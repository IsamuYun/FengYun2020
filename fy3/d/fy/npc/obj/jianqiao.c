// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("�Ž���", ({ "jianqiao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ�ѹŽ��Ľ��ʡ�\n");
          }

    setup();
}

