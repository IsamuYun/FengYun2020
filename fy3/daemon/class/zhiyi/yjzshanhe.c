#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;
        extra = me->query_skill("dayusword",1);
        if ( extra < 101) return notify_fail("��ģ۴������ݻ��������죡\n");
        extra = me->query_skill("wuwei-force",1);
        if ( extra < 50) return notify_fail("��ģ���Ϊ�ķ��ݻ��������죡\n");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("[ һ����ɽ��]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("[ ������ ]ֻ���ý�ʹ�ã�\n");
        extra = me->query_skill("dayusword",1) / 5;
        extra += me->query_skill("wuwei-force",1) / 5;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIM  "\n$Nǿ����Ϊ�ķ�,���ϵ��ھ�����,��̤�Բ�,ʹ����������\n\n"+BLINK+HIR+"\tһ����ɽ��\n"NOR
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "�ض�ɽҡ��������\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/8;i++)
        {
        msg = HIG "����Ʈ�꣮������\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "��ɽ���أ�������\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/8;i++)
        {
        msg = HIC "ˮ����ɽ��������\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg =  HIW "�˷����ˣ�������\n" NOR;
        message_vision(msg, me, target);
        for(i=0;i<extra/8;i++)
        {
        msg = HIY "����ɽ�ӣ�������\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack", -extra);   
        me->add_temp("apply/damage", -extra);
        me->start_busy(4);
        return 1;
}


