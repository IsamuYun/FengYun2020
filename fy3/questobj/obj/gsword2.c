#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( "���ʵ��з�����", ({ "gswords" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ѵ���������͵��з�������\n");
		set("material", "steel");
                set("value", 10000); 
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n����Ž��ʡ�\n");
	}
	init_sword(45);
	setup();
}
