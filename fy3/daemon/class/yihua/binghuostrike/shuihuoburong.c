// xgchen@zzfy
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        int lvl;
        string msg,msg1,msg2,msg3;
        int extra;
        object weapon;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ˮ���ݣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        lvl = (int)me->query_skill("binghuostrike",1) / 20;
        if(lvl<1) {             return notify_fail("��ĺ����һ��ƻ��������!��\n");
                }      
        extra = me->query_skill("binghuostrike",1) ;
        extra=extra*lvl;
        if( (int)me->query("force") < 10*lvl )     return 
        notify_fail("�������������\n"); 
        me->add_temp("apply/attack", extra/10);    
        me->add_temp("apply/damage", extra);
        msg1 = HIY  "$N˫������,�ϻ����֮����,����һ��:ʹ�������һ��Ƶľ�ѧ\n\n" NOR;       
msg2 = HIR"      !!!ˮ*��*��*��!!!\n\n" NOR;
msg3 = HIM"      !!!!!!��    "+chinese_number(lvl)+"    ��!!!!!!\n" NOR;
        msg=msg1+msg2+msg3;
        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
        me->add_temp("apply/attack", -extra/10);   
        me->add_temp("apply/damage", -extra);
        me->start_busy(3);
        return 1;
}
int help(object me)
{
        write(RED"\n�����һ��ƣ�"NOR"\n");
        write(@HELP

        �����һ���,С�������ؼ�ˮ��֮�������Դ����ɵ��Ʒ���ʹ�ó�����
        ��ʹ�˷·�����ˮ�����֮�У�ʹ�಻����ɱ�������Ǿ޴󣡶��Ҵ��书
        ��Ϊ�ö�׶Σ�ÿ����һ�أ���ʹ��������ߺܶ࣬����ѧϰ���Ѷ�Ҳ��Ҳ
        ��Խ��Խ��

        Ҫ��  �����һ��Ƶȼ� 20 ����
                �������� 10*�����һ��Ƶȼ�/20

HELP
        );
        return 1;
}

