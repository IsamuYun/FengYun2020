// heal.c  written by tiandi

#include <ansi.h>

int exert(object me, object target, int amount)
{
        if( me->is_fighting() )
                return notify_fail("ս�����˹����ˣ�������\n");

        if( (int)me->query("force") - (int)me->query("max_force") < 50 )
                return notify_fail("�������������\n");
       
        write( HIY "���̵ؾ��������˵��;��ȫ�����ҪѨ������һС���죬��󻺻������뵤�\n" NOR);
        message("vision",
                HIY + me->name() + 
"�̵ؾ��������˵��;��ȫ�����ҪѨ������һС���죬��󻺻������뵤�\n"
+RED+"����"+ me->name() + "�³�һ��"+HIR+"��Ѫ����ɫ�������ö��ˡ�\n" 
NOR,
                environment(me), me);

        me->receive_curing("kee", 10 + (int)me->query_skill("force")/2 );
        me->add("force", -50);
        me->set("force_factor", 0);

        return 1;
}
 
