// startvote.c
// ��ʼͶƱ�ĳ�����ΪͶƱ�Ľ����Ƚϴ�һ��Ҫ�ߵȼ���ʦ
// ����Ȩ����ʼ������Ҫѡ��������ұȽ϶��ʱ��ſ�ʼ��

#include <ansi.h>
inherit F_CLEAN_UP;
int help();

int main(object me, string arg)
{
	if (arg) return help();
	if (YNVOTE_D->query_temp("voting")) return notify_fail("�����Ѿ���ͶƱ��ѽ��\n"); // ��������ͶƱ
	else {
	write(WHT+MUD_NAME+"����ͶƱϵͳ��������������\n"NOR);
	YNVOTE_D->create(); // ����ϵͳ�ļ��е�create()��������
	write(RED"�����������ɹ���\n"NOR);
	return 1;
	}
}

int help ()
{
        write(@HELP
ָ���ʽ: startvote
 
��ʽ��ʼ����Ǿ�ӭ��ͶƱ���
 
HELP
);
        return 1;
}