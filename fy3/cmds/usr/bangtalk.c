// user list
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
        object *ob,*target;
        int i;
	string mebang,obbang;
	string fa_name,outarg;
        if(me->query("chblk_on"))
                return notify_fail("你的频道被关了！\n");
	mebang = (string)me->query("class");
	if(!mebang) return notify_fail("你不属于任何帮派！\n");
        ob=users();
        i = sizeof(ob);
        while (i--) {
		obbang = (string)ob[i]->query("class");
		if ( (mebang == obbang || wizardp(ob[i])) && !ob[i]->query("env/bangtalk"))
		{
			if (sizeof(target)==0)
				target=({ob[i]});
			 else 
				target+=({ob[i]});
		}
	}
	if(!stringp(fa_name=me->query("family/family_name")))
		 fa_name = "平民百姓";
	if(!stringp(outarg = arg))
		outarg = "．．．．．";	
	message("vision", HIW "【"+fa_name+"】" + 
	me->query("name") + "(" + capitalize(me->query("id")) + ")" + 
	"：" + outarg + "\n" NOR, target);	
        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : bangtalk 内容
与同门的玩家们通过【帮会】频道讲话
bangtalk也可以用bt来代替
HELP
    );
    return 1;
}
