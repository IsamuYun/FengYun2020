// ken 1999.12.7

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(HIB"�ֻ���"NOR, ({ "huajian" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("jungle",1);
		set("material", "iron");
		set("long", "����һ������\n");
		set("wield_msg", "$N�ó�һ���ֻ��õ�$n�������С�\n");
		set("unequip_msg", "$N�����е�$n�Żػ��\n");
	}
	init_blade(5);
	setup();
}
