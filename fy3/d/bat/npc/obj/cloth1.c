// cloth.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIB"������"NOR, ({ "blue cloth","cloth"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���·���\n");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 10);
	}
	setup();
}
