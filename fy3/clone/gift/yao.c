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
	set_name(HIM"七昌丹"NOR, ({"yao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "串");
		set("long", "这是一棵武林人士梦寐以求的七昌丹，据说吃一棵立刻使内力、法力和灵力达到极限。\n");
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
	return notify_fail("你要吃什么？\n");

	if(me->query("max_force")<max_force) {
     me->set("max_force",max_force);
     tell_object(me,"你的内力上限提高了！\n");
    }
	if(me->query("max_mana")<max_mana) {
     me->set("max_mana",max_mana);
     tell_object(me,"你的法力上限提高了！\n");
    }
	if(me->query("max_atman")<max_atman) {
     me->set("max_atman",max_atman);
     tell_object(me,"你的灵力上限提高了！\n");
    }

	message_vision("$N吃下一颗丹药，只觉得自己的修炼提升到了极致 !\n", this_player());
	destruct(this_object());
	return 1;
}

