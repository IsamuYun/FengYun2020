// ������Ϭ  written by tiandi
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

mapping weapon_name = ([
        "sword" : "��",
        "blade" : "��",
        "staff" : "��",
        "whip"  : "��",
	 "axe"   : "��",
	 "dagger": "��",
	 "spear" : "ǹ"
]);

void do_remote_fight(object me, object couple, object target, int n);
void do_here_fight(object me, object couple, object target, int n);

int perform(object me, object target)
{
        int same_place;
        string couple_id;
        string couple_name;
        object couple;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail(HIM"[������Ϭ]"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! stringp(couple_id = me->query("marry")))
                return notify_fail("�㻹û�н�飬��Ϭ��ƨ����\n");

        couple_name = me->query("marryname");

        if (! objectp(couple = find_player(couple_id)))
                return notify_fail(couple_name + "����˯����أ�����Ҳ��������Ϭ��\n");

          if (!couple->query_skill("tianya-blade"))
		    return notify_fail("��İ��º��󲻻��������µ���\n");
	 if (!couple->query_temp("weapon"))
		    return notify_fail("��İ��º���û���ñ�����\n");
	  if  (couple->query_temp("weapon") ->query("skill_type")!="blade")
		      return notify_fail("��İ��º���û���õ���\n");
	if (couple->is_ghost())
                return notify_fail(couple_name + "�����ǹ»�Ұ���޷���Խ��������������\n");

        if (! living(couple))
                return notify_fail("������������޷���" + couple_name + "��ͨ��\n");

        if (target == couple)
                return notify_fail("���в�����\n");

        same_place = (environment(couple) == environment(me));

        if (! same_place)
                do_remote_fight(me, couple, target, (int)couple->query("atman"));
        else
                do_here_fight(me, couple, target, (int)couple->query("atman"));
        return 1;
}

