// icy_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( HIY "����ս��" NOR, ({ "long zhanjia", "zhanjia" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 40000);
		set("material", "cloth");
		set("armor_prop/armor", 30);
		set("armor_prop/dodge", 20);
	}
	setup();
}