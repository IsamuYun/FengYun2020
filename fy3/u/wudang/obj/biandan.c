
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("�ⵣ", ({ "biandan" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����ɳ��ıⵣ��\n");
		set("value", 200);
		set("material", "wood");
		set("rigidity", 10);
		set("wield_msg", "$N�ó�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n���¡�\n");
	}
	init_staff(11);
	setup();
}
