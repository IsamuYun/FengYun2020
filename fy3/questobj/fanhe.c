// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"����" NOR, ({ "fanhe" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
       set("long", "һ�����ŵĺ�ľ���С��������װ(zhuang)��ȥ��Щʳ�\n");
          }
     setup();
}


void init()
{
  if(this_player()==environment())
  add_action("do_zhuang","zhuang");
}

int do_zhuang()
{
int i,aa=0,bb=0,cc=0;
object newtask,me, *inv;
object aaa,bbb,ccc;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
   if(inv[i]->query("name") == "���׷�") {aa = 1; aaa = inv[i];}
   if(inv[i]->query("name") == "���") {bb = 1; bbb = inv[i];}
   if(inv[i]->query("name") == "�����") {cc = 1; ccc = inv[i];}
   		}
if( aa && bb && cc )
{
	destruct(aaa);
        destruct(bbb);
        destruct(ccc);
	newtask = new(__DIR__"obj/fanhe2");
	newtask->move(me);
message_vision("$Nƴ���ذѷ����������ﵹ��ֱ����Ҳװ����Ϊֹ��\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N���˵�����ķ��У����ÿ���װ�ºܶණ����\n",this_player());

return 1;
}

