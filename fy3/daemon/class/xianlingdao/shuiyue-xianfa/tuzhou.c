// yiru@hero
// leizhou
#include <ansi.h>
#include <condition.h>

inherit SSERVER;

int cast(object me, object target)
{
        
        string msg;
        int damage, ap, dp;
        int i,size;
        object *tar;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ���䣿\n");

        if((int)me->query_skill("spells") < 30)
                return notify_fail("�㻹ûѧ�����䡣����\n");

        if((int)me->query("mana") < 25+(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("���޷����о�����\n");

        me->add("mana", -25-(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 50 ) {
                write("��ʧ���ˣ�\n");
                return 1;
        }

        msg = HIG
"$N�������˼������ģ�ֻ��$N�仯��һ����ľ޴���칬��ʿ��˫������һ����ɽ��\n"
"��$n����������ɽ����̩ɽʱ��ȴ��$N����ɽ��$n����ѹ�£�\n" NOR;

        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_mana") / 10 +
random((int)me->query("eff_sen") / 5);

                damage -= (int)target->query("max_mana") / 10 +
random((int)target->query("eff_sen") / 5);
                damage +=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));

    if(me->query_temp("apply/nature_attrib") & NA_TU) damage *= 2; 
    if(target->query_temp("apply/nature_attrib") & NA_TU) damage = 0;
    if(target->query_temp("apply/nature_attrib") & NA_FENG) damage *= 2; 

/*
tar=all_inventory(me);          
 size = sizeof(tar); 
        if(size) {
                for(i=0;i<size;i++)
                if(tar[i]->query("id") == "tuling zhu")  {
                        damage=damage*2  ;  }

        }
*/


//here we can see if 2 players are at same status, the attacker has higher chance.
                if( damage > 0 ) {
//finally damage also depends on enabled spells level.
                damage +=random((damage*(int)me->query_skill("spells"))/100);
                        msg += HIG "̩ɽѹ���ɲ��Ǻ��ܵģ�$n�ѱ�ѹ�������\n" NOR;
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/3, me);
                        target->receive_damage("kee", damage, me);
                        target->receive_wound("kee", damage/4, me);
                        target->start_busy(1);
                        me->improve_skill("shuiyue-xianfa", 1, 1);
                }
            else {
//here, cast failed and the target's mana_factor will be added to the previous 
//damage to hurt yourself:(...note, damage<0.
                        msg += HIG "���̩ɽ��$n�Է������������ɻ�������ѹ��$N���ϣ�\n" NOR;
                damage -= (int)target->query("mana_factor");
                damage -=random((-damage*(int)target->query_skill("spells"))/100);
                        me->receive_damage("sen", -damage, target);
                        me->receive_wound("sen", -damage/3, target);
                        me->receive_damage("kee", -damage, target);
                        me->receive_wound("kee", -damage/4, target);
                        me->start_busy(1);
                        me->improve_skill("shuiyue-xianfa", 1, 1);
            }
             } 
        else
                msg += "���Ǳ�$n�㿪�ˡ�\n";

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);
//damage=0 corresponding to "���Ǳ�$n�㿪�ˡ�\n"--no report.    

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
target->kill_ob(me);
                }
                me->kill_ob(target);
        }

        me->start_busy(1+random(2));
        return 3+random(5);
}
