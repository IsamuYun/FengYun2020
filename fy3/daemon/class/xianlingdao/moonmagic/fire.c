// firebolt.c
#include <ansi.h>
inherit SSERVER;
int conjure(object me, object target)
{
string *title=({HIR"������"NOR,HIR"�����"NOR,HIR"�������"NOR,HIR"�� ��"});
string * mssg=({HIR"�����С�������������һ��������$n�������ȥ��\n"NOR,
   HIR"�����С�������������һ������򣬴���������Ũ����$n��ȥ��\n"NOR,
   HIR"����һ���ӱ���쳣���ȣ��������ض���ȼ������ŨŨ�һ�$n��Χ��$nֻ�����Լ�������������֮�С��һ��б�������������$n����ž����ȥ��\n"NOR,
   HIR"���г�����һ�����ͷ���Ĵ���----����\n����˫�������䱧����״����ʱ�γ�һ������Խ��Խ��Խ��Խ�󡣡���������\n����˫��һ�ƣ����������ǵص���$n�ҽ���ȥ��\n"NOR});
        string msg;
        int damage, ap, dp;
        int extradam;
        if( !target ) target = offensive_target(me);
      if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me
        ||      !target->is_fighting(me))
                return notify_fail("��Ҫ��˭ʩչ���ħ����\n");
        ap =(int)me->query_skill("magic")/50;
if (ap>3) ap=3;
        if((int)me->query("atman") < 20*(ap+1) )
        return notify_fail("�������������\n");
        if((int)me->query("sen") < 100 )
        return notify_fail("��ľ���û�а취��Ч���У�\n");
        me->add("atman", -20*(ap+1));
        me->receive_damage("sen", 20);
        msg = HIW "$N������������˫�֣�һ�Ű׹���ָ��һ��������������\n$N������ӣ���$nһָ��ʹ��"+title[ap]+"��\n"NOR;msg+=mssg[ap];
        ap = me->query_skill("magic");
        ap = ap + (int)me->query("sen")/100 ;
        dp = target->query_skill("magic");
        dp = ap + (int)target->query("sen")/100 ;
        damage=ap*2-dp;
        
        if( damage > 0 ) {
                        msg +="�����������һ����׼ȷ������$n���յ�$n��ͷ�ö\n";
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/3, me);
                        me->improve_skill("magic", 1, 1);
                } else
                        msg += "�����������һ��������$n��ߡ�\n";
        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else                            target->kill_ob(me);
                }
                me->kill_ob(target);
        }
        me->start_busy(2);
        return 1;
}
