// by tiandi for trade system
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
        if( me->is_fighting() )
                return notify_fail("ս���в��ܰ�̯��\n");
    	    if(! environment(me)->query("trade") )
             	   return notify_fail("���ﲻ�����̯��\n");
    	    if(me->query_temp("in_trade") )
             	   return notify_fail("���Ѿ��ڰ�̯�ˡ�\n");
	   if(me->is_ghost())
		   return notify_fail("�����û�а취��̯�ģ�����˱���Ҳ����������\n");
    	    if(me->query("level")< 10 )
             	   return notify_fail("��ĵȼ�̫�͡�\n");
      	   if( me->is_busy() )
             	   return notify_fail("����һ��������û����ɣ����ܰ�̯��\n");
     
	   message_vision("$N���ִ�����ó�һ��С���ӣ������ó�һ�����ӣ��Ҵҵ�д���˼��ʣ���һƨ�������˵����Ͽ�ʼ��̯��\n",me);
	  write ("��������ϼ�(tradeup)���¼�(tradedown)����̯(exit)��\n");
     	   me->set_temp("in_trade",1);

	
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : trade

������������̯�ĵط������������а�̯������

HELP
        );
        return 1;
}
 


