#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"���־�"NOR, ({ "szjing" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "cloth");
            set("long", "һ���ּ�����ľ���\n");
          }

    setup();
}
void init()
{
  if(this_player()==environment())
  add_action("do_combine","di_shu");
}

int do_combine()
{
int i,bk=0,sp=0;
object commcase,me, *inv;
object szjing,oil;
me = this_player();
inv = all_inventory(me);
i=0;
while(i<sizeof(inv))
                {
                        if(base_name(inv[i]) == "/questobj/szjing") {bk = 1; szjing = inv[i];}
                        if(base_name(inv[i]) == "/questobj/oil") {sp = 1; oil = inv[i];}
                        i++;
		}
if( bk && sp )
{
	message_vision("$N�������İ����͵��ھ����ϣ�������ּ�Խ��Խ����ˡ�\n",me);
	commcase = new(__DIR__"zw-szjing");
	commcase->move(me);
       szjing->move(environment(me));destruct(szjing);
}
else 
message_vision("$N���˿�,ʲô�¶�û�з���!\n",this_player());

return 1;
}
