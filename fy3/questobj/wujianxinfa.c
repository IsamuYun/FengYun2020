#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"无剑心法"NOR, ({ "wujianxinfa" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "stone");
            set("long", "一本破旧，字迹模糊的书，你打开翻了翻，发现其中少了一页。
要是能找到缺页，订（ｄｉｎｇ）好，也许···\n");
          }

    setup();
}


void init()
  {
     if(this_player()==environment())
     add_action("do_ding","ding");
  }

int do_ding()
 {
   int i,he1=0,he2=0,he3=0;
   object jade,me, *inv;
   object zhu1,zhu2,zhu3;
   me = this_player();
   inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                   {
	 		if(inv[i]->query("name") == "发黄的纸") {he1 = 1; zhu1 = inv[i];}
			if(inv[i]->query("name") == "细麻线") {he2 = 1; zhu2 = inv[i];}
			if(inv[i]->query("name") == "银针") {he3 = 1; zhu3 = inv[i];}
		   }
if( he1 && he2 && he3 )
     {
	destruct(zhu1);
        destruct(zhu2);
        destruct(zhu3);
	jade = new("/questobj/obj/wujianxinfa1");
	jade->move(me);
message_vision("$N将细麻线穿在银针上，小心翼翼地把发黄的纸订在无剑心法缺页的地方，
然后就如饥似渴地读了起来，想从上面学到西门吹雪的绝世武功。\n",this_player());
	destruct(this_object());

     }
 else 
    message_vision("$N身上东西不够，看来是没有希望了。\n",this_player());
  return 1;
 }

