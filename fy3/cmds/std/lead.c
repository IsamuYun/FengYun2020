#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj;

        if(!arg) 
                return notify_fail("指令格式 : lead <玩家>\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if(obj==me)
                return notify_fail("看来你对自己往哪儿去都不清楚了。\n");

        tell_object(me, HIY "你对" + obj->name() + "说道：跟着我，我带你去个好地方。\n" NOR);
        tell_object(obj, HIY " " + me->name() + "对你说道：跟着我，我带你去个地方。\n"
                        + " 如果你愿意跟着" + me->name() + "，请你对"+ me->name() + "键入 follow " + me->query("id") + " 的指令。\n" NOR);
        return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : lead <玩家>
 
这个指令让你主动邀请某个玩家跟随你，同时也告诉这个玩家跟随你
的命令是什么。

其他相关指令: follow
HELP
    );
    return 1;
}
