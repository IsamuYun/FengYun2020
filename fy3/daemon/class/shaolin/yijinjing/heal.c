// heal.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n");

        if( (int)me->query("force") - (int)me->query("max_force") < 50 )
                return notify_fail("�������������\n");

        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 5 )
                return 
notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
        if( (int)me->query("eff_kee") >= (int)me->query("max_kee"))
                return notify_fail("��û������,�����˹����ˣ�\n");

        write( HIM "����������������׽�������ڹ���ʼ�˹����ˡ�\n" NOR);
        message("vision",
                HIM + me->name() + 
"�׽�������������������ߣ����ã���������Ѹ�ٵõ���ת��\n"NOR,
                environment(me), me);

        me->receive_curing("kee", 10 + (int)me->query_skill("force")/2 );
        me->add("force", -50);
        me->set("force_factor", 0);

        return 1;
}
 
