// demostication ѱ����
// yiru@hero

inherit SKILL;
#include <ansi.h>

int valid_enable(string usage)
{
    return (usage=="spells")
        || (usage=="force");
}

int valid_learn(object me)
{
    int lvl = me->query_skill("domestication");
    if( (int)me->query_skill("spells") < 10
     || (int)me->query_skill("force") < 10
     || ((int)me->query_skill("spells")+me->query_skill("force") <= lvl)
    )
    return
        notify_fail("����������ڹ���Ϊ���������޷���ϰ�������ѱ������\n");
    return 1;
}

int effective_level() { return 12;}

string cast_spell_file(string spell)
{
    return CLASS_D("heimiao") + "/domestication/" + spell;
}

string exert_function_file(string func)
{
    return CLASS_D("heimiao") + "/domestication/" + func;
}

int learn_bonus()
{
        return -1200;
}

int practice_bonus()
{
        return -1200;
}

int black_white_ness()
{
        return -30;
}
