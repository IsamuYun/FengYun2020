// tie@fengyun
#include <ansi.h>
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
		return notify_fail("���Ʋ�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	extra = me->query_skill("dugu-sword",1) ;
        if(extra < 201 ) return notify_fail("��ģ۶��¾Ž��ݲ���������\n");
             if(me->query("family/master_id") != "master kumei")
                return notify_fail("�㲻�ǿ�÷��ʦ�ĵ��Ӳ���ʹ�ã��Ʋ�ʽ�ݣ�\n");
             if((int)me->query_temp("pocan-id")>2)
                return notify_fail("��ľ���ɢ����ʱ����ʹ�ã��Ʋ�ʽ�ݣ�\n");
             if(me->query("family/family_name") != "��ɽ��")
                return notify_fail("�㲻�ǻ�ɽ���Ӳ���ʹ�ã��Ʋ�ʽ�ݣ�\n");
       message_vision(HIW"$N�����򣬶��¾Ž����Ʋ�ʽ���Ծ���֮����$n������ \n"NOR,me,target);      
       msg = HIW "$n��ʧɫ���ľ����������Ѿ�̫���ˣ�\n" NOR;
            	message_vision(msg, me, target);
        me->add_temp("pocan-id",1);
        me->start_busy(8);
target->skill_death_penalty();

	return 1;
}
