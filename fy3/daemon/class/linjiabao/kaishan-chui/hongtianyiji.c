// ����Ӣ��
// by lion@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string msg,*limbs;
    int i,size,damage;
    int hisexp,meexp;
    object my_w,target_w;

    if( !target ) target = offensive_target(me);
    if( !target
      ||      !target->is_character()
      ||      !me->is_fighting(target) )
        return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    
    if( me->is_busy())
        return notify_fail("������û�գ�\n");
    
    if( (int)me->query_skill("kaishan-chui",1) < 100)
        return notify_fail("��ġ���ɽ�����ȼ�������\n");
    
    if( (int)me->query("force") < 400 )
        return notify_fail("�������������\n");
    
    me->add("force", -400);
    me->start_busy(2);
    
    my_w = me->query_temp("weapon");
    message_vision(HIC"$NͻȻ����һ����������һ��������������"+my_w->name()+"����һ�����߾�ֱ��$n��ȥ��\n"NOR,me,target);

	hisexp = (int)target->query("combat_exp");
	meexp = (int)me->query("combat_exp");

    // ʧ�ܣ�
    if (random(hisexp+meexp) > 3*meexp)
    {
        message_vision(HIR"���$N����һ�ζ��˹�ȥ��$nһ�����ֲ��ȣ�"
          "���е�"+my_w->name()+"���������Լ����ȡ�\n"NOR,target,me);
        me->receive_damage("kee",50,target);        
        COMBAT_D->do_attack(me,me, me->query_temp("weapon"), TYPE_REGULAR,"");
        return 1;
    }
    
    target_w = target->query_temp("weapon");
    if(!target_w)
        target_w = target->query_temp("secondary_weapon");
    
    if(!target_w || 3*random(hisexp) > random(meexp))
    { 
    	// �Է�����
        damage = me->query_skill("hammer");
        me->add_temp("apply/attack", damage);
        me->add_temp("apply/damage", damage);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,"");
        me->add_temp("apply/attack", -damage);
        me->add_temp("apply/damage", -damage);
        return 1;
    }
    
    // �ұ���
    msg = HIC"ֻ��$n���е�"+target_w->query("name")+"��Ȼ���Ҷ������Σ�"
    		"�����ܵ�$N�ľ����ļ�������$nѸ����ȥ��\n"NOR;
	message_vision(msg,me,target);

    if(target_w->unequip())
        target_w->move(environment(target));
    target_w->set("name", target_w->query("name") + "����Ƭ");
    target_w->set("value", 0);
    target_w->set("weapon_prop", 0);
//    target->reset_action();
    limbs=target->query("limbs");
    size = sizeof(limbs);
    damage = (int)me->query_skill("hammer") + me->query_str() + me->query_temp("apply/damage");
    
    for(i=0;i<1+random(size);i++)
    {
	    msg =HIW"\n���͡�����Ƭ����$N��"+limbs[random(size)]+"��\n"NOR;
	    message_vision(msg,target);
	    target->receive_damage("kee",damage,me);
	    target->receive_wound("kee", damage/3,me);
	    COMBAT_D->report_status(target);
    }
    return 1;
}
