#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{	set_name("��ֽ",({"paper"}));
	set("long","һ���ɸɾ����İ�ֽ����(draw)һ�ų���д(write)��ʲô�ɡ�\n");
	set("unit","��");
	set("base_unit","��");
	set("value",0);
	set_amount(3);
}
void init()
{	add_action("do_draw","draw");
}

int do_draw(string arg)
{  object paper;
   paper=new(__DIR__"paper");
   if(!arg)
     if(paper->move(this_player()))
       { message_vision("$N���һ�Ű�ֽ���ţ�д��ʲô�أ�\n",this_player());
         this_object()->add_amount(-1);return 1;}
   paper->set("name",arg);paper->set("long","");
   if(paper->move(this_player()))
     message_vision("$N���һ�Ű�ֽ��׼��дһ��"+arg+"��\n",this_player());
     this_object()->add_amount(-1);return 1;
}
