// group.c by tiandi ������Ϣ
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object *ob;
	string file,c_name,arg;
	if (!me->query("group"))
		return notify_fail("�㻹û�м������š�\n");
	c_name = me->query("group");
	file = "/data/group/"+c_name;
	if (file_size(file)<0) 
		return notify_fail("�Ҳ���"+c_name+"���ŵ����ϡ�\n");
	

	

}
 
int help(object me)
{
    write(@HELP

��ָ������鿴���Լ����ڵ����ŵ�һЩ��Ϣ��
�����ǽ��г�ս��ǰ�ᣬֻ�����ŵ��ų��ſ��Է����ս��

HELP
    );
        return 1;
}
