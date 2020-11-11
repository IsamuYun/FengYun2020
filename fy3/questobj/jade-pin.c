
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIC "觇玉发簪" NOR, ({ "jade-pin"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("long", "一个翠绿欲滴的玉发簪，美中不足的是本来上面镶嵌着的两颗大
宝石却不翼而飞了,你估计如果找到了那两块宝石，或许还可以
把它(install)复原。\n");
		set("value", 1);
	}
}


void init()
{
  if(this_player()==environment())
  add_action("do_install","install");
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
			if(inv[i]->query("name") == "[1;32m凝碧宝石[2;37;0m") {hezhu = 1; zhu1 = inv[i];}
                        if(inv[i]->query("name") == "[1;31m化血宝石[2;37;0m") {baizhu = 1; zhu2 = inv[i];}

		}
if( hezhu && baizhu )
{
	destruct(zhu1);
        destruct(zhu2);
	jade = new("/questobj/obj/pin1");
	jade->move(me);
message_vision("$N小心翼翼的把找到的两块宝石放在觇玉发簪上，只听“卡啦”一声，
两块宝石自动的镶嵌在觇玉发簪上了，一只光彩夺目的觇玉发簪呈现在你的面前。\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N真想把觇玉发簪复原，但可惜的是手中没有材料。\n",this_player());

return 1;
}
