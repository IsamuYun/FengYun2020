// wizlist.c
#include <ansi.h>
int main(object me, string arg)
{
        string str;
	str="";	
        str += HIR"≡"HIC"────────"HIR" ☆"HIY" 一世风云 "HIR"☆ "HIC"──────────"HIR"≡\n"NOR;
        str += HIG"\n☆☆☆☆☆☆☆☆☆"HIB"本游戏没有管理巫师"HIG"☆☆☆☆☆☆☆☆☆☆\n"NOR;
        str += "\n"HIR"≡"HIC"──────────────────────────"HIR"≡\n"NOR;
        me->start_more(str);
        return 1;
}
int help(object me)
{
        write("\n指令格式 : wizlist\n"
        "用途 : 列出目前所有的巫师名单。\n"
        );
        return 1;
}
