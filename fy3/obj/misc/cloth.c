// cloth.c
// From ES2
// This is the basic equip for players just login.
// 修改：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("布衣", ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一件普普通通的布衣。");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}
