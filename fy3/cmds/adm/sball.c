// purge.c

#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string file;
	string *tmp;
	int loop;
        if( wiz_level(me) < wiz_level("(admin)") )
	return notify_fail("你的巫师等级太低，没有使用这个指令的权力。\n");  
	file = read_file(arg);
	tmp = explode(file,"\n");
	for(loop=0; loop<sizeof(tmp); loop++)
	{
	reset_eval_cost();
	"/cmds/wiz/update"->main(me,"/"+tmp[loop]);
	}
	write("DONE\n");
	return 1;
}
