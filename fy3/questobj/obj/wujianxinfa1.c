#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("װ�����"+ HIW"�޽��ķ�"NOR, ({ "wujianxinfas" }) );
    set_weight(500);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("value",5000);
            set("long", "һ���ƾɣ��ּ�ģ�����飬��Ȼ�������װ���������ǡ�����\n");
          }

    setup();
}
