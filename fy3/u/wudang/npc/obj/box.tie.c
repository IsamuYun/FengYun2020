
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("����", ({ "box"}) );
        set_weight(300);
	set("unit", "��");
	set("long", "һ��������������С���������Ű�����(open)\n");
	set("opened", 0);
	set("value", 200);
}

int is_container() {return 1;}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","open");
}

int do_open(string arg)
{
	object		me, ob;
	int		kar;
	
        if( !arg || arg != "box" )
                return notify_fail("��Ҫ��ʲô��\n");
	me = this_player();
	ob = this_object();
	message_vision("$NС�ĵذ�$n�򿪡�\n", me, ob);
	kar = me->query("kar");
	if( kar < 27 && random(5) != 3) { 
		message_vision(HIR "ֻ������������һ�������Ŵ�$n�������ֻ��ɫ�����룬������$N�����ϣ�\n" NOR, me, ob);
		me->apply_condition("no_shadow", 10);
		message_vision(HIR "$N�������ϵĶ���\n" NOR, me);
	}
	else {
		ob->set("opened",1);
        message_vision("$NС�ĵذ�$n�򿪡�\n", me, ob);
	}
        return 1;
}

int is_locked()
{
return (int) this_object()->query("opened");
}
