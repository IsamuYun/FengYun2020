// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) return 
notify_fail("��ֻ���þ����ľ������Լ���ս������\n");

        if( (int)me->query("force") < 100 )     return 
notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) return 
notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");

        me->add("bellicosity", 100 + skill/4 );
        me->add("force", -100);
        me->receive_damage("kee", 0);

        message_vision(
                HIR 
"$N�۹۱ǣ��ǹۿڣ��ڹ��ģ�ʩչ�����ľ�������Ϊʵ��ȫ��͸�������ޱȵ�������\n" NOR, me);

        me->add_temp("apply/attack", skill/4);
        me->add_temp("apply/dodge", skill/4);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/4 :), skill);

        if( me->is_fighting() ) me->start_busy(4);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("powerup");
        tell_object(me, "��ľ����ľ�������ϣ��������ջص��\n");
}
 
