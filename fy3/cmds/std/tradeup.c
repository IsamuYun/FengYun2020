// by tiandi for trade system
#include <ansi.h>
inherit F_CLEAN_UP;
string value_string(int value)
{
	if( value < 1 ) value = 1;
	else if( value < 100 )
		return chinese_number(value) + "��Ǯ";
	else
		return chinese_number(value/100) + "��"
			+ (value%100? "��" + chinese_number(value%100) + "��Ǯ": "");
}

int main(object me, string arg)
{
	string item;
	object ob1;
	int price;
        if( me->is_fighting() )
                return notify_fail("ս���в����ϼܡ�\n");
    	    if(! environment(me)->query("trade") )
             	   return notify_fail("���ﲻ�����ϼܡ�\n");
    	    if(!me->query_temp("in_trade") )
             	   return notify_fail("����Ȱ�̯�ſ����ϼܰ���\n");
	   if(me->is_ghost())
		   return notify_fail("�����û�а취��̯�ģ�����˱���Ҳ����������\n");
    	    if(me->query("level")< 10 )
             	   return notify_fail("��ĵȼ�̫�͡�\n");
      	   if( me->is_busy() )
             	   return notify_fail("����һ��������û����ɣ������ϼܡ�\n");
     
           if(!arg || sscanf(arg,"%d %s",price,item) != 2)
                        return notify_fail("��������ȷ�ĸ�ʽ��tradeup <price> <item id>��\n");
	 if ( price > 999999999)
              	      return notify_fail("��ڵļ۸�Ҳ̫���˵�ɡ�\n");
	 if ( price < 10000)
              	      return notify_fail("�ⶫ��ֵֻ���Ǯ��\n");
	   ob1 = present(item,me);
	  if(!ob1)
		    return notify_fail("�����Ϻ���û����������ɣ�\n");
	  if( ob1->query("money_id") )
		    return notify_fail("�����Ǯ�ϼܣ����Ǻ����Ⱑ����������\n");
	 if(ob1->query_temp("trading") )
		    return notify_fail("��������Ѿ��ϼ��ˡ�\n");
	 if(ob1->query_temp("no_drop") || ob1->query_temp("no_get"))
		    return notify_fail("������������ϼܡ�\n");
	 if(!ob1->query("value") )
		    return notify_fail("�������û��ʲô��ֵ��\n");
	 if(ob1->query("owner") && !ob1->query("selfmaking") )
		    return notify_fail("���������������Ʒ�������ϼܡ�\n");



	 message_vision("$N��"+ob1->query("name")+"��"+value_string(price)+"�ļ۸��ϼ��ˡ�\n",me);
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
ָ���ʽ : tradeup <price> <item id>

��̯��������ô��������������Ҫ���Ķ����ϼܷ�����

HELP
        );
        return 1;
}
 


