#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIW"����"NOR, ({ "zheshan" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("jungle",1);
		set("material", "wood");
		set("long", "����һ�Ѿ��µ����ȡ�\n");
		set("wield_msg", "$N���һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n�������䡣\n");
	}
	init_blade(5);
	setup();
}
