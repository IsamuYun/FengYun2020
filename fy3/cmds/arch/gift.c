// ������Ķ���
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object *users, present;
    int i;

    if( !arg || arg=="" )
        return notify_fail("ָ���ʽ��gift <��Ʒ�ļ���>\n");

    if( !(present = load_object(arg)) )
        return notify_fail("����ָ�������ﲻ���ڻ����Ʒ�������������롣\n");

    seteuid(getuid());
    users = users();
    i = sizeof(users);
    while(i--) {
        present=new(arg);
        present->move(users[i]);
        tell_object(users[i],HIR "��ʦ�������ԩ�࣬����������Ʒ\n\n" +
          HIW "���ϴ���һ�󶣶�����������\n\n" +
          HIY "ͻȻ���������һ�¶���һ��ʲô������\n\n" NOR);
    }
    write("���﷢����ϡ�\n");
    return 1;
}

int help(object me)
{
    write(@HELP
ָ���ʽ : gift <������ļ�����>

�ô� : �������ﵽ���е��������

HELP
    );
    return 1;
}
