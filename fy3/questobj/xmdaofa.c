#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"��ħ����"NOR, ({ "xmdaofa" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "һ�����幬�Ľ�ħ����\n");
          }

    setup();
}
