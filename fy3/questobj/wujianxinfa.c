#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"�޽��ķ�"NOR, ({ "wujianxinfa" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "stone");
            set("long", "һ���ƾɣ��ּ�ģ�����飬��򿪷��˷���������������һҳ��
Ҫ�����ҵ�ȱҳ����������磩�ã�Ҳ������\n");
          }

    setup();
}


void init()
  {
     if(this_player()==environment())
     add_action("do_ding","ding");
  }

int do_ding()
 {
   int i,he1=0,he2=0,he3=0;
   object jade,me, *inv;
   object zhu1,zhu2,zhu3;
   me = this_player();
   inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                   {
	 		if(inv[i]->query("name") == "���Ƶ�ֽ") {he1 = 1; zhu1 = inv[i];}
			if(inv[i]->query("name") == "ϸ����") {he2 = 1; zhu2 = inv[i];}
			if(inv[i]->query("name") == "����") {he3 = 1; zhu3 = inv[i];}
		   }
if( he1 && he2 && he3 )
     {
	destruct(zhu1);
        destruct(zhu2);
        destruct(zhu3);
	jade = new("/questobj/obj/wujianxinfa1");
	jade->move(me);
message_vision("$N��ϸ���ߴ��������ϣ�С������ذѷ��Ƶ�ֽ�����޽��ķ�ȱҳ�ĵط���
Ȼ����缢�ƿʵض����������������ѧ�����Ŵ�ѩ�ľ����书��\n",this_player());
	destruct(this_object());

     }
 else 
    message_vision("$N���϶���������������û��ϣ���ˡ�\n",this_player());
  return 1;
 }

