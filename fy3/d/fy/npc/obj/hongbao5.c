#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIR "结婚红包" NOR, ({ "hongbao5" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
                set("value", 50000);
            set("unit", "个");
            set("material", "cloth");
            set("long", "一个小小的结婚红包，上面绣着：佳偶天成，白头到老\n");
          }
    setup();
}
void init()
{

if(environment()==this_player())
add_action("do_open","open");
}
int do_open(string arg)
{
object gold;
if(arg != "hongbao" && arg != "红包") return 0;
if(query("opened"))
return notify_fail("你打开小红包，但里面是空的！\n");
gold = new("/obj/money/gold");
gold->set_amount(5);
gold->move(this_player());
set("opened",1);
set("value",0);
return notify_fail("你打开结婚红包，从里面拿出一些黄金！\n");
}
