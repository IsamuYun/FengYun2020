// yiru@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string msg, type;
    int extra, str;
    int force, force_factor, flag;
    object weapon;

    if( !target ) target = offensive_target(me);

    if( !target 
      || !target->is_character()
      || !me->is_fighting(target) )
        return notify_fail(HIC"�߾�����"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    weapon = me->query_temp("weapon");
    if (!weapon) 
        type = "unarmed";
    else
        type = weapon->query("skill_type");

    if ( (string) me->query_skill_mapped(type) != "seven-gest")
        return notify_fail("��Ŀǰʹ�õ��⹦�����߾�������\n");

    if ( (string) me->query_skill_mapped("force") != "seven-gest")
        return notify_fail("��Ŀǰʹ�õ��ڹ������߾�������\n");

    force = me->query("force");
    force_factor = me->query("force_factor");
    if( force < 700+force_factor )
        return notify_fail("������������ˣ��޷�ʹ��"HIC"�߾�����"NOR"��\n");

    extra = me->query_skill("seven-gest",1);
    if( extra < 140 )
        return notify_fail("����߾��������������죡\n");

    msg = HIW "\n$Nʹ���ּұ��书�ľ��裬ָ�����һ�����������߾�����һ���ǳɣ�\n" NOR;

    // ��ⲽ��
    flag = me->query_skill("tiannan-step",1);
    if (me->query_skill_mapped("dodge") != "tiannan-step" )
    {
        flag=0;
        }
        
    if( flag > 250)
    {
        msg = HIR "$N��̤�ּұ����е����ϲ�����ͬʱʹ���ּұ��书�ľ��裬\n"
        "ָ�����һ�����������߾�����һ���ǳɣ�\n" NOR;
        target->start_busy( flag/250 );
    }

    message_vision(msg, me, target);
    
    str = extra/3;
    
    if(type == "unarmed")
    {
        me->add("str",str);
    }
    else
    {
        me->add_temp("apply/damage", extra*2);
        me->add_temp("apply/attack", extra*2);
    }

    msg = HIC "��ֱ������\n$N������ָ��������ǹֱ��������$n�����š�" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"����");
    
    msg = HIY "����������\n$N����һ�ӣ�һ������������һ���$n���Ȳ���" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"����");

    msg = HIM "������ָ����\n$N���һ�٣���������������˷�Ϯ����$n�������粻������" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"����");

    msg = HIB "������ն����\n$N˫�ּ��裬˫�־۳�һ���ھ�������������ɽ������ɨ��$n���̡�" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"����");
    
    msg = HIC "������ն����\n$N������ǰһԾ���Բ���˼��ĽǶȻ���$nǰ����" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"����");

    me->add("str",str);

    msg = HIY "������ն����\n$N����ָ�⣬��������, ͻȻ��$n���Ϯ��, �񲻿ɵ�, ����ʤ����" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"����");

    me->add("str",str);
    me->add_temp("apply/attack", extra);
    me->add_temp("apply/damage", extra);

    msg = HIW "����ɨǧ������\n$N��ɽ�������Ե������֮�����ɨ��$n��" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"����");

        me->add("str",-2*str);
        me->add_temp("apply/damage", -extra);
        me->add_temp("apply/attack", -extra);

    if(type == "unarmed")
    {
                me->add("str",-str);
    }
    else
    {
        me->add_temp("apply/damage", -extra*2);
        me->add_temp("apply/attack", -extra*2);
    }

    me->set("force",force-700);

    if( flag > 250 )
    {
        me->start_busy(1);
        }
        else if( flag > 150 )
        {
                me->start_busy(3);
        }
        else
        {
                me->start_busy(5);
        }
        
    return 1;
}

