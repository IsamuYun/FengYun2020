// yiru@hero
// jingang.c
// �����

#include <ansi.h>

inherit SSERVER;
int conjure(object me, object target)
{
    int lvl,i;
    object env, *inv;
    lvl = (int) me->query_skill("moon-magic",1);
    lvl += (int) me->query("spi");
    if ( lvl < 150)
        return notify_fail("���ˮ���ɷ�����������\n");
    if( me->query("atman") < 30 )
        return notify_fail("�������������\n");
    if(me->query_temp("magic_protect"))
        return notify_fail("������ʩչ�۽����ݣ�\n");
        me->add("atman", -30);
        message_vision(HIY "$N����ˮ���ɷ���ֻ��ȫ��Ӳ���գ������ھ���֮�У�\n" NOR, me);
    me->add_temp("apply/extra_fle", lvl/3);
    me->add_temp("apply/iron-cloth", lvl*3);
    me->add_temp("apply/armor", lvl);
    me->set_temp("magic_protect", 1);
    me->start_call_out( (: call_other, __FILE__, "remove_effect", me, lvl :), lvl);
    if( me->is_fighting() ) me->start_busy(3);
    return 1;
}

void remove_effect(object me, int lvl)
{
    me->add_temp("apply/extra_fle", -lvl/3);
    me->add_temp("apply/iron-cloth", -lvl*3);
    me->add_temp("apply/armor", -lvl);
    me->delete_temp("magic_protect");
    tell_object(me, "��Ľ����ʧЧ�ˡ�\n");
}
