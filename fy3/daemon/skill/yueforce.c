// ken 1999.12.13
#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }
int effective_level() { return 10;}

int practice_skill(object me)
{
        return 
notify_fail("月影心法只能用学的，或是从运用(exert)中增加熟练度。\n");
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
HIR "\n你突然间只觉得任督二脉突然一震，刹那间全身真气鼓涨难耐！！....\n\n" NOR);
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

