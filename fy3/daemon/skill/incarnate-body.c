// yiru@hero
// incarnate-body.c
// �ɷ����

#include <ansi.h>
inherit FORCE;

int valid_enable(string usage) 
{ 
        return  (usage=="iron-cloth") || (usage=="force") || (usage=="incarnation");
}

int valid_learn(object me)
{
        object ob;

        if( (int)me->query_skill("incarnation",1) < me->query_skill_eff_lvl("incarnate-body") )
                return notify_fail("���������Ϊ������û�а취���ɷ���ǡ�\n");

        return 1;
}

int practice_skill(object me)
{
    int lvl=me->query_skill("incarnate-body",1);
                if( lvl > 18 )
                  return notify_fail("�ɷ���ǵ�������ز�ֻ�ܴ�ѧϰ����ߡ�\n");

            if( (int)me->query("force") <  lvl)
                  return notify_fail("������������ˡ�\n");
                me->add("force", -lvl);
        return 1;
}
 
int effective_level() { return 28;}

int learn_bonus()
{
        return -810;
}
int practice_bonus()
{
        return -729;
}
int black_white_ness()
{
        return 81;
}
string exert_function_file(string func)
{
        return CLASS_D("xianren") + "/pal-force/" + func;
}
