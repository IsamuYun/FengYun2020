#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)

{
        object ob1,ob2;
        if( !arg || arg=="" )
                return notify_fail("指令格式: snoopwho <某人>\n");
        ob1 = find_player(arg);

        if (!ob1) return notify_fail("没有这个人。\n");
        if( arg=="atu" )
                return notify_fail(ob1->query("name") + "现在没有在监听\n");
        if ( objectp(ob2 = query_snooping(ob1)) )
                        write(ob1->query("name") + "现在正在监听" + ob2->query("name") + "所收到的讯息。\n") ;
        if (!ob2) return notify_fail(ob1->query("name") + "现在没有在监听\n");
        return 1;
}
int help()
{
        write(@TEXT
指令格式 snoopwho  <某人>
 
查看目标人物是否在监听。
TEXT
        );
        return 1;
}
