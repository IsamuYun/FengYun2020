#include <weapon.h>
inherit THROWING;
#include <ansi.h>
void create()
{
	set_name("梅树幼苗", ({ "tree", "plum tree" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","又软又轻的树苗，也许你可以用来造（ｍａｋｅ）些东西．\n");
		set("unit", "捆");
		set("base_unit", "根");
		set("base_weight", 10000);
		set("base_value", 1);
	}
	set_amount(1);
	init_throwing(20);
	setup();
}
void init()
{
  if(this_player()==environment())
  add_action("do_make","make");

}

int do_make()
{
	object boat;
	if(query_amount() < 15)
	return notify_fail("才"+chinese_number(query_amount())+
	"根梅树幼苗，什么也造不出呀．．．\n");
	boat = new(__DIR__"boat");
	if(boat->move(this_player()))
	write("你用灵巧的双手造出了一只小木舟。\n");
	if(!this_player()->query("m_success/木舟"))
        {
                this_player()->set("m_success/木舟",1);
                this_player()->add("score",150);
	message("system",HIC "\n【快乐风云】谜题任务："+this_player()->query("name")+"解开了相关谜题，获得了"HIY"【心灵手巧】"HIC"的称号。\n" NOR,users());

        }
	destruct(this_object());
	return 1;
			
}
