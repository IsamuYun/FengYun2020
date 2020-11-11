// jiangli.c by tiandi

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string arg)
{
	object obj,gift;
	string msg,name;
	
	if( !arg ) return notify_fail("你要给谁奖励？\n");

	if(!arg || sscanf(arg,"%s %s",name,msg) != 2)
                     return notify_fail("请输入正确的格式，jiangli <id> <reason>。\n");

	obj = find_player(name);
	if(!obj)		return notify_fail("该玩家没有在线。\n");
		
	gift = new("/d/wiz/tiandi/obj/jiangli");
	gift ->move(obj);
	
 	message("system",HIC "\n【快乐风云】奖励消息："+obj->query("name")+"("+ name + ")由于["HIR+msg+HIC"]，功绩突出，"+this_player()->query("name")+"特赠予其礼品一件。\n" NOR,users());

	message_vision(HIY"天上突然掉下什么东西，直接落入$N的口袋。\n"NOR, obj);
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : jiangli <id> <reason>
 
这个指令会将由巫师发放给对本站作出贡献的玩家的一分礼品。
 
HELP
    );
    return 1;
}
