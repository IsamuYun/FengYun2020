//lion@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
    int extra;
    object weapon;
    if(me->is_busy())
    	return notify_fail("������û�գ���\n");

    if( !target ) target = offensive_target(me);
    if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۶������£�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    extra = me->query_skill("bawang-qiang",1);
    if ( extra < 100) return notify_fail("��İ���ǹ�����������죡\n");
    
    extra = extra+me->query_skill("spear");

    me->add_temp("apply/attack", extra*3);
    me->add_temp("apply/damage", extra);

    msg = HIW "\n$N���쳤Х�����ܰ���ֱ������������$w�û���ǧ��ìӰ�����ǡ�����ǹ����\n��ս�޵�֮ʽ��--��-��-��-��--��!!" NOR+HIC "\n\n��\n$N����$wֱָ���գ���Ȼֱ��$n!" NOR;
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);
    
    msg = HIW  "����\n$Nŭ��һ����ǧ��ìӰ���κ��˰�ֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);
    
    msg = HIY  "����Ȼ\n$N��ǹ֮�������м䣬ǹͷǹβ���������������$n��" NOR;
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);

    msg = HIC  "��������\n$N����$w������Ҷ���޴����ڣ�����ǹӰ��һ����ֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);

    msg = HIB  "��˻\n$N����$w�������磬�������죬�·������ڣ�" NOR;
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);

    msg = HIR  "Ѫ��\n$N����$wǹͷ����ٿ�ñ������������Ѫ�⣡" NOR;
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);

    msg = HIC  "��\n����һ��ͻ��������$N����$wǹӰ��ʧ��" NOR;
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"), TYPE_REGULAR,msg);

    me->add_temp("apply/attack", -extra*3);
    me->add_temp("apply/damage", -extra);
	
	me->start_busy(2);
	return 1;
}
