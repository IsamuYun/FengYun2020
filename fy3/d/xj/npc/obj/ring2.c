#include <armor.h>

inherit FINGER;

void create()
{
	set_name("����ָ", ({ "wedding ring", "ring"}) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000000);
		set("wear_msg", "$N����ذ�һ��$n������ָ�ϡ�\n");
		set("unwield_msg", "$N����ذ�$n����ָ�ϳ���������\n");
	}
	setup();
}