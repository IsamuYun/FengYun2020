// diamond-earth.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(YEL "����ʯ" NOR, ({ "earth diamond", "diamond" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
    		set("long", @LONG 
����һ������ʯ��
LONG
  		);
		set("value", 200000);
		set("material", "diamond");
    	};
        setup();
}
