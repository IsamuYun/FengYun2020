#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
             if(me->query("family/family_name") != "������")
                return notify_fail("�㲻�����ֵ��Ӳ���ʹ�÷������У�\n");
                    if((int) me->query_skill("rulai-fofa",1) <= 200)
                return notify_fail("��������𷨻���������������ʹ���������С�\n");
        message_vision( BBLU HIY"$N˫�ֺ�ʮ�����ı�Ŀ��׼����$n�г�--��������--\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(3)+3);
        me->start_busy(5);
        return 1;
}
void kill_him(object me, object target)
{
        string msg;
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
msg =BBLU HIY "$N��$n�г�" + HIR "��������" +HIY "��$nֻ��һƬ���֮��������ȫ��" ;
msg +=  "\n$n�����е���ħ������ɢ�ˣ�������ȫ��!\n" NOR;

        message_vision(msg, me, target);
        me->remove_all_killer();
                target->unconcious();
        }
        return ;
}

