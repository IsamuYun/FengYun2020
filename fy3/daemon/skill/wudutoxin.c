inherit SKILL;

int valid_enable(string usage) 
{ 
        return usage=="toxin";

}

int valid_learn(object me)
{
        if( (int)me->query_skill("toxin",1) < (int)me->query_skill("wudutoxin",1))
                return notify_fail("��Ķ�����Ϊ�������޷��������������Ŷ�����\n");
        return 1;
}

string scribe_spell_file(string spell)
{
        seteuid(getuid());
        return CLASS_D("tangmen") + "/liandan/" + spell;
}