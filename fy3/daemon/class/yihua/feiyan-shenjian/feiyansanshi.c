// xgchen@fy 2002
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i;
        object weapon;
        extra = me->query_skill("feiyan-sword",1);
        if ( extra < 200) return notify_fail("��ģ۷�����ʽ�ݻ��������죡\n");
      if (me->query("family/master_name")!="������") 
          return notify_fail("��ģ۷�����ʽ�ݻ��������죡\n");
         if ( me->query("force") < 500) return notify_fail("����������������죡\n");
       if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("[������ʽ]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("[������ʽ]����Ҫ���ſ��Է���������\n");
        if( (string)weapon->query("skill_type") != "sword")
        return notify_fail("[������ʽ]����Ҫ���ſ��Է���������\n");
        if ( (string) me->query_skill_mapped("sword") != "feiyan-sword")
        return notify_fail("[������ʽ]����Ҫ���ſ��Է���������\n");
        me->add_temp("apply/attack", extra*extra);    
        me->add_temp("apply/damage", extra*extra);
       if (target->query("max_kee") >= target->query("kee"))
{               target->add("eff_kee",-target->query("eff_kee")/(random(7)+1));}
       if (me->query("eff_kee")>2000)
{               me->add("eff_kee",-me->query("eff_kee")/8);}
        msg = HIR  "\n$NͻȻ�����е�"+ weapon->name() +HIR"�����ִ�ȥ��������Ѫ���磡\n\n���ֻӽ�������Ѫ��ʹ��������л���$n��\n\n"BLINK+"                 ����ͬ��\n"NOR"\n$n�ܵ��������ص��˺���" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra*extra);    
        me->add_temp("apply/damage", -extra*extra);
        me->start_busy(4);
        return 1;
}

int help(object me)
{
        write(WHT"\n������ʽ��"NOR"\n");
        write(@HELP
        ������ʽ���������촴�ͳ�����ר�ŶԸ��ƻ����ģ���ϧ����û������
        ȴ�Ѿ����ƻ��������ˣ��˽������������������������ޱȣ���ѧ80��
       �Ϳ��Է����������˽�������ȥƽ�����棬�������а������ѧ�ɣ�
       ��Ϊ�������Ѿ��з��ˣ����Ծ���С�����ô�������ˣ�Ҳû��ȥѧ
       �˽���������δ����ѧ�ᡣ
        
        ����Ҫ��      (ѧ�����ܣ�
                          ���ã����� 500 ���ϣ�      
                                 �ȼ� 80 ����;
HELP
        );
        return 1;
}
