// lingzhi.c ���Ǻ�«
//����(lywin)2000/4/22

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
	set_name(HIM"���Ǻ�«"NOR, ({"hulu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ��������ı��Ǻ�«����˵��һ�ÿɵ�3500���飬500Ǳ�ܡ�\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("combat_exp", 3500);
	this_player()->add("potential",500);
	message_vision("$N����һ�����Ǻ�«��ֻ�����Լ��ֱ�������һЩ !\n", this_player());
	destruct(this_object());
	return 1;
}

