#include <weapon.h>

inherit SWORD;
void create()
{
        set_name("���̽�", ({ "ningsword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	               set("material", "iron");
 set("long", "һ����÷��ʦ������Ľ���\n");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unequip_msg", "$N�����е�$n������ڡ�\n");
        }
        init_sword(75);
        setup();
}

