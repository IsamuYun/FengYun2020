// by king
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        if( target != me ) return 
	notify_fail("��ֻ�ܽ���ʱ�չ��������Լ������ϡ�\n");
        if( (int)me->query("force") < 200 )     return
        notify_fail("�������������\n");
        if( (int)me->query_temp("shizhao") ) return 
	notify_fail("���Ѿ���ʩչ��ʱ�չ����ˡ�\n");
	skill = me->query_skill("four-force",1);
        if(skill < 140) return notify_fail("��������񹦻��������\n");
	skill =skill*3;
	me->add("force", -200);
        message_vision( HIC
"$Nʩչ�������񹦡���ʱ�չ����������ȫ�����纮����\n" NOR, me);
        me->add_temp("apply/iron-cloth", skill);
        me->set_temp("shizhao", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill :), skill/5);
        if( me->is_fighting() ) me->start_busy(2);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/iron-cloth", - amount);
        me->delete_temp("shizhao");
        tell_object(me, "��ģ�ʱ�չ��ݵĹ�Чɢ���ˡ�\n");
}
 
