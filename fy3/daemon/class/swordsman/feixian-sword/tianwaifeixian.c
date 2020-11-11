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
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
       if( (int)me->query("force") < 20 )     return
             notify_fail("�������������\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("feixian-sword",1) / 10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$Nʹ�����ɽ����еľ����������ɣݣ����е�"+ weapon->name() +"����һ�����磬�����Ļ���$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "����һ������ʧ��������\n" NOR;
	message_vision(msg, me, target);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
       me->add("force", -20);
	me->start_busy(2);
	return 1;
}

int help(object me)
{
        write(YEL"\n���ɽ���֮������ɣ�"NOR"\n");
	write(@HELP

       ���ɽ������ǰ��Ƴǳ�������Ҷ�³ǵĶ����书�����Ľ���������ʽ��
       ���ޱȣ�����ÿʽ����͸����ѧ�����С����׽�����Ӻ�ݸ��ţ�ʩչ��
       ����������Ů�·����ظ����裬˿����������ƴ���ĸо�����������ȫ
       �ޣ�ÿ�ж��̲��Ų�ͬ�ı仯���ɹ����أ����ʺ��ϲ���������ѧϰ��
       ����ͻ�������������ǣ������磬�����ɷ�����
       Ҫ��	
               (ѧ������ 50 ���ϣ�
                    �ڹ�Ϊ�����ķ���
               ���ã����� 20 ���ϣ�      
                     ���ɽ����ȼ� 1 ����;

HELP
	);
	return 1;
}