
inherit SKILL;

int valid_enable(string usage) 
{ 
    return (usage=="magic")
        || (usage=="force");
}

int valid_learn(object me)
{
    int lvl = me->query_skill("moon-magic", 1);
    if( ((int)me->query_skill("spells", 1) <= lvl)
     	|| ((int)me->query_skill("magic", 1) <= lvl)
     	|| ((int)me->query_skill("force", 1) <= lvl)
    	)
    {
    	return notify_fail("��ķ������������ڹ���Ϊ����������޷�����������ˮ���ɷ���\n");
	}

	if( me->query("family/master_name") != "�����")
		return notify_fail("ֻ��ˮ�¹����ӿ�����ϰˮ���ɷ���\n");

    if(lvl>=120 && me->query("gender")!="Ů��")
        return notify_fail("���������ϣ���������һ���������ڹ��������޷�����������ˮ���ɷ���\n");
    return 1;
}

int effective_level() { return 23;}

string conjure_magic_file(string spell)
{
    return CLASS_D("xianlingdao") + "/moon-magic/" + spell;
}

string exert_function_file(string func)
{
    return CLASS_D("xianlingdao") + "/moon-magic/" + func;
}
 
int learn_bonus()
{
        return -5300;
}

int practice_bonus()
{
        return -5300;
}

int black_white_ness()
{
        return 100;
}
