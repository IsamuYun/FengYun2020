// ken 1999.12.13
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }
int effective_level() { return 10;}

int practice_skill(object me)
{
        return 
notify_fail("��Ӱ�ķ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("moon") + "/yueforce/" + func;
}

 
int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 20;
}

void skill_improved(object me)
{      
        object hb;
        if( (int)me->query_skill("yueforce", 1)  > 220              &&  !me->query("marks/yue") ) {
                tell_object(me,
HIR "\n��ͻȻ��ֻ�����ζ�����ͻȻһ��ɲ�Ǽ�ȫ�������������ͣ���....\n\n" NOR);
		me->delete_skill("yueforce");
                me->set_skill("yueying",30);
                me->add("max_force",300);
                hb=new("/questobj/obj/hongbao2");
                hb->move(me);
		me->set("marks/yue",1);
                me->add("score",500);
                me->unconcious();
        } 
}

