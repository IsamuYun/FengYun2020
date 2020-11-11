// level sheet.c by tiandi

#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIW  "帝王的财宝" NOR, ({ "money box" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个由盗墓者偷挖出来的财宝箱。\n");
		set("value", 100000);
	
	}
	setup();
}
