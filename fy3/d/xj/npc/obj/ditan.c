#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�½���̺", ({ "thick carpet"}) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ���൱��ʵ���½���̺��");		
		set("material", "cloth");
                set("value", 100);
		set("armor_prop/armor", 10);
	}
	setup();
}
