#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"���"NOR,({"hongbao"}));
	set("long","һ������ʱ�õĺ�������Դ���(open)\n");
    set_max_encumbrance(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("weight",3);
		set("closed",1);
	}
}
int is_container()
{
	return 1;
}
void init()
{
        if(this_player()==environment())
                 add_action("do_open","open");
}
int do_open(string arg)
{
	object xijin,ob,me;
	ob=this_object();
	xijin=new("/obj/money/gold");
	xijin->set_amount(ob->query_temp("account"));
	xijin->move(ob);
	me=this_player();
	if ( !arg || arg != "hongbao")
	{
		return notify_fail("��Ҫ��ʲô��\n");
	}
	message_vision("$NС������ش򿪺��......\n",me);
	ob->set("closed",0);
	return 1;
}
int is_closed()
{
        return ((int) this_object()->query("closed"));
}
