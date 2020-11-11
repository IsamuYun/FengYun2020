// yiru@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string msg, type;
    int extra, atman_f;
    int i, cost, force, flag;
    object weapon=me->query_temp("weapon");
    object      *inv;

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
    if( force < 700 )
        return notify_fail("������������ˣ��޷�ʹ��"HIC"�߾�����"NOR"��\n");

    extra = me->query_skill("seven-gest",1)/10;
    if( extra < 21 )
        return notify_fail("����߾��������������죡\n");

    msg = HIC "$Nʹ���ּұ��书�ľ��裬ָ�����һ�����������߾�����һ���ǳɣ�\n"+NOR;

    // ��ⲽ��
    flag = me->query_skill("tiannan-step",1);
    if (me->query_skill_mapped("dodge") != "tiannan-step" )
        flag=0;

    if( flag > 70){
        msg = HIR "$N��̤�ּұ����еĲ�����ͬʱʹ���ּұ��书�ľ��裬\n"
        "ָ�����һ�����������߾�����һ���ǳɣ�\n"+NOR;
        target->start_busy( flag/70 );
    }

    message_vision(msg, me, target);

    me->add_temp("apply/attack", extra*2);      
    msg = HIC "��ֱ������\n$N������ָ��������ǹֱ��������$n�����š�" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"����");
    // �ñ����������˺�
    if(type=="whip"){
        inv = all_inventory(environment(me));
        for(i=0; i<sizeof(inv); i++) {
            if( inv[i]==me || inv[i]==target) continue;
            if( inv[i]->is_character() && !(inv[i]->is_corpse()) ) {
                me->add_temp("apply/damage", extra*10*sizeof(inv));     
                inv[i]->add_temp("is_unconcious",1);
                COMBAT_D->do_attack(me,inv[i], weapon, TYPE_REGULAR,"");
                inv[i]->add_temp("is_unconcious",-1);
                me->add_temp("apply/damage", -extra*10*sizeof(inv)); 
            }
        }
    }
    me->add_temp("apply/attack", -extra);       

    me->add_temp("apply/damage", extra);
    msg = HIC "����������\n$N����һ�ӣ�һ������������һ���$n���Ȳ���" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"����");

    if( flag>280 ){
        target->add_temp("is_unconcious",1);
        target->start_busy(4);
    }
    msg = HIC "������ָ����\n$N���һ�٣���������������˷�Ϯ����$n�������粻������" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"����");
    if( flag>280 )
        target->add_temp("is_unconcious",-1);

    // ����ָ�������˺�
    inv = all_inventory(environment(me));
    for(i=0; i<sizeof(inv); i++) {
        if( inv[i]==me || inv[i]==target) continue;
        if( me->is_fighting(inv[i]) || inv[i]->is_fighting(me) )
            COMBAT_D->do_attack(me,inv[i], weapon, TYPE_REGULAR,"","����");
    }
    me->add_temp("apply/attack", -extra);       
    me->add_temp("apply/damage", -extra);

    me->add_temp("apply/str", extra);
    if( flag>70 )
        me->add_temp("apply/str", extra);
    msg = HIC "������ն����\n$N˫�ּ��裬˫�־۳�һ���ھ�������������ɽ������ɨ��$n���̡�" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"����");
    me->add_temp("apply/str", -extra);

    me->add_temp("apply/damage", extra*7);
    if( flag>210 )
        target->add_temp("is_unconcious",1);
    msg = HIC "������ն����\n$N������ǰһԾ���Բ���˼��ĽǶȻ���$nǰ����" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"����");

    msg = HIC "������ն����\n$N����ָ�⣬��������, ͻȻ��$n���Ϯ��, �񲻿ɵ�, ����ʤ����" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"����");
    // ����ն�������˺�
    inv = all_inventory(environment(me));
    for(i=0; i<sizeof(inv); i++) {
        if( inv[i]==me || inv[i]==target) continue;
        if( me->is_fighting(inv[i]) || inv[i]->is_fighting(me) )
            COMBAT_D->do_attack(me,inv[i], weapon, TYPE_REGULAR,"","����");
    }
    if( flag>210 )
        target->add_temp("is_unconcious",-1);
    me->add_temp("apply/damage", -extra*7);

    if(type == "unarmed")
        me->add_temp("apply/str", extra);
    else
        me->add_temp("apply/damage", extra*extra);

    if( userp(me) )
        me->add_temp("apply/attack", extra*7);

    msg = HIC "����ɨǧ������\n$N��ɽ�������Ե������֮�����ɨ��$n��" NOR;
    COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg,"����");
    // ��ɨǧ���������˺�
    inv = all_inventory(environment(me));
    for(i=0; i<sizeof(inv); i++) {
        if( inv[i]==me || inv[i]==target) continue;
        if( geteuid(inv[i])==geteuid(me) ) continue;
        if( inv[i]->is_character() && !(inv[i]->is_corpse()) )
            COMBAT_D->do_attack(me,inv[i], weapon, TYPE_REGULAR,"","����");
    }

    if( userp(me) )
        me->add_temp("apply/attack", -extra*7);

    if(type == "unarmed")
        me->add_temp("apply/str", -extra);
    else
        me->add_temp("apply/damage", -extra*extra);

    if( flag>70 )
        me->add_temp("apply/str",-extra);
    me->set("force",force-700);

    me->start_busy(4+random(3));

    return 1;
}
