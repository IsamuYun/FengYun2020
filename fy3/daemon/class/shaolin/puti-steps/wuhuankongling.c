// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        extra = me->query_skill("dodge");
        if ( extra < 300) return notify_fail("�����Ծ����֮�����������죡\n");
        
        if(me->query("env/invisibility"))
                return notify_fail("������ʩչ����ÿ����\n");
        if( !me->is_fighting() )
           return notify_fail("ֻ����ս����ʹ�ã�\n");
        if(me->query("force") < 100)
                return notify_fail("�������������\n");
        me->add("force",-100);
  message_vision( HIR "$N"HIR"ʹ��������ղ�����һʽ����ÿ��飢���������񣬲�����գ�\n
  ��Ӱ�����˵���ǰٿ����ʧ����Ȼ���٣�������\n\n" NOR,me,target);
        me->set("env/invisibility",1);
        me->start_busy(3);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra/2);
        return 1;
}
void remove_effect(object me)
{
        me->delete("env/invisibility");
        tell_object(me, "�����ÿ���ʩչ��ϣ�����ͣ��������\n");
}

