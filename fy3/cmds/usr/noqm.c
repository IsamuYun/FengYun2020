//edit by xgchen@zzfy
//取消签名指令

#include "ansi.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string *txt;

        if( !arg ) return notify_fail("指令格式：noqm me<id>\n");
          if(arg!=me->query("id")) return notify_fail("指令格式：noqm me<id>\n");

        me->delete("qianminglong");
        write("Ok.\n");
        return 1;
}

int help()
{
        write(@TEXT
指令格式：qianming <文字>

这个指令让你设定当你留言的时候能显示你的签名。
签名超过一行时可以使用to qianming。
TEXT
        );
        return 1;
}


