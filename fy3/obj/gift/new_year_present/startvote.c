// startvote.c
// 开始投票的程序，因为投票的奖励比较大，一定要高等级巫师
// 才有权力开始，并且要选择在线玩家比较多的时候才开始！

#include <ansi.h>
inherit F_CLEAN_UP;
int help();

int main(object me, string arg)
{
	if (arg) return help();
	if (YNVOTE_D->query_temp("voting")) return notify_fail("现在已经在投票了呀。\n"); // 假如正在投票
	else {
	write(WHT+MUD_NAME+"新年投票系统正在启动．．．\n"NOR);
	YNVOTE_D->create(); // 调用系统文件中的create()函数启动
	write(RED"．．．启动成功！\n"NOR);
	return 1;
	}
}

int help ()
{
        write(@HELP
指令格式: startvote
 
正式开始新年辞旧迎新投票活动！
 
HELP
);
        return 1;
}