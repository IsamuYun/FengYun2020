#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("С��ɵ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int) me->query_skill("feidao",1) <= 200)
                return notify_fail("��ķɵ��������������������ܷ���С��ɵ���\n");

        message_vision(RED"$NĿ��ת���ض���$n��׼����������һ����\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(3)+3);
        me->start_busy(5);
        return 1;
}
void kill_him(object me, object target)
{
        string msg;
if(me->query("class")=="traveller" && me->is_fighting() && target->is_fighting() && environment(me) == environment(target))
        {
msg = HIY "$Nʹ���ɵ������������鷢��" + HIR "С��ɵ�" +HIY "��$nֻ������ǰһ�����ʺ��ѱ��Դ�����������" ;
msg +=  "\nһ��Ѫ����ӿ��������$n���۾�������ͻ�˳�������\n" NOR;

        message_vision(msg, me, target);
                target->die();
        }
else{
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
msg = HIY "$Nʹ���ɵ������������鷢��" + HIR "С��ɵ�" +HIY "��$nֻ������ǰһ�����ʺ��ѱ�$w�Դ�����������" ;
msg +=  "\nһ��Ѫ����ӿ��������$n���۾�������ͻ�˳�������\n" NOR;

        message_vision(msg, me, target);
//                target->die()
                target->add("kee",-me->query("kee")/2);
        }
}
        return ;
}

