// lingzhi.c 
#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIM"�߲���"NOR, ({"yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ����������߲�������˵��һ������ʹ�����������������ﵽ���ޡ�\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	object me;
	int max_force,max_mana,max_atman;
	me = this_player();
	max_force=((int)me->query_skill("force", 1) + me->query_skill("force")/5) * 5;
	max_mana=((int)me->query_skill("spells", 1) + me->query_skill("spells")/5) * 5;
	max_atman=((int)me->query_skill("magic", 1) + me->query_skill("magic")/5) * 5;


	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	if(me->query("max_force")<max_force) {
     me->set("max_force",max_force);
     tell_object(me,"���������������ˣ�\n");
    }
	if(me->query("max_mana")<max_mana) {
     me->set("max_mana",max_mana);
     tell_object(me,"��ķ�����������ˣ�\n");
    }
	if(me->query("max_atman")<max_atman) {
     me->set("max_atman",max_atman);
     tell_object(me,"���������������ˣ�\n");
    }

	message_vision("$N����һ�ŵ�ҩ��ֻ�����Լ��������������˼��� !\n", this_player());
	destruct(this_object());
	return 1;
}

