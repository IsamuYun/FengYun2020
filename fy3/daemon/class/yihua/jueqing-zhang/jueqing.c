//xgchen@fy
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۾�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        extra = me->query_skill("jueqing-zhang",1) ;
        if ((int)me->query_skill("mingyu-shengong", 1) < 150)
                return notify_fail("��������񹦻��̫ǳ��\n");
        if( extra <=20) return notify_fail("���[����ȭ]������������\n");
        if( me->query("class")!="yihua") return notify_fail("���[����ȭ]��ʧȥ�����ˣ�\n");
      if( (int)me->query("force") < 2400 )     return
        notify_fail("�������������\n");
        me->add_temp("apply/attack", extra/5);  
        me->add_temp("apply/damage", extra/5);
        msg = HIW  "\n$N��ʩչ����ľ��� "+HIR"[��������]"+NOR+HIW" ��$n������"+NOR+WHT"\n\n$N˫�ƽ���,һ��"+NOR+HIB"�����项"+NOR+WHT"��������̽�����ƾ�������$n��ͷ��!" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
            if( extra >160) {
            me->add_temp("apply/attack", extra/5);
            me->add_temp("apply/damage", extra/5);
       msg = WHT  "$N���������һ��"+NOR+HIB"�����塹"NOR+WHT"���Ʒ���ϸ�����$n��$lɨȥ��" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
            me->add_temp("apply/attack", -extra/5);
           me->add_temp("apply/damage", -extra/5);
            }
            if( extra >220) {
       me->add_temp("apply/attack", extra*extra/5);
            me->add_temp("apply/damage", extra);
            msg = WHT  "$Nһ��"+NOR+HIB"�����᡹"+NOR+WHT"��˫�ƻû�ΪһƬ��Ӱ����$n�����ڻ�Ӱ֮�ڣ�" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       me->add_temp("apply/attack", -extra*extra/5);
        me->add_temp("apply/damage", -extra);
       }
            if( extra >380) {
       me->add_temp("apply/attack", extra*extra/5);
            me->add_temp("apply/damage", extra*extra);
            msg = WHT  "$N������շ���һ��"NOR+HIB"���޺ۡ�"NOR+WHT"����$n��$l�������ƣ�" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       me->add_temp("apply/attack", -extra*extra/5);
        me->add_temp("apply/damage", -extra*extra);
       }
            if( extra >600) {
       me->add_temp("apply/attack", extra*extra);
            me->add_temp("apply/damage", extra*extra);
        me->add("str",extra);           
 msg = HIW  "$N˫Ŀ�����ֲ������⣬�����Ƶ��������յ�"BLINK+HIB"���������塹"NOR+HIW"����$n��ȫ��ȥ��" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       me->add_temp("apply/attack", -extra*extra);
        me->add_temp("apply/damage", -extra*extra);
           me->add("str",-extra);       
}
       me->add_temp("apply/attack", -extra/5);
        me->add_temp("apply/damage", -extra/5);
        me->start_busy(4);
        return 1;
}int help(object me)
{
        write(RED"\n��������ƣ�"NOR"\n");
        write(@HELP

        ���������¹�������֮ѧ,�����Դ����ɵ��Ʒ���ʹ�ó�����
        ��ʹ�˷·���������һ����ʹ�಻����ɱ�������Ǿ޴󣡶�
             �Ҵ˹������ߣ�����ѧϰ���Ѷȴ�

        Ҫ��  �������ȼ� 160 ����

HELP
        );
        return 1;
}


