// purge.c

#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string file;
	string *tmp;
	int loop;
        if( wiz_level(me) < wiz_level("(admin)") )
	return notify_fail("�����ʦ�ȼ�̫�ͣ�û��ʹ�����ָ���Ȩ����\n");  
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
