
#include <weapon.h>

inherit FORK;

void create()
{
	set_name("����", ({ "dingpa" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�Ѿųݶ��١�\n");
		set("value", 2500);
		set("material", "steel");
		set("rigidity", 40);
		set("wield_msg", "$N������γ�һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�������䡣\n");
	}
	init_fork(60);
	setup();
}
