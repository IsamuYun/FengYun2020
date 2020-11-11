// transfer.c

#include <ansi.h>

inherit SSERVER;

int exert(object me, object target, int amount)
{
        int force, trans;

        if( !target || target==me || !living(target) )
                return notify_fail("��Ҫ����������˭��\n");

        if( (string)me->query_skill_mapped("force") != 
target->query_skill_mapped("force") )
                return notify_fail(target->name() + 
"��ʹ�õ��ڹ����㲻ͬ��\n");

        if( (int)me->query("force") <= (int)me->query("max_force") )
                return notify_fail("����������㡣\n");

        force = me->query("force") - me->query("max_force");

        if( force/2 < 1 ) return notify_fail("����������㡣\n");
        me->add("force", - force / 2 );
        message_vision("$N����������$n���ģ������������������͹�ȥ��\n", me, 
target);
        if( random(force/3) > (int)me->query_skill("force") )
                return notify_fail("��ʧ���ˡ�\n");
	if((int) target->query("force") * 2  < (int) target->query("max_force"))
        target->add("force", force/3);
        write("Ok.\n");
        tell_object(target, HIY "�����һ��������" + me->name() + 
"�����ƴ��˹�����\n" NOR);
        return 1;
}
 
