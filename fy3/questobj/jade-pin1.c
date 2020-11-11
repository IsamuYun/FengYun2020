
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIY"金算盘"NOR, ({ "suanpan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "把");
            set("material", "gold");
            set("long", "一把纯金打造算盘。仔细一看，发现好象少了两个珠
如果能找到它们，并装（zhuang）上去，那就完美无缺了。\n");
		set("value", 1);
	}
}


void init()
{
  if(this_player()==environment())
  add_action("do_zhuang","zhuang");
}

int do_zhuang()
{
int i,hezhu=0,baizhu=0;
object jade,me, *inv;
object zhu1,zhu2;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			if(inv[i]->query("name") == "[1;33m算盘珠[2;37;0m") {hezhu = 1; zhu1 = inv[i];}
			if(inv[i]->query("name") == "[1;33m算盘珠[2;37;0m") {baizhu = 1; zhu2 = inv[i];}

		}
if( hezhu && baizhu )
{
	destruct(zhu1);
        destruct(zhu2);
	jade = new("/questobj/obj/suanpans");
	jade->move(me);
message_vision("$N慢慢地把[1;33m金算盘[2;37;0m拆开，小心地将[1;33m算盘珠[2;37;0m装了上去。
\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N身上没有[1;33m算盘珠[2;37;0m。\n",this_player());

return 1;
}
