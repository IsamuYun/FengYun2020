#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("moon-steps",1);
if ( extra < 60) return notify_fail("��ģ�Բ�²����ݻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
message_vision(HIY"$N��������ʩչ��������ݾ��� , ����˲����Ʈ�첻������\n"NOR,me,target);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
        {
        message_vision("���$N�����ɢ���ۻ����ң��޴ӷֱ棡\n",target);
        target->start_busy(3);
        }
        else{
        msg = "��ϧ$N����Ϊ�����Ȼ������";
        COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);  
        me->start_busy(1);
        }
        return 1;
}

