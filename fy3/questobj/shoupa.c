inherit ITEM;
#include <ansi.h>

void create()
{
        set_name( HIC "ԧ������" NOR, ({ "shoupa" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "������������������Ķ������\n");
	}
	setup();
}
