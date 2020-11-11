#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"«ÎºÌ"NOR,({"qingjian","jian"}));
	set_weight(3);
	set("unit","’≈");
    if( clonep() )
		set_default_object(__FILE__);
       else {set("long","");}
}
