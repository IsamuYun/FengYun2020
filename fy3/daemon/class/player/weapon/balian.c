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
	if(me->query("myskill")<8&&me->query("myskill")>10)
		return notify_fail("�����ڻ�û��ʹ�����еı��£���\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("sword");
        if ( extra < 550) return notify_fail("����Դ��������������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�˽�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
	me->add("force_factor",extra/3);
	orforce = (int) me->query("force");
        me->add("force",extra/3);
	me->add_temp("apply/attack",extra);me->add_temp("apply/damage",extra*2);
       msg = HIR  "\n$Nʹ���Դ������еİ˽����У�һ�������˽���������е�"+ weapon->name()+  "�������$n������\n\n"HIW"һ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC  "������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "�Ľ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�彣��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        msg = HIY  "�߽���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�˽���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(4);
	me->set("force_factor",0);
	me->set("force", orforce);
        me->add_temp("apply/attack",-extra);me->add_temp("apply/damage",-extra*2);
        return 1;
}
