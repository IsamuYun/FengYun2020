// diamond-gold.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "��ʯ" NOR, ({ "gold diamond", "diamond" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
    		set("long", @LONG 
����һ�Ž�ʯ��
LONG
  		);
		set("value", 200000);
		set("material", "diamond");
    	};
        setup();
}
