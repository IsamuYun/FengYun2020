// yiru@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{       object *ob2;
        string msg;
        int extra, str;
        int i,j;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�򽣾�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if(me->query_skill("imperialsword",1) < 160)
        {
                return notify_fail("�����������Ϊ�������޷�ʹ���򽣾���\n");
        }

    weapon = me->query_temp("weapon");
    msg=HIG"\n$N�������������Ǳ������������"+weapon->name()+HIG"���ֶ�����ֱ���մ�ȥ��\n\n"; 
    message_vision(msg, me, target);
    if( random(me->query_skill("sword"))+random(me->query("kar")) < 100)
    { 
        message_vision("���ϵ��˰��죬����û�����ġ�����\n",me,target);
        write(HIY"����������ɽ��������������Ϊ�������ߡ�\n\n"NOR);
        me->start_busy(1);
        return 1;
    }
    msg=HIG"\nȴ�����а׹���˸����������"+ weapon->name() +HIG "������佫������\n"NOR;
    message_vision(msg,me);
    msg=HIW "������ ���Ʊ�ɫ" NOR;
    ob2 = me->query_enemy();
    extra = me->query_skill("pal-sword",1)/5 + me->query_skill("imperialsword",1)/2;
    str = me->query("atman_factor")/2+extra;
    
    j = sizeof(ob2)*(extra/20);
    if (j>36)
    {
        j=36;
    }

    j=j+random(j);

    me->add_temp("apply/attack", extra*3);
    me->add_temp("apply/damage", extra*3);
//      me->add("str",str);
    
    for(i=0;i<j;i++)
    {       
                COMBAT_D->do_attack(me,ob2[random(sizeof(ob2))], weapon, TYPE_REGULAR,msg);
    }
    
//     me->add("str",-str);
    me->add_temp("apply/damage", -extra*3);
        me->add_temp("apply/attack", -extra*3);
    
        msg=HIG "\n$N��һ�ӣ�һ�ɽ�����������ֺϳ�Ϊԭ����" + weapon->name() +HIG"�ɻ�$N���С�\n" NOR;
        message_vision(msg, me, target);
    
    if(j > 30)
    {
        j = 30; 
    }
    if(j < 10)
    {
        j = 10; 
    }
    me->start_busy(j/5);
        return 1;
}

