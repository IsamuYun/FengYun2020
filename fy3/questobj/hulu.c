// ken 1999.12.7

#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIC"�ƺ�«" NOR, ({ "hulu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "paper");
       set("long", "һ�����(guan)�Ĵ��«����ϧ�����ǿյģ����ó�������������˱ض��Ⱥñ���֮�\n");}
     setup();
}


void init()
{
  if(this_player()==environment())
  add_action("do_guan","guan");
}

int do_guan()
{
int i,aa=0,bb=0,cc=0;
object newtask,me, *inv;
object aaa,bbb,ccc;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
   if(inv[i]->query("name") == "��ƴ�") {aa = 1; aaa = inv[i];}
   if(inv[i]->query("name") == "ţƤ�ƴ�") {bb = 1; bbb = inv[i];}
   if(inv[i]->query("name") == "��Ƥ�ƴ�") {cc = 1; ccc = inv[i];}
   		}
if( aa && bb && cc )
{
	destruct(aaa);
        destruct(bbb);
        destruct(ccc);
	newtask = new(__DIR__"obj/hulu2");
	newtask->move(me);
message_vision("$N�Ѿƴ���ĸ��־ƻ���һ�𣬹����«������ų���һ�ڣ���Ȼ���з�ζ��\n",this_player());
	destruct(this_object());

}
else 
message_vision("$N���˵�����ĺ�«�����ÿ���װ�ºܶ�ơ�\n",this_player());

return 1;
}

