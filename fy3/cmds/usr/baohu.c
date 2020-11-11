// user list
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me,string arg)
{
        string id, id2;
        object obj, *pros;
        int i;
        if (!arg)
                return notify_fail("ָ���ʽ : baohu <����>\n");
        if(!stringp(id=me->query("marry")))
                return notify_fail("�����û�н�飡\n");
        if(id != arg)
                return notify_fail(arg+"���󲢲���������ӣ��ɷ�\n");
        if(!objectp(obj=present(id,environment(me))))
                return notify_fail(id+"���󲢲��������Χ��\n");
        id2 = obj->query("marry");
        if( id2 != me->query("id"))
                return notify_fail(arg+"���󲢲���������ӣ��ɷ�\n");
// passed all checks!
        pros = obj->query_temp("protectors");
        for(i=0;i<sizeof(pros);i++)
                if(pros[i] == me) 
                {
                 pros -= ({ me });
                return notify_fail("��ֹͣ����"+arg+"�ˣ�\n");
                }

        if(sizeof(pros))
                pros += ({ me });
        else
                pros = ({ me });
        obj->set_temp("protectors",pros);
        write("�㿪ʼ����"+arg+"\n");
        return 1;
        
}

int help(object me)
{
write(@HELP
ָ���ʽ : baohu <����>

�����ѻ�����������Է������ӣ��ɷ򣩵�ָ��
�����Ϊ������ʱ����������Լ��߳��Ĳ��еļ���������
�Լ���ͬ�飬��Է���ܵ��˵Ĺ�����
HELP
    );
    return 1;
}

