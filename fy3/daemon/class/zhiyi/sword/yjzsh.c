// by xgchen
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int ff;
            object weapon;
         ff = me->query("force");
       extra = me->query_skill("dayusword",1);
         if ( ff < 1500) return notify_fail("�������������\n");
       if ( extra < 101) return notify_fail("��ģ۴������ݻ��������죡\n");
        dodskill = (string) me->query_skill_mapped("force");
        if ( dodskill != "wuwei-force")
                        return notify_fail("�۴���������Ҫ�У���Ϊ�ķ��ݵ���ϣ�\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��һ����ɽ�ӣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
              msg = HIM  "\n$Nǿ����Ϊ�ķ�,���ϵ��ھ�����,��̤�Բ�,ʹ����������"
         +BLINK+HIY+"\n\n\t   <<|| һ  ��  ��  ɽ  �� ||>>"+NOR+"\n
    \n"+HIW+"\t\t�۵ض�ɽҡ��\n$N���н���$n��ȥ��" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
              msg = HIG  "\n\t\t�۰˷������\n$N���н���$n��ȥ��" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIY  "\n\t\t�۾�����ӿ��\n$N���н���$n��ȥ��" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIB  "\n\t\t����ɽ���أ�\n$N���н���$n��ȥ��" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIG  "\n\t\t��ˮ��ɽ����\n$N���н���$n��ȥ��" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIW  "\n\t\t�۽�������\n$N���н���$n��ȥ��" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIC  "\n\t\t�۽��������\n$N���н���$n��ȥ��" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        msg = HIR  "\n\t\t�۽���ɽ�ӣ�\n$N���еĽ��������,����ǿ�ҵ�����Χ��$n��" NOR;
message_vision(msg, me, target); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
        me->start_busy(5);


   target->receive_damage("kee", extra*10);
   target->receive_wound("kee", extra*5);
   me->add("force", -200);
        return 1;
}
