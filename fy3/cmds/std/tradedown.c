// by tiandi for trade system
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string item;
	object ob1;
	int price;
          if( me->is_fighting() )
                return notify_fail("战斗中不能下架。\n");
    	    if(! environment(me)->query("trade") )
             	   return notify_fail("这里不允许下架。\n");
    	    if(!me->query_temp("in_trade") )
             	   return notify_fail("你得先摆摊才可以下架啊。\n");
	   if(me->is_ghost())
		   return notify_fail("鬼魂是没有办法摆摊的，你摆了别人也看不见啊。\n");
    	    if(me->query("combat_exp")< 1000000 )
             	   return notify_fail("你的经验太低。\n");
      	   if( me->is_busy() )
             	   return notify_fail("你上一个动作还没有完成，不能下架。\n");
             if(!arg || sscanf(arg,"%s",item) != 1)
                        return notify_fail("请输入正确的格式，tradedown  <item id>。\n");
	   ob1 = present(item,me);
	  if(!ob1)
		    return notify_fail("你身上好像没有这个东西吧？\n");
	 if(!ob1->query_temp("trading") )
		    return notify_fail("这个东西还没有上架吧。\n");


	 message_vision ("$N把"+ob1->query("name")+"从货架上撤了下来。\n",me);
	 ob1->delete_temp("price");
	 ob1->delete_temp("trading");
	ob1->delete_temp("no_drop");
	ob1->delete_temp("no_get");

     	   me->set_temp("in_trade",1);

	
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : tradedown <item id>

摆摊后，你可以用此命令把你已经上架准备贩卖的物品撤下来。

HELP
        );
        return 1;
}
 


