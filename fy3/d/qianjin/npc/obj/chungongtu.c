#include <ansi.h>
inherit ITEM;

void create()
{
        set_name( "����ͼ" , ({ "xxx-tu" }) );
        set_weight(70);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����Ʒǳ������Ĳ�ɫ����ͼ�����ĺ����ǽ�ƿ÷��\n");
                set("value", 1);
                set("material", "paper");
             }
        setup();
}

