// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        if( target != me ) return 
	notify_fail("��ֻ�ܽ��۰�����ƣ������Լ������ϡ�\n");
	if(!me->query_condition("drunk"))
	return notify_fail("�����ں���һ������Ҳû��Ү��\n");
        if( (int)me->query("force") < 100 )     return
        notify_fail("�������������\n");
        if( (int)me->query_temp("zuixian") ) return 
	notify_fail("���Ѿ���ʩչ�۰�����ƣ��ˡ�\n");
	skill = me->query_skill_eff_lvl("zuixian-steps");
	if(skill < 100) return notify_fail("����������²�̫���ˣ�\n");
	 me->add("force", -100);
        message_vision( HIR
"$N��ҡ�Ұڣ�ٲȻ���������²��еģ۰�����ƣݣ���������ҡ�ڲ�����\n" NOR, me);
        me->add_temp("apply/dodge", skill/3);
        me->set_temp("zuixian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/3 :), skill/3);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("zuixian");
        tell_object(me, "��ģ۰�����ƣ�ʩչ��ϣ������ȶ���������\n");
}
 
