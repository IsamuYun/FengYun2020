inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIR"风云群英谱"NOR, ({ "qunyingpu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "一本风云群英谱，记载着古今英雄的名字，但翻开一看，
里面引言的地方竟然是空的，如果有支笔，再找到墨汁的话，
你真想写(write)点什么上去。\n");
          }
}


void init()
{
  if(this_player()==environment())
  add_action("do_install","write");
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
                        if(inv[i]->query("name") == "端砚") {hezhu = 1; zhu1 = inv[i];}
                        if(inv[i]->query("name") == "狼毫笔") {baizhu = 1; zhu2 = inv[i];}

                }
if( hezhu && baizhu )
{
        destruct(zhu1);
//        destruct(zhu2);
        jade = new("/questnew/obj/qypu");
        jade->move(me);
message_vision("$N豪兴大发，拿起狼毫笔，草草几笔，将$N在江湖中的处世心得
写在空白的地方。\n",this_player());
        destruct(this_object());

}
else 
message_vision("$N想在风云群英谱上写些什么，可惜的是缺少书写的工具。\n",this_player());

return 1;
}