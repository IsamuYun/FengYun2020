// counterattack.c

#include <ansi.h>

inherit SSERVER;
void surekill(object me, object target);
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("[һ��������]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int) me->query_skill("yiqiguanforce",1) < 1000)
                return notify_fail("���[������]���������������ܷ���[һ��������]��\n");

        message_vision(RED"$N����$n���޾���ǵ���$n���ֻ���һ�¡�\n"NOR,me,target);
msg = HIY "$Nʹ��[һ��������]��$nֻ������ǰһ����ȫ�����Զϣ�����" ;
msg +=  "\nһ��Ѫ���ӿ�����ӿ��������$n����ǰ�����������Ͼ��д˵ȹ��򣮣�\n" NOR;

        message_vision(msg, me, target);
                target->die();
        return 1;
}

