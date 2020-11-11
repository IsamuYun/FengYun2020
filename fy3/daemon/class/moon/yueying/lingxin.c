// ken 1999.12.13

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) return 
notify_fail("��ֻ������Ӱ�񹦵ģ��������������Լ���������\n");

        if( (int)me->query_skill("yueying",1) < 100 )     return 
notify_fail("�����Ӱ�񹦵ȼ�������\n");
        if( (int)me->query("force") < 300 )     return 
notify_fail("�������������\n");
        if(me->query_temp("lingxin") >0 ) return 
notify_fail("���Ѿ����˹����ˡ�\n");

        skill = me->query_skill("force");

        me->add("force", -300);
        message_vision(
                HIR 
"$N΢΢����������Ӱ���еģ��������ݣ�ͷ���ϳ���һ˿�����İ���\n" NOR, me);

        me->add_temp("apply/intelligence", skill/100);
        me->set_temp("lingxin", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/100 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
//        me->delete_temp("apply/intelligence");
//        me->add_temp("apply/attack", - amount);
        me->delete_temp("lingxin");
        tell_object(me, "��ģ���������������ϣ��������ջص��\n");
}
 
