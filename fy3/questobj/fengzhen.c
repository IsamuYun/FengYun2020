// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(MAG"花风筝" NOR, ({ "fengzhen" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "paper");
            set("long", "一个小风筝。五彩斑澜，如果系(xi)上细棉线，一定会飞得很高。\n");
          }

    setup();
}

void init()
{
  if(this_player()==environment())
  add_action("do_xi","xi");
}

int do_xi()
{
object me, *inv;
int i;
object cl,newtask;
me = this_player();
inv = all_inventory(me);
for(i=0; i<sizeof(inv); i++)
{
      if(inv[i]->query("name") == "细棉线") 
  {     cl = inv[i];
	destruct(cl);
   message_vision("\n$N把手里的细棉线与风筝摆弄了几下．结结实实地系在了一起。\n",this_player());
        newtask = new(__DIR__"obj/fengzhen2");
	newtask->move(me);
	destruct(this_object());
        return 1;
  }
}
        return 1;

}
//}

