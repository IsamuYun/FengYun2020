// Cmds:/cmds/usr/ynvote.c
// ����ͶƱָ������˻��Լ�Ͷ��һƱ��

inherit F_CLEAN_UP;
#include <ansi.h>

int help();

int main(object me, string arg)
{
	object ob;
	if ( !arg || arg=="" ) return help();
/*����Ҫע�⣬����ϸ��������������û�������ҿ���ͶƱ���Լ���һ�㣬�������
   MUD�˶�Ļ���������Ͷ���Լ��ɣ��������٣����׳���Ʊ����ͬ�ģ��ǾͲ�����
   Ͷ���Լ��ɣ�����������һ��Ϳ����ˡ�����Ҫ˵��һ�£��������Ʊ����ͬ������
   ��˭������˵���������ɣ�
	if (arg==me->query("id")) return notify_fail("ǫ��һ��ò��ã�\n");*/
	if (me->query("have_voted")) return notify_fail("�Բ������Ѿ�Ͷ��Ʊ�ˡ�\n");
	if (wizardp(me)) return notify_fail("��ʦ�ͱ�����������˰ɡ�\n");
	if (!YNVOTE_D->query_temp("voting")) return notify_fail("���ڲ�����ͶƱѽ��\n");
	if (!ob=find_player(arg)) return notify_fail("û�������ҡ�\n");
	else {
	write("Ok�����Ѿ�Ϊ"+ob->name()+"�ɹ���Ͷ����һƱ��\n");
	message("system",RED"�����꾫�顿"WHT+me->name()+"("+me->query("id")+")���Լ���һƱͶ����"+ob->name()+"("+ob->query("id")+")��\n"NOR,users());
	ob->add_temp("voted",1);
	me->set("have_voted",1);
	return 1;
	}
}

int help()
{
	write(@TEXT
ָ���ʽ��ynvote <���id>

���ָ������������ͶƱ��и����ͶƱ��
ÿ��ֻ��ͶһƱ��

TEXT
	);
	return 1;
}
