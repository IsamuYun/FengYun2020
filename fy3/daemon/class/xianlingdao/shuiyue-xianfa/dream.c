// yiru@hero
// dream.c
// �ػ�����

#include <ansi.h>

inherit SSERVER;
int conjure(object me, object target)
{
        int lvl,i;
        object env, *inv;
        lvl = (int) me->query_skill("magic");
        lvl += (int) me->query("spi");
    if ( lvl < 300)
        return notify_fail("���ˮ���ɷ�����������\n");
        if( me->query("atman") < 100 )
                return notify_fail("�������������\n");
    if( me->query("gin") <= 30 )
        return notify_fail("��ľ�������\n");
    if(me->query_temp("in_dreaming"))
        return notify_fail("������ʩչ�ۻػ����Σݣ�\n");
    if( me->is_fighting() )
        return notify_fail("ս���в�����ʩչ�ۻػ����Σݣ�\n");
        me->add("atman", -100);
        me->receive_damage("gin", 30);
        message_vision(HIW "$N������������ʱֻ��һ��������ת������\n" NOR, me);
        me->set_temp("in_dreaming", 1);
    me->remove_all_killer();
    tell_object(me,"��о�����������ƺ����˱仯��\n");
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), lvl);
    return 1;

}

void remove_effect(object me)
{
    me->delete_temp("in_dreaming");
        message_vision(HIW "һ��������ת֮��$N�ֻص��ˡ�����\n" NOR, me);
    me->move(environment(me));
    me->remove_all_killer();
}
