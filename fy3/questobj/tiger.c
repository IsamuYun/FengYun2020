
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIW "白玉老虎" NOR, ({ "tiger"}) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "一只晶莹剔透的白玉老虎,发出淡淡的光芒。
      在它的底部有一个小孔，你可以把什么东西从这个小孔塞（sai）进去。\n");
		set("value", 1);
	}
}


void init()
{
  if(this_player()==environment())
  add_action("do_sai","sai");
}

int do_sai()
{
int i,hezhu=0,baizhu=0;
object jade,me, *inv;
object zhu1;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
			if(inv[i]->query("name") == "[37m蜡封密函[2;37;0m") {hezhu = 1; zhu1 = inv[i];}
		}
if( hezhu )
{
	destruct(zhu1);
	jade = new("/questobj/obj/tiger1");
	jade->move(me);
message_vision("$N把[37m蜡封密函[2;37;0m打开，把里面的一张小纸片卷成一个小卷，小心地把它从[1;37m白玉老虎[2;37;0m底
部的小孔塞了进去,并把小孔封上。\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N想把什么东西塞进去？\n",this_player());

return 1;
}
