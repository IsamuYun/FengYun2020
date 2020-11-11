// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int absorb_ghost(object me, object obj)
{

    obj->receive_damage("gin", 1, me);
    if(obj->is_ghost()==1 && (int)obj->query("combat_exp") < 2000000) {
        message_vision(HIY "һ��������$N�Դ�������$N�����ɢ��\n" NOR, obj);
        me->add("atman",-30);
        obj->die();
        return 1;
    }
    if(obj->is_zombie()==1) {
        message_vision(HIB "һ��������$N�Դ�������$N��Ϊ��һ̲Ѫˮ��\n" NOR, obj);
        me->add("atman",-12);
        obj->die();
        return 1;
    }
    return 0;
}

int conjure(object me, object target)
{
    string msg;
    int extra, atman_f;
    int i, j, cost, no_target=0;
    object weapon=me->query_temp("weapon");
    object    *inv;

    if( !target ) target = offensive_target(me);

    if( !target)
        no_target=1;
    else{ 
        if( !target->is_character()
          || !me->is_fighting(target) )
            return notify_fail("������ħֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( target->is_ghost() || target->is_zombie() )
            no_target=1;
    }

	if(me->query_skill("windcloud-move",1) < 100)
	{
		return notify_fail("����ɷ���������Ϊ�������޷�ʹ��������ħ��\n");
	}

	if(me->query_skill("imperialsword",1) < 90)
	{
		return notify_fail("�����������Ϊ�������޷�ʹ��������ħ��\n");
	}

    weapon = me->query_temp("weapon");
    if (!weapon) return notify_fail("������ħֻ�ܺ���������ͣ�\n");
    if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("������ħֻ�ܺ���������ͣ�\n��\n");
    if ( (string) me->query_skill_mapped("sword") != "imperialsword")
        return notify_fail("������ħֻ�ܺ���������ͣ�\n��\n");
    if(me->query_spi()<25)
        return notify_fail("�������̫�ͣ��޷�����������ħ��\n");
    j=(int)me->query_spi();

    atman_f=(int)me->query("atman_factor")/10;

    cost=30-(int)me->query_skill("magic")/10 - j/6;
    if(atman_f>60)
        cost += (120-atman_f);
    else
        cost += atman_f;

    if(cost<5) cost=5;

    if(me->query("atman")<cost)
        return notify_fail("������������ˣ�\n");

    if(no_target)
        msg = HIC  "$Nʹ���������ĸ߼���ʽ��������ħ�ݣ�\n"+
        "���е�"+ weapon->name() +HIC "����ǧ�������ֱ��������\n" NOR;
    else
        msg = HIC  "$Nʹ���������ĸ߼���ʽ��������ħ�ݣ�\n"+
        "���е�"+ weapon->name() +HIC "����ǧ��������ֱ��$n��\n" NOR;

    message_vision(msg, me, target);

    extra = me->query_skill("imperialsword",1) *3;

    // Ҫ����90����Ҳ����˵ 91������ֻ֤�а��˽�ʥ�ſ��Գ�
    if(!me->is_ghost() && (extra > 270)){
        inv = all_inventory(environment(me));
        for(i=0; i<sizeof(inv); i++) {
            if( inv[i]==me) continue;
            if (!objectp(inv[i])) continue;
            if( inv[i]->is_ghost() || inv[i]->is_zombie() )
                absorb_ghost(me, inv[i]);
            if( me->query("atman")<30 ){
                tell_object(me, "������������ˣ�\n");
                me->start_busy(3);
                return 1;
            }
        }
    }
    if(!me->is_ghost() && (extra < 270) && no_target){
        return notify_fail("�������������ߣ����ܶԹ��ʹ��������ħ��\n");
    }

    if (no_target){ me->start_busy(3); return 1; }

    extra = me->query_skill("windcloud-move",1) / 10;

    me->add_temp("apply/attack", extra);    
    extra += me->query_skill("incarnation") /12;
    me->add_temp("apply/damage", extra+atman_f);
    me->add_temp("apply/str", atman_f);

    j=(extra+j*5/12)/5;

    for(i=1;i<=j;i++)
    {
        if(i==1)
            msg =  HIC "һ����������$n��\n" NOR;
        else
            msg =  HIW "��һ����������$n��\n" NOR;

        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add("atman",-cost*i);
        if(me->query("atman")<cost*i || me->query("atman")<3) {
            tell_object(me,"\n������������ˣ�\n");
            me->set("atman_factor",0);
            break;
        }
    }
    me->add_temp("apply/str",-atman_f);
    me->add_temp("apply/damage", -extra-atman_f);
    extra -= me->query_skill("incarnation") /12;
    me->add_temp("apply/attack", -extra);
    if(wizardp(me)) tell_object(me,"����"+chinese_number(j)+"����\n");

    me->start_busy(3);

    return 1;
}

int perform(object me, object target)
{
    // yiru: ������һ��pk bug�����꣬2000.8.24 �޲�
    if(!userp(me))
        return conjure(me, target);
    else
        return 0;
}
