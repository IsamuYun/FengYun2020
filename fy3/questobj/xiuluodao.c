#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name(HIR "���޵�" NOR, ({ "xiuluodao" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�����غ����͸��������Ķ������\n");
		set("material", "steel");
		set("wield_msg", "���һ����$N�ѽ�$n�������У�\n");
		set("unwield_msg", "$N��$n���뵶�ʡ�\n");
	}
	init_blade(20);
	setup();
}
