// blade.c
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("����", ({ "blade" }));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500);
		set("material", "iron");
		set("long", "����һѰ���ĵ�����������Լ�����߽��ء�\n");
		set("wield_msg", "$N���һ�����λε�$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��������ĵ��ʡ�\n");
		set("limited_lv",1);
		set("abradability",100);
	}
	init_blade(25);
	setup();
}