//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name(CYN "��ɫС��" NOR, ({ "dao" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѻ�С�ĵ����Դ�һ˿��ɫ��\n");
		set("material", "steel");
		set("wield_msg", "���һ�֣�$NͻȻ�γ�$n��\n");
		set("unwield_msg", "$N��$n�����ʡ�\n");
	}
	init_blade(80);
	setup();
}
