#include <ansi.h>
inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me) { return 1; }
int practice_skill(object me)
{
        return
notify_fail("������ֻ�ܴ�ѧ�����������ȡ�\n");
}

string exert_function_file(string func)
{
        return CLASS_D("tieflag") + "/jiayiforce/" + func;
}
int effective_level() { return 12;}
int learn_bonus()
{
        return -30;
}
int practice_bonus()
{
        return -10;
}
int black_white_ness()
{
        return 60;
}
void skill_improved(object me)
{
        int s;

        s = me->query_skill("jiayiforce", 1);
        if( !(s%50)
  && (me->query_skill("force",1) < me->query_skill("jiayiforce",1)))
	{
                tell_object(me,
                        HIR "\n�����������񵴣�һ��������������������....\n\n" NOR); 
                me->set_skill("jiayiforce",s/2);
                me->unconcious();
		me->set("gin",me->query("max_gin"));
        }

}
string belong()
{
	return "tieflag";
}
