// TIE@FY3
#include <armor.h>
inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIR"���ɢ����"NOR, ({ "huaqun" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ߵ���׺���������·�\n");
		set("material", "cloth");
		set("armor_prop/armor", 3);
		set("armor_prop/intelligence",2);
	}
	setup();
}
