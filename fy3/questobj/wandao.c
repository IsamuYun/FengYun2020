//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name(HIC "Բ���䵶" NOR, ({ "wandao" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����״�����صĵ�������·��е�������\n");
		set("material", "steel");
		set("wield_msg", "$N��$nͻȻ���ʣ��������û�п���$N�ε���\n");
		set("unwield_msg", "$N��$n�����ʡ�\n");
	}
	init_blade(25);
	setup();
}
