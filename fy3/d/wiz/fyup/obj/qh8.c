// 强化石头 by tiandi

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIY"强化石" NOR, ({ "stone" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块强化武器装备的石头，强化等级八级。\n");
		set("qianghua",8);
		set("value", 100000);
	
	}
	setup();
}
