#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("ţƤ�޹�", ({ "gu"}) );
        set_weight(300);
        set_max_encumbrance(80000);
	set("unit", "��");
	set("long", "�����»���¥�еľ޹ģ��ഫ��ӡ����ţƤ���ơ�\n");
	set("closed", 1);
	set("value", 20000);
}

int is_container() {return 1;}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","cut");
}
int do_open(string arg)
{
	object		me, ob;
        if( !arg || arg != "gu" )
                return notify_fail("��Ҫ�ʲô��\n");
	me = this_player();
	ob = this_object();
	message_vision("$N��������һ������$n���м仮����������\n", me, ob);
		ob->set("closed",0);
        set("long", "�����»���¥�еľ޹ģ��ഫ��ӡ����ţƤ���ơ�
��ϧ���ǹ����Ѿ����˰����ˡ�����\n");
        return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
