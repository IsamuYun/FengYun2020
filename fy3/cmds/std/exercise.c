// exercise.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int kee_cost=30, force_gain;

        seteuid(getuid());
        
        if( me->is_fighting() )
                return notify_fail("ս���в������ڹ������߻���ħ��\n");
       if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ��������ڹ���\n");

        if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("��������� enable 
ѡ����Ҫ�õ��ڹ��ķ���\n");

        if( arg 
        &&      !sscanf(arg, "%d", kee_cost) )
                return notify_fail("��Ҫ��������������\n");

        if( kee_cost < 10 ) return notify_fail("������Ҫ�� 10 �㡸��������������\n");

        if( (int)me->query("kee") < kee_cost )
                return 
notify_fail("�����ڵ���̫���ˣ��޷�������Ϣ����ȫ������\n");

        if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
                return notify_fail("�����ھ���״��̫���ˣ��޷�����רһ��\n");

        if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
                return notify_fail("�����ھ����������޷�������Ϣ��������\n");

        write("�������������ù���һ����Ϣ��ʼ������������\n");

        me->receive_damage("kee", kee_cost);
		me->start_busy(1);
        // This function ranged from 1 to 15 when kee_cost = 30
        force_gain = kee_cost * ((int)me->query_skill("force")/10
                + (int)me->query_con() ) / 30;
	force_gain = (force_gain + random(force_gain))/5;

        if( force_gain < 1 ) {
                write("���ǵ����й���ϣ�ֻ����ȫ���顣\n");
                return 1;
        }

        me->add("force", force_gain );

        if ( (int)me->query("force") > (int)me->query("max_force") * 2 ) {
                if ( (int)me->query("max_force") >= 
                //     ((int)me->query_skill("force", 1) + me->query_skill("force")/5) * 5 ) {
		     (int)me->query_skill("force", 1) * 100 ) {
			write("�������Ϣ�鲼ȫ����ʱȴû�й��������ļ����ƺ�������Ϊ�Ѿ�������ƿ����\n");
		} 
		else {
			write("���������ǿ�ˣ�\n");
                        me->add("max_force", 1);
                }
                me->set("force", me->query("max_force"));
        }       
        
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : exercise [<�ķѡ�����������Ԥ��ֵ 30>]

�����������������ڵ����ڸ�����������������ѵ�����弡���������
��������������������������ʽ����������������

��ο� help stats
HELP
        );
        return 1;
}
 
