#include <ansi.h>
#include <armor.h>

inherit ITEM;

void create()
{
	set_name(HIY "��������" NOR, ({ "yuxi"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "������Ĵ���������\n");
		set("unit", "��");
		
		
	}
	setup();
}

