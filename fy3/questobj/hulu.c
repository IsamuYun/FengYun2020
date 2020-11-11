// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIC"酒葫芦" NOR, ({ "hulu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "paper");
       set("long", "一个灌酒(guan)的大葫芦，可惜现在是空的，看得出来，此物的主人必定嗜好杯中之物。\n");}
     setup();
}


void init()
{
  if(this_player()==environment())
  add_action("do_guan","guan");
}

int do_guan()
{
int i,aa=0,bb=0,cc=0;
object newtask,me, *inv;
object aaa,bbb,ccc;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
   if(inv[i]->query("name") == "大酒袋") {aa = 1; aaa = inv[i];}
   if(inv[i]->query("name") == "牛皮酒袋") {bb = 1; bbb = inv[i];}
   if(inv[i]->query("name") == "羊皮酒袋") {cc = 1; ccc = inv[i];}
   		}
if( aa && bb && cc )
{
	destruct(aaa);
        destruct(bbb);
        destruct(ccc);
	newtask = new(__DIR__"obj/hulu2");
	newtask->move(me);
message_vision("$N把酒袋里的各种酒混在一起，灌入葫芦里，又试着尝了一口，果然别有风味。\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N掂了掂手里的葫芦，觉得可以装下很多酒。\n",this_player());

return 1;
}

