#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("̴��ľ��" , ({ "txmuliao" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����Ϻõ�̴��ľ�ϡ�\n");
                set("value", 50000);
                set("material", "stone");
                set("rigidity", 20000);
        }
        setup();
}