// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("����", ({ "tudao" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "iron");
                set("long", "����һ��ɱ��ר�õ�������ʮ�ַ���������ģ���Ŀ���--�������̡�\n");
                set("wield_msg", "$N���һ��ճ��Ѫ�ȵ�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n������䡣\n");
        }
        init_blade(40);
        setup();
}
