#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)

{
        object ob1,ob2;
        if( !arg || arg=="" )
                return notify_fail("ָ���ʽ: snoopwho <ĳ��>\n");
        ob1 = find_player(arg);

        if (!ob1) return notify_fail("û������ˡ�\n");
        if( arg=="atu" )
                return notify_fail(ob1->query("name") + "����û���ڼ���\n");
        if ( objectp(ob2 = query_snooping(ob1)) )
                        write(ob1->query("name") + "�������ڼ���" + ob2->query("name") + "���յ���ѶϢ��\n") ;
        if (!ob2) return notify_fail(ob1->query("name") + "����û���ڼ���\n");
        return 1;
}
int help()
{
        write(@TEXT
ָ���ʽ snoopwho  <ĳ��>
 
�鿴Ŀ�������Ƿ��ڼ�����
TEXT
        );
        return 1;
}
