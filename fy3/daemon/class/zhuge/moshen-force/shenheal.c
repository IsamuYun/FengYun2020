// ��ħ��

#include <ansi.h>

int exert(object me, object target, int amount)
{
        if( me->is_fighting() )
                return notify_fail("Ŀǰ��ħ�ƻ���֧����ս�������ˣ�\n");

        if( (int)me->query("force") - (int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

        write( HIW "��ȫ����ɣ���������ʼ�˹����ˡ�\n" NOR);
        message("vision",
                HIB + me->name() + 
"�������˹����ˣ�ͷ������һ˿˿���������ƺ�����һ����Ӱ��ת�۾Ͳ����ˡ�\n" 
NOR,
                environment(me), me);

        me->receive_curing("kee", me->query("max_kee"));
        me->set("force", 0);
        me->set("force_factor", 0);

        return 1;
}
 
