// 强化石头 by tiandi

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(MAG"强化石" NOR, ({ "stone" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块强化武器装备的石头，强化等级十三级。\n");
		set("qianghua",13);
		set("value", 100000);
	
	}
	setup();
}
