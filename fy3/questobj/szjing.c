#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"三字经"NOR, ({ "szjing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "cloth");
            set("long", "一本字迹不清的经文\n");
          }

    setup();
}
void init()
{
  if(this_player()==environment())
  add_action("do_combine","di_shu");
}

int do_combine()
{
int i,bk=0,sp=0;
object commcase,me, *inv;
object szjing,oil;
me = this_player();
inv = all_inventory(me);
i=0;
while(i<sizeof(inv))
                {
                        if(base_name(inv[i]) == "/questobj/szjing") {bk = 1; szjing = inv[i];}
                        if(base_name(inv[i]) == "/questobj/oil") {sp = 1; oil = inv[i];}
                        i++;
		}
if( bk && sp )
{
	message_vision("$N你慢慢的把神油滴在经书上，经书的字迹越来越清楚了。\n",me);
	commcase = new(__DIR__"zw-szjing");
	commcase->move(me);
       szjing->move(environment(me));destruct(szjing);
}
else 
message_vision("$N看了看,什么事都没有发生!\n",this_player());

return 1;
}
