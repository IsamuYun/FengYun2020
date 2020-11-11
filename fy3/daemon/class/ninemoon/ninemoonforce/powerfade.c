// powerfade.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) return 
notify_fail("��ֻ���þ����ľ�ѹ���Լ���ɱ����\n");

        if( (int)me->query("force") < 100 )     return 
notify_fail("�������������\n");
        if( me->query_temp("powerup") ) return 
notify_fail("���Ѿ����˹����ˡ�\n");
        if( (int)me->query("bellicosity") <= 0 )
                return notify_fail("�����ں���ɱ����\n");

        skill = me->query_skill("force");

        me->add("bellicosity", - 50 - skill/4 );
        me->add("force", -100);
        me->receive_damage("sen", 100);

        message_vision(
                HIC "$N˫��΢�ϣ�ʩչ�����ľ���������������ʼ�����Լ������� 
....\n" NOR, me);

        if( me->is_fighting()
        &&      (random(skill) < (int)me->query("cps") * 3 ) )
                me->unconcious();

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->add_temp("apply/damage", - amount);
        me->delete_temp("powerup");
        tell_object(me, "��ľ����ķ�������ϣ��������ջص��\n");
}
 
