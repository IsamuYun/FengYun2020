// group.c by tiandi 社团信息
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object *ob;
	string file,c_name,arg;
	if (!me->query("group"))
		return notify_fail("你还没有加入社团。\n");
	c_name = me->query("group");
	file = "/data/group/"+c_name;
	if (file_size(file)<0) 
		return notify_fail("找不到"+c_name+"社团的资料。\n");
	

	

}
 
int help(object me)
{
    write(@HELP

此指令让你查看你自己所在的社团的一些信息。
社团是进行城战的前提，只有社团的团长才可以发起城战。

HELP
    );
        return 1;
}
