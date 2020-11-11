#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{	set_name("白纸",({"paper"}));
	set("long","一叠干干净净的白纸，抽(draw)一张出来写(write)点什么吧。\n");
	set("unit","叠");
	set("base_unit","张");
	set("value",0);
	set_amount(3);
}
void init()
{	add_action("do_draw","draw");
}

int do_draw(string arg)
{  object paper;
   paper=new(__DIR__"paper");
   if(!arg)
     if(paper->move(this_player()))
       { message_vision("$N抽出一张白纸，嗯，写点什么呢？\n",this_player());
         this_object()->add_amount(-1);return 1;}
   paper->set("name",arg);paper->set("long","");
   if(paper->move(this_player()))
     message_vision("$N抽出一张白纸，准备写一份"+arg+"。\n",this_player());
     this_object()->add_amount(-1);return 1;
}
