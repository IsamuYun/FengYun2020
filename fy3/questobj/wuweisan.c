// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIC"��Ϊ�徲ɢ" NOR, ({ "wuweisan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
       set("long", "һ����Ϊ�徲ɢ���ݴ����Դ˵���(tiao)��������������ҩ����\n");}
     setup();
}


void init()
{
  if(this_player()==environment())
  add_action("do_tiao","tiao");
}

int do_tiao()
{
int i,aa=0,bb=0;
object newtask,me, *inv;
object aaa,bbb;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
   if(inv[i]->query("name") == "ѩ���") {aa = 1; aaa = inv[i];}
   if(inv[i]->query("name") == "���") {bb = 1; bbb = inv[i];}
     		}
if( aa && bb )
{
	destruct(aaa);
        destruct(bbb);
      	newtask = new(__DIR__"obj/yao");
	newtask->move(me);
message_vision("$N��ѩ���ͳ�ݵ��飬����Ϊɢ������һ��\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N�������е���Ϊ�徲ɢֱ������\n",this_player());

return 1;
}

