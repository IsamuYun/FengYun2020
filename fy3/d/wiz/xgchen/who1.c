#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{

	string str;
	str = WHO_D->local_whos(arg);
        me->start_more(str);
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : who [-l|-i|-w]

���ָ������г����������ϵ���Ҽ���ȼ���

-l ѡ���г���վ��ҵ�ѶϢ��
-i ֻ�г���ҵ�Ӣ�Ĵ��š�
-w ֻ�г��������еĹ�����Ա��

���ָ� finger
HELP
    );
    return 1;
}

