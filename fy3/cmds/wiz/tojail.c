// edit by xgchne@fy 
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	object room;
	if (!arg) return notify_fail("指令格式: imprison <player>\n");
	ob = find_player(arg);
	if (!ob) return notify_fail("找不到这个玩家。\n");
	message_vision("$N手一挥，一阵微风将$n吹入风云监狱．．．\n",me,ob);
	if(!room =find_object("/d/wiz/jail"))
	room = load_object("/d/wiz/jail");
	ob->move(room);
	ob -> save();
	return 1;
}
 
int help(object me)
{
   write(@HELP
指令格式: tojail <玩家>
将某个玩家禁锢在风云的重犯监狱里，在监狱里什么也做不了，
一直到被提出监狱。

HELP
   );
   return 1;
}
