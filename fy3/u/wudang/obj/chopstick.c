
#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("�����", ({ "chopstick" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�ԳԷ��õ�����ӡ�\n");
		set("value", 20);
		set("material", "wood");
		set("rigidity", 10);
		set("wield_msg", "$N�ó�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	init_dagger(11);
	setup();
}
