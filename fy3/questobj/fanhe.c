// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"饭盒" NOR, ({ "fanhe" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "paper");
       set("long", "一个空着的红木饭盒。里面可以装(zhuang)进去好些食物。\n");
          }
     setup();
}


void init()
{
  if(this_player()==environment())
  add_action("do_zhuang","zhuang");
}

int do_zhuang()
{
int i,aa=0,bb=0,cc=0;
object newtask,me, *inv;
object aaa,bbb,ccc;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
   if(inv[i]->query("name") == "粗米饭") {aa = 1; aaa = inv[i];}
   if(inv[i]->query("name") == "青菜") {bb = 1; bbb = inv[i];}
   if(inv[i]->query("name") == "竹筷子") {cc = 1; ccc = inv[i];}
   		}
if( aa && bb && cc )
{
	destruct(aaa);
        destruct(bbb);
        destruct(ccc);
	newtask = new(__DIR__"obj/fanhe2");
	newtask->move(me);
message_vision("$N拼命地把饭菜往饭盒里倒，直到再也装不下为止。\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N掂了掂手里的饭盒，觉得可以装下很多东西。\n",this_player());

return 1;
}

