// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        extra = me->query_skill("wudu-steps",1);
        if ( extra < 30) return notify_fail("��ģ��嶾�����ݻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������嶾��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
        message_vision("$N�Ųȹ��췽λ����$n��ǰ�ó������Ӱ��\n",me,target);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
        {

        message_vision("���$N���ŵ��ۻ����ң���֪���룡\n",target);
        target->start_busy(3);
        me->start_busy(1);
        }
        else{
        message_vision("��$n��͸��$N����ͼ����Ϊ����������\n",me);
        me->start_busy(2);
        }
        return 1;
}