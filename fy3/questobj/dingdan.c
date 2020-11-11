
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name( HIR"棺材定单" NOR, ({ "dingdan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张详细的定单，记载着棺材的预定情况：
上等檀香木棺材一口．．下面有一行用红笔圈写的文字很值得注意：
南宫钱庄欲定做（zuo)一水晶棺材，现在缺少材料：水晶、檀香木料。\n");
	}
}


void init()
{
  if(this_player()==environment())
  add_action("do_install","zuo"); 
}

int do_install()
{
int i,hezhu=0,baizhu=0;
object jade,me, *inv;
object zhu1,zhu2;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			if(inv[i]->query("name") == "檀香木料") {hezhu = 1; zhu1 = inv[i];}
                        if(inv[i]->query("name") == "[1;37m水晶[2;37;0m") {baizhu = 1; zhu2 = inv[i];}

		}
if( hezhu && baizhu )
{
	destruct(zhu1);
        destruct(zhu2);
	jade = new("/questobj/obj/guancai1");
	jade->move(me);
message_vision("$N凭着自己的想象，试图做出一个完美的水晶棺材。$N忙了半天，
累得满头大汗，才做出了个一口难看的棺材。$N真后悔浪费了这些
材料，但或许把这口棺材拿到棺材店还能有所补救。\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N一时冲动，想按照定单上的材料做口棺材，但可惜的是缺少材料。\n",this_player());

return 1;
}
