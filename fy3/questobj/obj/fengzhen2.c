// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("ϵ�����ߵĻ�����" , ({ "fixfengzhen" }) );
    set_weight(1000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("value", 10000);
            set("material", "paper");
            set("long", "һ��С���ݡ��Ѿ�ϵ��ϸ���ߣ�����з�������һ����ɵúܸߡ�\n");
          }

    setup();
}

