// by tiandi for trade system
#include <ansi.h>
inherit F_CLEAN_UP;
string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "文钱";
	else
		return chinese_number(value/100) + "两"
			+ (value%100? "又" + chinese_number(value%100) + "文钱": "");
}

int main(object me, string arg)
{
	string item;
	object ob1;
	int price;
        if( me->is_fighting() )
                return notify_fail("战斗中不能上架。\n");
    	    if(! environment(me)->query("trade") )
             	   return notify_fail("这里不允许上架。\n");
    	    if(!me->query_temp("in_trade") )
             	   return notify_fail("你得先摆摊才可以上架啊。\n");
	   if(me->is_ghost())
		   return notify_fail("鬼魂是没有办法摆摊的，你摆了别人也看不见啊。\n");
    	    if(me->query("level")< 10 )
             	   return notify_fail("你的等级太低。\n");
      	   if( me->is_busy() )
             	   return notify_fail("你上一个动作还没有完成，不能上架。\n");
     
           if(!arg || sscanf(arg,"%d %s",price,item) != 2)
                        return notify_fail("请输入正确的格式，tradeup <price> <item id>。\n");
	 if ( price > 999999999)
              	      return notify_fail("你摆的价格也太黑了点吧。\n");
	 if ( price < 10000)
              	      return notify_fail("这东西只值这点钱吗？\n");
	   ob1 = present(item,me);
	  if(!ob1)
		    return notify_fail("你身上好像没有这个东西吧？\n");
	  if( ob1->query("money_id") )
		    return notify_fail("你想把钱上架？真是好主意啊，哈哈哈～\n");
	 if(ob1->query_temp("trading") )
		    return notify_fail("这个东西已经上架了。\n");
	 if(ob1->query_temp("no_drop") || ob1->query_temp("no_get"))
		    return notify_fail("这个东西不能上架。\n");
	 if(!ob1->query("value") )
		    return notify_fail("这个东西没有什么价值。\n");
	 if(ob1->query("owner") && !ob1->query("selfmaking") )
		    return notify_fail("这个东西是自造物品，不能上架。\n");



	 message_vision("$N把"+ob1->query("name")+"以"+value_string(price)+"的价格上架了。\n",me);
	 ob1->set_temp("price",price);
	 ob1->set_temp("trading",1);
	ob1->set_temp("no_drop",1);
	ob1->set_temp("no_get",1);

     	   me->set_temp("in_trade",1);

	
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : tradeup <price> <item id>

摆摊后，你可以用此命令把你身上想要卖的东西上架贩卖。

HELP
        );
        return 1;
}
 


