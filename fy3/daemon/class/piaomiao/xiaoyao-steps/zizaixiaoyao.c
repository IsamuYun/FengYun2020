#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("xiaoyao-steps",1);
        if ( extra < 90) return notify_fail("��ģ���ң�Σݻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ң��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
        message_vision("$N����΢�����û����˸���Ӱ��Ʈ�첻����\n",me,target);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
        {

        message_vision("���$N���ŵ��ۻ����ң���Ӧ��Ͼ��\n",target);
        target->start_busy(4);
        }
        else{
        msg = "��ϧ$N������$n����������ѸȻ������";
        COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);  
        }
        return 1;
}