//xgchen@zzfy
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
	int orforce;
        object weapon;
        extra = me->query_skill("tianhuang-sorrow",1);
        if ( extra < 50) return notify_fail("���[��ʹ�]���������죡\n");
                if( !(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("id") != "baiyu-sorrow" )
                return notify_fail("�������װ�������������ʹ��[�ǻ�����]��\n");
if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ǻ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        weapon = me->query_temp("weapon");
        me->add("force_factor",extra/3);
        orforce = (int) me->query("force");
        me->add_temp("apply/attack",extra*extra*50);
me->add_temp("apply/damage",extra*2);
        me->add("force",extra/3);
        msg = MAG  "$N�������⣬����һ�ɣ����е�"HIW"�������"NOR+MAG"����������������$n��$l��\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "$N��"HIW"�������"HIB"������һ�㱼��$n��$l��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "$N��"HIW"�������"HIR"������һ�㱼��$n��$l��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N��"HIW"�������"HIY"������һ�㱼��$n��$l��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "�������"HIM+BLINK"�����̶����ƿ���,ֱ����$n���ؿ��ϣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->start_busy(5);
        me->set("force_factor",0);
        me->set("force", orforce);
        me->add_temp("apply/attack",-extra*extra*50);
me->add_temp("apply/damage",-extra*2);
target->apply_condition("throw_poison",random(10)+10);
target->set("prick",1);
        return 1;
}
