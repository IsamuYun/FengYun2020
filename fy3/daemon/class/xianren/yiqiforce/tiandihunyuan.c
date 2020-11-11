#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        if( target != me ) return 
        notify_fail("��ֻ�ܽ�����ػ�Ԫ�������Լ������ϡ�\n");
        if( (int)me->query("force") < 500 )     return
        notify_fail("�������������\n");
        if( (int)me->query_temp("hunyuan") ) return 
        notify_fail("���Ѿ���ʩչ����ػ�Ԫ���ˡ�\n");
        skill = me->query_skill("yiqiforce",1);
        if(skill < 100) return notify_fail("��Ļ�Ԫһ����̫���ˣ�\n");
        skill = random(skill/2)+skill/2;
        me->add("force", -100);
        message_vision( HIY
"$N��Ŀ�����Ԫһ����,�������屻������Χ��....................\n
$NͻȻ���һ��...��ػ�Ԫ���������.................\n" NOR, me);
        me->add_temp("apply/iron-cloth", skill);
        me->set_temp("hunyuan", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill :), skill/5);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/iron-cloth", - amount);
        me->delete_temp("hunyuan");
        tell_object(me, "��ģ���ػ�Ԫ�ݵĹ�Чɢ���ˡ�\n");
}
int help(object me)
{
        write(YEL"\n��Ԫһ������"NOR"\n");
	write(@HELP

        ��Ԫһ�������ഫ�ɶ�����۴��ͳ�������һ�����ص���ѧ����Ԫһ����
	�����ޱȣ���������ǿ�����Ӳ���书������������ѧ�˹�������֮���١�
        ������˾�������һ�����������ʹ˹���Ҫ�ޱȵ����ĺ;��˵���������
        ��ѧ�˹����ˡ������Ǹ������ˡ�
	
	Ҫ��	(ѧ���������ȼ� 331 ���ϣ�
               ���ã����� 500 ���ϣ�      
                     ��Ԫһ�����ȼ� 100 ����;

HELP
	);
	return 1;
}
