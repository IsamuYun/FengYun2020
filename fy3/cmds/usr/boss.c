// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string msg;
	write(CLR);
	if(arg)
	{
		msg = read_file("/obj/shit.txt");
		write(msg);
	}
	me->set_temp("block_msg/all",1);
	return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: boss <arg>

���ָ������(���)���ϰ����ǰһ����ʱ����Ļ��
���е��������������<arg>������Ļ������ƻ���
�����Ļ����ʾ��һЩ���¡�
���ͬʱ���㽫�ܲ����κ����Է��Ƶ�ѶϢ��ֱ����
����bossgoneָ�

�й�ָ�bossgone
HELP
    );
    return 1;
}
