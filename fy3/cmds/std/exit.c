// by tiandi for trade system
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
       object *inv; 
	 int i;
	 if(! me->query_temp("in_trade") )
                return notify_fail("����û�а�̯����ʲô̯����\n");
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

     	   message_vision("$N��С������վ��������������̯λ��\n",me);
     	   me->delete_temp("in_trade");


        return 1;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : exit

����������ڰ�̯��ʱ����������������̯��

HELP
        );
        return 1;
}
 


