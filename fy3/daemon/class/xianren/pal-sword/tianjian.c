// yiru@hero

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, extra2;
        int i, orgforce, orgfact;
        object *obs;
        object weapon;

    /*
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�콣ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    */
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("�콣ֻ�ܺ���������ͣ�\n");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("�콣ֻ�ܺ���������ͣ�\n");
        if ( (string) me->query_skill_mapped("sword") != "imperialsword")
        return notify_fail("�콣ֻ�ܺ���������ͣ�\n");
        if(me->query_spi()<15)
          return notify_fail("�������̫�ͣ��޷������콣��\n");
        if(me->query_skill("imperialsword",1)<30)
          return notify_fail("��������������������޷������콣��\n");

        extra = me->query_skill("imperialsword",1) / 5;
        extra2 = me->query_spi()-15;
        orgforce=me->query("force");
        orgfact=me->query("force_factor");

        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra2*2*2);
        me->add("force_factor",me->query("atman_factor")+extra2);

        msg = HIY "\n$N�Ľ���һ����$n"HIY"һ����һ���޴��"HIW"�콣"HIY"ֱ�������" NOR;
    obs = me->query_enemy();
    if(!sizeof(obs)) msg += "\n";
    message_vision(msg,me,weapon);
    for(i=0;i<sizeof(obs);i++)
        {       
        if(!obs[i]) continue;
        me->add("force",orgfact+extra2+me->query("atman_factor"));
COMBAT_D->do_attack(me,obs[i], weapon, TYPE_REGULAR,HIC"�콣����,��������"NOR);
        }
        me->start_busy(sizeof(obs)/2+2);
        
        me->set("force_factor",orgfact);
        me->add_temp("apply/damage", -extra2*2*2);
        me->add_temp("apply/attack", -extra);
        return 1;
}
