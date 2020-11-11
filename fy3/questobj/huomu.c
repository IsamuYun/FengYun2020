#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(HIR"火木"NOR, ({ "huo-mu"}));
	set_weight(3);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个在能发光的神木。\n");
		set("value", 10000);
	}
}

void init()
{
        add_action("do_use", "use");
}

int do_use(string arg)
{
        if( arg != "pearl" ) return 0;

        tell_object(this_player(),"你把" + this_object()->name() + "点燃了,光亮异常。\n");
        environment(this_player())->light_notify(this_object(), 1);

        return 1;
}


