// ling.c
#include <weapon.h>

inherit LING;

void create()
{
	set_name("ͭ��", ({ "ling" }));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "ֻ");
		set("value", 500);
		set("material", "corpper");
		set("long", "����һֻѰ����ͭ�塣\n");
		set("wield_msg", "$N���һֻ���λε�$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�Ż����䡣\n");
	}
	init_ling(20);
	setup();
}
