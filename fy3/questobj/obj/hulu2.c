// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("װ���ľƺ�«", ({ "fullhulu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("value", 10000);
            set("material", "paper");
            set("long", "һ��װ�����ַ�ζ���Ƶľƺ�«��\n");
          }

    setup();
}

