// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(MAG"������" NOR, ({ "fengzhen" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
            set("long", "һ��С���ݡ���ʰ��������ϵ(xi)��ϸ���ߣ�һ����ɵúܸߡ�\n");
          }

    setup();
}

void init()
{
  if(this_player()==environment())
  add_action("do_xi","xi");
}

int do_xi()
{
object me, *inv;
int i;
object cl,newtask;
me = this_player();
inv = all_inventory(me);
for(i=0; i<sizeof(inv); i++)
{
      if(inv[i]->query("name") == "ϸ����") 
  {     cl = inv[i];
	destruct(cl);
   message_vision("\n$N�������ϸ��������ݰ�Ū�˼��£����ʵʵ��ϵ����һ��\n",this_player());
        newtask = new(__DIR__"obj/fengzhen2");
	newtask->move(me);
	destruct(this_object());
        return 1;
  }
}
        return 1;

}
//}

