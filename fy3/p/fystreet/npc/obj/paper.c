#include <ansi.h>
inherit ITEM;
void create()
{	set_name("��ֽ",({"paper"}));
	set("long","һ�Ű�ֽ������д�ţ�\n");
	set("unit","��");
	set("value",0);
}
void init()
{	add_action("do_write","write");
}

int do_write(string arg)
{  if(!arg) return notify_fail("��Ҫдʲô��\n");
   this_object()->set("long",this_object()->query("long")+arg+"\n");
   write("ok.\n");return 1;
}
