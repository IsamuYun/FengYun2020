#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(YEL"棋盘"NOR, ({ "qipan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "stone");
            set("long", "一个石制棋盘\n");
          }

    setup();
}
void init()
{
  if(this_player()==environment())
  add_action("do_combine","zuo_qipan");
}

int do_combine()
{
int i,bk=0,sp=0,hs=0,il=0;
object commcase,me, *inv;
object qizi,shiqi,qipan;
me = this_player();
inv = all_inventory(me);
i=0;
while(i<sizeof(inv))
                {
                        if(base_name(inv[i]) == "/questobj/hsq") {bk = 1; qizi = inv[i];}
                        if(base_name(inv[i]) == "/questobj/sq") {sp = 1; shiqi = inv[i];}
                                          if(base_name(inv[i]) == "/questobj/qipan") {hs = 1; qipan = inv[i];}
                        i++;
		}
                        if(me->query("int")>=20) {il = 1;}
if( bk && sp && il )
{
           qizi->move(environment(me));destruct(qizi);
                   shiqi ->move(environment(me));destruct(shiqi);
        message_vision("$N仔细的把一套完整的棋盘装好了。\n",me);
	commcase = new(__DIR__"goodqipan");
	commcase->move(me);
        qipan->move(environment(me));destruct(qipan);
}
else 
message_vision("$N看了看棋盘,这东西怎么装呀，$N觉得自己很笨!\n",this_player());

return 1;
}

