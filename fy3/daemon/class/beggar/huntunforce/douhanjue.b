// powerup.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target, int amount)
{
        int skill;

        if( target != me ) return 
notify_fail("��ֻ�������Լ���������\n");

        if( (int)me->query("force") < 100 )     return 
	notify_fail("�������������\n");
        if( (int)me->query_temp("douhan") ) return 
	notify_fail("���Ѿ����˹����ˡ�\n");
        skill = me->query_skill("jingxing");
	if(skill < 10) return notify_fail("��Ļ��繦̫���ˣ�\n");
        me->add("force", -100);
        message_vision(
                HIR 
"$N��������˼���������������������������ƺ��־����˺࣮ܶ����\n" NOR, me);
        me->add_temp("apply/durability", skill/10);
        me->set_temp("douhan", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/10 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/durability", - amount);
        me->delete_temp("douhan");
        tell_object(me, "��ġ���������������ϣ��������ջص��\n");
}
 
