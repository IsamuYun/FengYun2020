// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("װ���ķ���", ({ "fullhe" }) );
    set_weight(3000);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("value", 10000); 
            set("material", "paper");
            set("long", "һ��װ���ĺ�ľ���С����������װ�źö�ʳ��ѽ��\n");
          }

    setup();
}

