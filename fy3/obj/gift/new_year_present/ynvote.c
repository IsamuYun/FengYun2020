// Cmds:/cmds/usr/ynvote.c
// 新年投票指令，给别人或自己投上一票。

inherit F_CLEAN_UP;
#include <ansi.h>

int help();

int main(object me, string arg)
{
	object ob;
	if ( !arg || arg=="" ) return help();
/*这里要注意，我仔细考虑了情况，觉得还是让玩家可以投票给自己好一点，假如你的
   MUD人多的话，就允许投给自己吧，假如人少，容易出现票数相同的，那就不允许
   投给自己吧，加上下面这一句就可以了。这里要说明一下，假如出现票数相同，奖励
   给谁？很难说，靠运气吧！
	if (arg==me->query("id")) return notify_fail("谦虚一点好不好？\n");*/
	if (me->query("have_voted")) return notify_fail("对不起，你已经投过票了。\n");
	if (wizardp(me)) return notify_fail("巫师就别在这儿搅和了吧。\n");
	if (!YNVOTE_D->query_temp("voting")) return notify_fail("现在并不在投票呀。\n");
	if (!ob=find_player(arg)) return notify_fail("没有这个玩家。\n");
	else {
	write("Ok。你已经为"+ob->name()+"成功的投出了一票！\n");
	message("system",RED"【新年精灵】"WHT+me->name()+"("+me->query("id")+")将自己的一票投给了"+ob->name()+"("+ob->query("id")+")！\n"NOR,users());
	ob->add_temp("voted",1);
	me->set("have_voted",1);
	return 1;
	}
}

int help()
{
	write(@TEXT
指令格式：ynvote <玩家id>

这个指令让你在新年投票活动中给玩家投票，
每人只能投一票。

TEXT
	);
	return 1;
}
