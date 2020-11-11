#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string wmp;
        if(!arg = me->quest_skill("arg"))
                return notify_fail("你不想传授什么？\n");

        if(!me->query("env/no_teachskill"))
                me->set("env/no_teachskill", wmp+">");
        else
                me->set("env/no_teachskill", me->query("env/no_teachskill")+wmp+">");
        return 1;
}
 
int help(object me)
{
write(@HELP
指令格式 : notskill <武功>
这个指令用来设置不传授什么武功给弟子的
HELP
    );
    return 1;
}
