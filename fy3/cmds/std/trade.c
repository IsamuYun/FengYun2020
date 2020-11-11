// by tiandi for trade system
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        if( me->is_fighting() )
                return notify_fail("战斗中不能摆摊。\n");
    	    if(! environment(me)->query("trade") )
             	   return notify_fail("这里不允许摆摊。\n");
    	    if(me->query_temp("in_trade") )
             	   return notify_fail("你已经在摆摊了。\n");
	   if(me->is_ghost())
		   return notify_fail("鬼魂是没有办法摆摊的，你摆了别人也看不见啊。\n");
    	    if(me->query("level")< 10 )
             	   return notify_fail("你的等级太低。\n");
      	   if( me->is_busy() )
             	   return notify_fail("你上一个动作还没有完成，不能摆摊。\n");
     
	   message_vision("$N左手从身后拿出一把小凳子，右手拿出一块牌子，匆匆地写上了几笔，便一屁股坐在了凳子上开始摆摊。\n",me);
	  write ("你可以用上架(tradeup)，下架(tradedown)，收摊(exit)。\n");
     	   me->set_temp("in_trade",1);

	
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : trade

你可以在允许摆摊的地方用这个命令进行摆摊操作。

HELP
        );
        return 1;
}
 


