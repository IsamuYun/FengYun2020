// by tiandi for trade system
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string item;
	object ob1;
	int price;
          if( me->is_fighting() )
                return notify_fail("ս���в����¼ܡ�\n");
    	    if(! environment(me)->query("trade") )
             	   return notify_fail("���ﲻ�����¼ܡ�\n");
    	    if(!me->query_temp("in_trade") )
             	   return notify_fail("����Ȱ�̯�ſ����¼ܰ���\n");
	   if(me->is_ghost())
		   return notify_fail("�����û�а취��̯�ģ�����˱���Ҳ����������\n");
    	    if(me->query("combat_exp")< 1000000 )
             	   return notify_fail("��ľ���̫�͡�\n");
      	   if( me->is_busy() )
             	   return notify_fail("����һ��������û����ɣ������¼ܡ�\n");
             if(!arg || sscanf(arg,"%s",item) != 1)
                        return notify_fail("��������ȷ�ĸ�ʽ��tradedown  <item id>��\n");
	   ob1 = present(item,me);
	  if(!ob1)
		    return notify_fail("�����Ϻ���û����������ɣ�\n");
	 if(!ob1->query_temp("trading") )
		    return notify_fail("���������û���ϼܰɡ�\n");


	 message_vision ("$N��"+ob1->query("name")+"�ӻ����ϳ���������\n",me);
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
ָ���ʽ : tradedown <item id>

��̯��������ô���������Ѿ��ϼ�׼����������Ʒ��������

HELP
        );
        return 1;
}
 


