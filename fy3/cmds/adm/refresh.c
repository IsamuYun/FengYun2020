#include <ansi.h>

int main(object me)
        {
          if( !wizardp(me) )
                return notify_fail("you are not wiz!!\n");  
          TASK_D->init_dynamic_quest(1);
        }
                
 int help(object me)
{
  write(@HELP

refresh �������������²����У���ɺ�û��ɣ���ʹ�����������

HELP
    );
return 1;
}
