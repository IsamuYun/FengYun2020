#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW "�����ϻ�" NOR, ({ "tigers" }) );
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "ֻ");
            set("material", "stone");
            set("value", 40000);
	    set("rigidity", 20000);
            set("long", "һֻ��Ө��͸�İ����ϻ�,���������Ĺ�â��
                                  \n");
          }

    setup();
}
