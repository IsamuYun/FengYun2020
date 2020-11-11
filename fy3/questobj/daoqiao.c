#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(BLU"寒萸刀鞘"NOR, ({ "daoqiao" }) );
        set_weight(8000);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
		set("for_bandit2",1);
                set("long", "一个用天山上千年寒萸做成的刀鞘。\n");
        }
}

int is_container() { return 1; }

void init()
{
  if(this_player()==environment())
  add_action("do_combine","kan_qiao");
}

int do_combine()
{
int i,bk=0,sp=0,il=0;
object commcase,me, *inv;
object wandao,daoqiao,unarmed;
me = this_player();
inv = all_inventory(me);
i=0;
while(i<sizeof(inv))
                {
                        if(base_name(inv[i]) == "/questobj/wandao") {bk = 1; wandao = inv[i];}
                        if(base_name(inv[i]) == "/questobj/daoqiao") {sp = 1; daoqiao = inv[i];}
                        i++;
		}
                        if(me->query("str")>=11) {il = 1;}
if( bk && sp && il )
{
           wandao->move(environment(me));destruct(wandao);
	message_vision("$N摧动真气把手中的圆月弯刀往寒萸刀鞘砍去,寒萸刀鞘立刻断裂。\n\n而圆月弯刀也因此化作一堆碎片。\n",me);
	commcase = new(__DIR__"duanqiao");
	commcase->move(me);
        daoqiao->move(environment(me));destruct(daoqiao);
}
else 
message_vision("$N看了看刀鞘,但是怎么也不能把圆月弯刀插进去!\n",this_player());

return 1;
}
