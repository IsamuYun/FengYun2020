// diamond-wood.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "ľ��ʯ" NOR, ({ "wood diamond", "diamond" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
    		set("long", @LONG 
����һ��ľ��ʯ��
LONG
  		);
		set("value", 200000);
		set("material", "diamond");
    	};
        setup();
}
