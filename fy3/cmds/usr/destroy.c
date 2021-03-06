// kickout.c

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg || sscanf(arg, "%s", arg) != 1 )
		return notify_fail("你要摧毁什么？\n");

	if( !objectp(ob = present(arg, me)) )
        return notify_fail("你身上没有这样东西。\n");
	if( ! ob->query("selfmaking"))
	return notify_fail("这样东西不是玩家制作的，你不可以摧毁它。\n");
	seteuid(ROOT_UID);
	rm(base_name(ob) + ".o");
	rm(base_name(ob) + ".c");
	ob->move(environment(me));
	destruct(ob);
	seteuid(getuid());
	write("ＯＫ\n");
	return 1;
}

int help(object me)
{
write(@HELP
你可以用此指令摧毁一件你自己的物件。被摧毁的物件将
永远从风云中消失。此指令是用来摧毁你不想再要的自造物品，
指令格式 : destroy <某物件>

HELP
    );
    return 1;
}

