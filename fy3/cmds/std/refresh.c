// writen by FY@SH-morrison
#include <ansi.h>

int main(object me)
	{
	  if( !wizardp(me) )
		return notify_fail("��Ҳ���ʹ�ô����������·ֲ�ʹ����:(\n");
	  message("system",HIR "���·ֲ�����ʹ��������"NOR,users()); 
	  TASK_D->init_dynamic_quest(1);
	  message("system",HIG "������ʹ�����·ֲ����\n"NOR,users()); 
	}
        	
 int help(object me)
{
  write(@HELP

refresh �������������²����У���ɺ�û��ɣ���ʹ�����������

HELP
    );
return 1;
}

