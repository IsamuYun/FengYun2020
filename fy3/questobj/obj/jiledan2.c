#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("���ֵ���", ({ "danfen" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "Щ");
            set("material", "stone");
            set("value", 10000);
            set("long", "һЩ������ҩ���ļ��ֵ��ۡ�\n");
          }

    setup();
}

