
#include <weapon.h>

inherit HAMMER;

void create()
{
	set_name("��ͷ", ({ "chutou" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ͷ��\n");
		set("value", 600);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N������γ�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	init_hammer(40);
	setup();
}
