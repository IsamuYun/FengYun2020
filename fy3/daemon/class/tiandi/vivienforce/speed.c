// speed.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) return 
	notify_fail("��ֻ�������Լ����ٶȡ�\n");

        if( (int)me->query("force") < 100 )     return 
	notify_fail("�������������\n");
        if( (int)me->query_temp("speedup") ) return 
	notify_fail("���Ѿ����˹����ˡ�\n");
        skill = me->query_skill("vivienforce");
	if(skill < 60) return notify_fail("��������ķ�̫���ˣ�\n");
        me->add("force", -100);
        message_vision(
                HIR 
"$N�����ؾ������������˴���һ��������״̬��\n" NOR, me);
        me->add_temp("apply/agility", skill);
        me->set_temp("speedup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill :), skill/5);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/agility", - amount);
        me->delete_temp("speedup");
        tell_object(me, "��������ķ�������ϣ�����������и��������\n");
}
 
