// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIC"无为清静散" NOR, ({ "wuweisan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "包");
            set("material", "paper");
       set("long", "一包无为清静散。据传可以此调制(tiao)出起死回生的神药来。\n");}
     setup();
}


void init()
{
  if(this_player()==environment())
  add_action("do_tiao","tiao");
}

int do_tiao()
{
int i,aa=0,bb=0;
object newtask,me, *inv;
object aaa,bbb;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
   if(inv[i]->query("name") == "雪蛤蟆") {aa = 1; aaa = inv[i];}
   if(inv[i]->query("name") == "虫草") {bb = 1; bbb = inv[i];}
     		}
if( aa && bb )
{
	destruct(aaa);
        destruct(bbb);
      	newtask = new(__DIR__"obj/yao");
	newtask->move(me);
message_vision("$N把雪蛤蟆和虫草捣碎，与无为散调合在一起。\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N看着手中的无为清静散直发呆。\n",this_player());

return 1;
}

