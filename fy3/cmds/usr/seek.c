//seek

#include <ansi.h>

int main(object me, string arg)
{
        int i, n;
        object ob;
        object *user;
        
//        if( !wizardp(me) ) return 0;
        if( !arg ) 
                return notify_fail("你要找什么人？\n");
        
        write("目前在线的玩家中，叫 "HIR+arg+NOR+" 的有：\n\n");
        user = users();
        for(i=0,n=0; i<sizeof(user); i++)
        if( user[i]->name()==arg )
        {
                write(user[i]->name()+"("+HIR+getuid(user[i])+NOR+")\n");
                n++;
        }
        if( n==0 ) write("目前在线的玩家当中没有叫 "+HIR+arg+NOR+" 的。\n");
        
        return 1;
}
int help (object me)
{
        write(@HELP
指令格式 : seek [玩家中文名字]
 
这个指令让你查看玩家的中文名字是哪个英文名字�
 
HELP
);
        return 1;
}

