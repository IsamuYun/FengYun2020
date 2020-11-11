#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object obj;

        if(!arg) 
                return notify_fail("ָ���ʽ : lead <���>\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if(obj==me)
                return notify_fail("��������Լ����Ķ�ȥ��������ˡ�\n");

        tell_object(me, HIY "���" + obj->name() + "˵���������ң��Ҵ���ȥ���õط���\n" NOR);
        tell_object(obj, HIY " " + me->name() + "����˵���������ң��Ҵ���ȥ���ط���\n"
                        + " �����Ը�����" + me->name() + "�������"+ me->name() + "���� follow " + me->query("id") + " ��ָ�\n" NOR);
        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : lead <���>
 
���ָ��������������ĳ����Ҹ����㣬ͬʱҲ���������Ҹ�����
��������ʲô��

�������ָ��: follow
HELP
    );
    return 1;
}
