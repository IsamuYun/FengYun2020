#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("装着珠宝的" + HIW "白玉" NOR + "珠宝盒" , ({ "zhubaohe"}) );
        set_weight(100);
 	set("unit", "个");
	set("long", "一个用白玉作成的专门放置珠宝和盒子。\n");
	set("closed", 1);
	set("value", 500000);
}

