// mouse@skills
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        extra = me->query_skill("lingbo-steps",1);
        if ( extra < 80) return notify_fail("��ģ��貨΢���ݻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��Ʈ�����ɣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if(target->is_busy())
                return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
        message_vision( HIG "$Nʩչ�貨΢���еľ�ѧ" + HIR "��Ʈ�����ɣ�"NOR+ HIG "����һת����һб���ó�������Ӱ��\n" NOR,me);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
        {

        message_vision(HIC "\n $Nֻ������ǰһ��������ȫ��$n��Ӱ����\n" NOR,target,me);
        target->start_busy(4);
        }
        else{
        message_vision(HIC "\n  �����û��Ч����\n" NOR,me);
        me->start_busy(1);
        }
        return 1;
}