void do_remote_fight(object me, object couple, object target, int n)
{
        object weapon;
        string chinese_type;
        int need, cost;
        int enhance, count;
        string msg;

        if (n > 500) n = 500;
        need = 300 - n / 2;
        cost = 300 - n / 3;

        if (me->query("atman") < need)
        {
                write("����ͼʩչ������Ϭ������һʱ���þ������ã�������ϵ��\n");
                return;
        }

        if (couple->query("atman") < need)
        {
                write("������ԼԼ�ĸо�������µ����������Ƿǳ�΢�������Ѳ�׽����\n");
                return;
        }

	if (me->is_busy())
        {
		write("( ����һ��������û����ɣ�����ʩչ������Ϭ��)\n");
                return;
        }

        if (random(2))
                tell_object(me, HIM "������ĬĬ������" + couple->name(1) +
                            HIM "�����֣������е������������"
                            "�������͸���޾�����գ���������������\n\n" NOR);
        else
                tell_object(me, HIM "��������翵���գ���·𿴵�" + couple->name(1) +
                            HIM "�����������ϵĹ�����޾���������\n\n" NOR);

        if (random(2))
                tell_object(couple, HIM "���ƺ��о���" + me->name(1) +
                            HIM "�������������������֣�����֮"
                            "������������Ϭ����ĬĬ��Ϊ" +
                            gender_pronoun(me->query("gender")) +
                            "ף����ȥ�ɣ��ҵİ��ˣ�\n" NOR);
        else
                tell_object(couple, HIM "ڤڤ��е���" + me->name(1) +
                            HIM "����ĺ�������һɲ�ǣ�������������"
                            "ȫȻ��ͨ��������ε�����ע����Է���������" +
                            gender_pronoun(me->query("gender")) + "��\n" NOR);

        me->add("atman", -cost);
        couple->add("atman", -cost);
        weapon = me->query_temp("weapon");
        if (weapon && (chinese_type = weapon_name[weapon->query("skill_type")]))
        {
                if (me->query("gender") == "Ů��")
                        msg = HIG"$N��" + chinese_type +"������������ݺ���ȣ�Ʈ����������е�" +weapon->name() + HIG "��������ҹ�꣬����$n��\n" NOR;
                else
                        msg = HIC"$N��" + chinese_type + "��������Ȼ��$n�����������" +weapon->name() + HIC "�������磬������" +chinese_type + "Ӱ����$p���ڵ��С�\n" NOR;
        } else
        {
                if (me->query("gender") == "Ů��")
                        msg = HIG"$N����ǳЦ��ƮȻ�����������޾��ף�����������Ṳ̊��쳾������Ͷ��֮��û���κ�������\n" NOR;
                else
                        msg = HIC "$N������Х��һ��ɱ����Ȼ������ص�ʱɫ�䣬$NЮ�������֮�ƣ�ѹ��$n��\n" NOR;
        }
        enhance = (int)couple->query_skill("force")+ n/10;
        count =  random(n / 100);
        if (count > 3)
                count = 3;
        me->add_temp("apply/attack", enhance);
 	 COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
		 
	 msg = MAG+"$N����ԼԼ������$n��ǰ��һ�������ʧ�ˣ��������س�����$n��󣬲���$n��\n\n"NOR;
	message_vision(MAG+"\n"+couple->query("name")+"����ԼԼ������$n��ǰ��һ�������ʧ�ˣ��������س�����$n��󣬲���$n��\n"NOR,me,target);

 	 COMBAT_D->do_attack(couple,target,couple->query_temp("weapon"),TYPE_REGULAR,msg);
	 if ( count >	0)
        {
	 msg = HIW+"$N���и��ǹ���������ңָ$n˫�ȣ�ֻ���ꡢ�������������ǿ���ķ磬����$n˫ϥ�ġ�����Ѩ����\n"NOR;
 	 COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
	 }
	 if ( count >	1)
        {
	 msg = MAG+"$N����Ӱ��ӳ����$n���У�ȴ��$n׽����͸��ֻ��$N˫������һ�ƣ�������$n��\n\n"NOR;
	message_vision(MAG+"\n"+couple->query("name")+"����Ӱӳ����$n��ǰ��ȴ��$n׽����͸��ֻ��"+couple->query("name")+"˫������һ�ƣ�������$n��\n"NOR,me,target);
 	 COMBAT_D->do_attack(couple,target,couple->query_temp("weapon"),TYPE_REGULAR,msg);
	 }
	 if ( count >	2)
        {
	 msg = HIW+"$N�������࣬���ܸж���ֱ��ƺ�����ʽ������"+weapon->name()+HIW"����ͣЪ��һ����ʽ����$n��\n"NOR; 	
	 COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
	 }



	 me->add_temp("apply/attack", -enhance);
        me->start_busy(3);
        return;
}

void do_here_fight(object me, object couple, object target, int n)
{
        int need, cost;
        int enhance1, enhance2, count;
        string msg;

        if (n > 500) n = 500;
        need = 300 - n / 2;
        cost = 300 - n / 3;

	if (me->is_busy())
        {
		write("( ����һ��������û����ɣ�����ʩչ������Ϭ��)\n");
                return;
        }

        if (couple->is_busy())
        {
                write("��İ���������æ���޷���������������Ϭ��\n");
                return;
        }

        if (! couple->is_fighting(target))
                couple->fight_ob(target);

        message_vision(HIY "$N" HIY "��$n" HIY "��������һ����������"
                        "Ȼ��ͨ�����ɵĻ���һЦ��ֻ����������һ����ʱ\n"
                        "�Ѿ���" + target->name() + "�������У�\n" NOR,
                        me, couple);

        enhance1 = (int)couple->query_skill("force",1);
        enhance2 = (int)me->query_skill("force",1);
        count = 2 + random(5 + n / 50);
        if (count > 6)
                count = 6;
        me->add_temp("apply/attack", enhance1);
        couple->add_temp("apply/attack", enhance2);
        while (count--)
        {
                if (me->is_fighting(target) && (count % 2) == 0)
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                else
                if (couple->is_fighting(target))
                        COMBAT_D->do_attack(couple, target, couple->query_temp("weapon"), 0);
                else
                        break;
        }

        me->start_busy(2);
        couple->start_busy(2);
        me->add_temp("apply/attack", -enhance1);
        couple->add_temp("apply/attack", -enhance2);
        return;
}

