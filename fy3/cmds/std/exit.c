// by tiandi for trade system
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
       object *inv; 
	 int i;
	 if(! me->query_temp("in_trade") )
                return notify_fail("你又没有摆摊，收什么摊啊？\n");
	 inv = all_inventory(me);
	 for(i=0;i<sizeof(inv);i++)
		{
		if (inv[i]->query_temp("trading"))
			{
			inv[i]->delete_temp("trading");
			inv[i]->delete_temp("price");
			inv[i]->delete_temp("no_drop");
			inv[i]->delete_temp("no_get");
			}
		}

     	   message_vision("$N从小凳子上站了起来，收起了摊位。\n",me);
     	   me->delete_temp("in_trade");


        return 1;
}


int help(object me)
{
        write(@HELP
指令格式 : exit

当你的人物在摆摊的时候，用这个命令可以收摊。

HELP
        );
        return 1;
}
 


